/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_HeaderParagraphs_tc_H1DP(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is a description.\n\n"
        "This is the first paragraph.\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description,
            "This is a description.\n"));
        test_assert(!strcmp(md_Doc(o)->text,
            "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1DPP(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is a description.\n\n"
        "This is the first paragraph.\n\n"
        "This is the second paragraph.\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description,
            "This is a description.\n"));
        test_assert(!strcmp(md_Doc(o)->text,
            "This is the first paragraph.\n\n"
            "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1H2H3H4P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        "### ThirdHeading\n"
        "#### FourthHeading\n"
        "This is the first paragraph.\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading/ThirdHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading/ThirdHeading/FourthHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 4);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1H2H3P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        "### ThirdHeading\n"
        "This is the first paragraph.\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading/ThirdHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1H4P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "#### SecondHeading\n"
        "This is the first paragraph.\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 4);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1P(
    test_HeaderParagraphs this)
{
    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
}

void test_HeaderParagraphs_tc_H1PH1P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "# SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1PH2P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "## SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1PH2PH3P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "## SecondHeading\n"
        "This is the second paragraph.\n"
        "### ThirdHeading\n"
        "This is the third paragraph.\n";
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading/ThirdHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the third paragraph.\n"));
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1PH3P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n"
        "### SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1PnH1P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n\n"
        "# SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1PnH2P(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n\n"
        "## SecondHeading\n"
        "This is the second paragraph.\n";
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description, "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1PP(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n\n"
        "This is the second paragraph.\n";
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text != NULL);
        test_assert(!strcmp(md_Doc(o)->description,
            "This is the first paragraph.\n"));
        test_assert(!strcmp(md_Doc(o)->text,
            "This is the second paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_H1PPP(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        "This is the first paragraph.\n\n"
        "This is the second paragraph.\n\n"
        "This is the third paragraph.\n";
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(md_Doc(o)->text != NULL);
        test_assert(!strcmp(md_Doc(o)->description,
            "This is the first paragraph.\n"));
        test_assert(!strcmp(md_Doc(o)->text,
            "This is the second paragraph.\n\n"
            "This is the third paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }

}

void test_HeaderParagraphs_tc_whitespace(
    test_HeaderParagraphs this)
{

    char text[] =
        "# FirstHeading\n"
        " \n\n"
        "This is the first paragraph.\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_parentof(o) == test_docs_o);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(md_Doc(o)->description != NULL);
        test_assert(!strcmp(md_Doc(o)->description,
            "This is the first paragraph.\n"));
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }

}
