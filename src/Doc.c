/* This is a managed file. Do not delete this comment. */

#include <driver/ext/md/md.h>
int16_t md_Doc_construct(
    md_Doc this)
{

    if (!corto_check_attr(this, CORTO_ATTR_NAMED)) {
        corto_throw("md/doc objects must be scoped");
        goto error;
    }

    this->index = corto_scope_size(corto_parentof(this));

    return 0;
error:
    return -1;
}
