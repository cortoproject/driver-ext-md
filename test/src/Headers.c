/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Headers_tc_H1(
    test_Headers this)
{
    char text[] =
        "# FirstHeading\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "FirstHeading"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
}

void test_Headers_tc_H1H2(
    test_Headers this)
{
    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "FirstHeading"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "SecondHeading"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
}

void test_Headers_tc_H1H2H1(
    test_Headers this)
{

    char text[] =
        "# Heading1\n"
        "## Heading2\n"
        "# Heading3\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading1"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1/Heading2");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading2"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading3");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading3"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
}

void test_Headers_tc_H1H2H1H2(
    test_Headers this)
{

    char text[] =
        "# Heading1\n"
        "## Heading2\n"
        "# Heading3\n"
        "## Heading4\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading1"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1/Heading2");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading2"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading3");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading3"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading3/Heading4");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading4"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }

}

void test_Headers_tc_H1H2H3(
    test_Headers this)
{
    char text[] =
        "# FirstHeading\n"
        "## SecondHeading\n"
        "### ThirdHeading\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "FirstHeading"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "SecondHeading"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "FirstHeading/SecondHeading/ThirdHeading");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "ThirdHeading"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }
}

void test_Headers_tc_H1H2H3H1H2(
    test_Headers this)
{

    char text[] =
        "# Heading1\n"
        "## Heading2\n"
        "### Heading3\n"
        "# Heading4\n"
        "## Heading5\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading1"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1/Heading2");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading2"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1/Heading2/Heading3");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading3"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading4");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading4"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading4/Heading5");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading5"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }
}

void test_Headers_tc_H1H3(
    test_Headers this)
{

    char text[] =
        "# Heading1\n"
        "### Heading2\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading1"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1/Heading2");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading2"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }

}

void test_Headers_tc_H1H3H1H3(
    test_Headers this)
{

    char text[] =
        "# Heading1\n"
        "### Heading2\n"
        "# Heading3\n"
        "### Heading4\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading1"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1/Heading2");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading2"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading3");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading3"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading3/Heading4");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading4"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }

}

void test_Headers_tc_H1H3H2(
    test_Headers this)
{

    char text[] =
        "# Heading1\n"
        "### Heading2\n"
        "## Heading3\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading1"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 1);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1/Heading2");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading2"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 3);
        corto_release(o);
    }
    {
        corto_object o = corto_resolve(test_docs_o, "Heading1/Heading3");
        test_assert(o != NULL);
        test_assert(corto_instanceof(md_Doc_o, o));
        test_assert(md_Doc(o)->o == NULL);
        test_assert(!strcmp(md_Doc(o)->niceName, "Heading3"));
        test_assert(md_Doc(o)->text == NULL);
        test_assert(md_Doc(o)->level == 2);
        corto_release(o);
    }

}

void test_Headers_tc_H2(
    test_Headers this)
{

    char text[] =
        "## FirstHeading\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        test_assert(corto_catch() != 0);
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o == NULL);
    }

}

void test_Headers_tc_H3(
    test_Headers this)
{

    char text[] =
        "### FirstHeading\n"
        ;
    md_parseToCorto(test_docs_o, text);
    {
        test_assert(corto_catch() != 0);
        corto_object o = corto_resolve(test_docs_o, "FirstHeading");
        test_assert(o == NULL);
    }

}
