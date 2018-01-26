#include "driver/ext/md/md.h"
#include "callbacks.h"
#include "_md_resolvers.h"

#define MAX_OBJECT_HEADER (6)

static void md_appendBuffer(
    const hoedown_buffer *content,
    const hoedown_buffer *lang_content,
    const hoedown_renderer_data *data,
    int code)
{
    md_Doc lastHeader = NULL;
    corto_uint32 i = 0;
    md_parseData* _data = data->opaque;
    corto_string str = NULL, buff = NULL, lang = NULL;

    for (i = 1; i <= MAX_OBJECT_HEADER; i++) {
        if (_data->headers[i]) {
            lastHeader = _data->headers[i];
        }
    }

    buff = corto_calloc(content->size + 1);
    memcpy(buff, content->data, content->size);

    if (lang_content) {
        lang = corto_calloc(lang_content->size + 1);
        memcpy(lang, lang_content->data, lang_content->size);
    } else {
        lang = strdup("");
    }

    if (lastHeader) {
        if (code || lastHeader->description ||
            lastHeader->text ||
            strchr(buff, '`') ||
            strstr(buff, "!["))
        {
            if (code) {
                if (lastHeader->text) {
                    str = corto_asprintf("%s\n```%s\n%s```\n", lastHeader->text, lang, buff);
                } else {
                    str = corto_asprintf("```%s\n%s```\n", lang, buff);
                }
            } else {
                if (lastHeader->text) {
                    str = corto_asprintf("%s\n%s\n", lastHeader->text, buff);
                } else {
                    str = corto_asprintf("%s\n", buff);
                }
            }
            corto_set_str(&lastHeader->text, str);
        } else {
            str = corto_asprintf("%s\n", buff);
            corto_set_str(&lastHeader->description, str);
        }
    }

    if (str) corto_dealloc(str);
    corto_dealloc(buff);
    corto_dealloc(lang);
}

void md_callbackBlockcode(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *lang, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(lang);
    CORTO_UNUSED(data);

    if (text) {
      md_appendBuffer(text, lang, data, 1);
    }
}

void md_callbackBlockquote(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
}

void md_callbackHeader(hoedown_buffer *ob, const hoedown_buffer *content, int level, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    corto_id name;
    md_parseData* _data = data->opaque;

    corto_object o;
    strncpy(name, (char*)content->data, content->size)[content->size] = '\0';

    md_Doc doc = NULL;
    corto_object previous = root_o;

    if (level <= MAX_OBJECT_HEADER) {
        /* `o` can be null when not documenting an object store */
        o = md_resolve(level, name, &previous, _data);

        /* Test if root of documents is a H1 header */
        if (!corto_instanceof(md_Doc_o, previous) && (level > 1)) {
            corto_throw(
              "H1 header missing (a level %d header as root is illegal)",
              level);
            goto error;
        }

        char *ptr = name, ch, *bptr;
        corto_id id;
        bptr = id;

        for (; (ch = *ptr); ptr++, bptr++) {
            if (ch == ':') {
                *bptr = '_';
                ptr++;
            } else if (ch == '/') {
                *bptr = '_';
            } else if (ch == ' ') {
                *bptr = '_';
            } else {
                *bptr = ch;
            }
        }
        *bptr = '\0';

        doc = md_Doc__create(previous, id, o, level, name);

        _data->headers[level] = doc;
    } else {
        /* TODO just append like text */
    }
error:
    return;
}

void md_callbackHrule(hoedown_buffer *ob, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(data);
}

void md_callbackList(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_list_flags flags, const hoedown_renderer_data *data) {
    md_appendBuffer(content, NULL, data, 0);
}

void md_callbackListitem(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_list_flags flags, const hoedown_renderer_data *data) {
    hoedown_buffer_puts(ob, " - ");
    hoedown_buffer_put(ob, content->data, content->size);
}

void md_callbackParagraph(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    md_appendBuffer(content, NULL, data, 0);
}

void md_callbackTable(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    md_appendBuffer(content, NULL, data, 0);
}

void md_callbackTable_header(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    md_parseData* _data = data->opaque;
    hoedown_buffer_put(ob, content->data, content->size);
    int i; for (i = 0; i < _data->cellCount - 1; i++) {
        hoedown_buffer_puts(ob, "---|");
    }
    hoedown_buffer_puts(ob, "---\n");
}

void md_callbackTable_body(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    hoedown_buffer_put(ob, content->data, content->size);
}

void md_callbackTable_row(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    md_parseData* _data = data->opaque;
    hoedown_buffer_put(ob, content->data, content->size);
    hoedown_buffer_puts(ob, "\n");
    _data->rowCellCount = 0;
}

void md_callbackTable_cell(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_table_flags flags, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(flags);
    md_parseData* _data = data->opaque;
    if (_data->rowCellCount) {
        hoedown_buffer_puts(ob, " | ");
    }
    hoedown_buffer_put(ob, content->data, content->size);
    if (_data->rowCellCount == _data->cellCount) {
        _data->cellCount ++;
    }
    _data->rowCellCount ++;
}

void md_callbackFootnotes(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("Footnotes =>\n  ");
}

void md_callbackFootnote_def(hoedown_buffer *ob, const hoedown_buffer *content, unsigned int num, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(num);
    CORTO_UNUSED(data);
    printf("Footnote_def =>\n  ");
}

void md_callbackBlockhtml(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
    printf("Blockhtml =>\n  ");
}

int md_callbackAutolink(hoedown_buffer *ob, const hoedown_buffer *link, hoedown_autolink_type type, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(link);
    CORTO_UNUSED(type);
    CORTO_UNUSED(data);
    printf("Autolink =>\n  ");
    return 0;
}

int md_callbackCodespan(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
    printf("Codespan =>\n  ");
    return 0;
}

int md_callbackDouble_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("Double_emphasis =>\n  ");
    return 0;
}

int md_callbackEmphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("Emphasis =>\n  ");
    return 0;
}

int md_callbackUnderline(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("Underline =>\n  ");
    return 0;
}

int md_callbackHighlight(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("Highlight =>\n  ");
    return 0;
}

int md_callbackQuote(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("Quote =>\n  ");
    return 0;
}

int md_callbackImage(hoedown_buffer *ob, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *alt, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(link);
    CORTO_UNUSED(title);
    CORTO_UNUSED(alt);
    CORTO_UNUSED(data);
    printf("Image =>\n  ");
    return 0;
}

int md_callbackLinebreak(hoedown_buffer *ob, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(data);
    printf("Linebreak =>\n  ");
    return 0;
}

int md_callbackLink(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(link);
    CORTO_UNUSED(title);
    CORTO_UNUSED(data);
    printf("Link =>\n  ");
    return 0;
}

int md_callbackTriple_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("emphasis =>\n  ");
    return 0;
}

int md_callbackStrikethrough(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("Strikethrough =>\n  ");
    return 0;
}

int md_callbackSuperscript(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(content);
    CORTO_UNUSED(data);
    printf("Superscript =>\n  ");
    return 0;
}

int md_callbackFootnote_ref(hoedown_buffer *ob, unsigned int num, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(num);
    CORTO_UNUSED(data);
    printf("ref =>\n  ");
    return 0;
}

int md_callbackMath(hoedown_buffer *ob, const hoedown_buffer *text, int displaymode, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(displaymode);
    CORTO_UNUSED(data);
    printf("Math =>\n  ");
    return 0;
}

int md_callbackRaw_html(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
    printf("RAW HTML =>\n  ");
    return 0;
}

void md_callbackEntity(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
    printf("Entity =>\n  ");
}

void md_callbackNormal_text(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(text);
    CORTO_UNUSED(data);
    char *buff = corto_calloc(text->size + 1);
    memcpy(buff, text->data, text->size);
    buff[text->size] = '\0';
    printf("Normal_text =>\n %s\n", buff);
}

void md_callbackDoc_header(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(inline_render);
    CORTO_UNUSED(data);
    printf("header =>\n  ");
}

void md_callbackDoc_footer(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data) {
    CORTO_UNUSED(ob);
    CORTO_UNUSED(inline_render);
    CORTO_UNUSED(data);
    printf("footer =>\n  ");
}
