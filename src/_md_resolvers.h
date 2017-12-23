#ifndef _MD_RESOLVERS_H
#define _MD_RESOLVERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "driver/ext/md/md.h"
#include "callbacks.h"

corto_object md_resolve(int level, corto_string name, corto_object *parent, md_parseData* data);

#ifdef __cplusplus
}
#endif

#endif /* _MD_RESOLVERS_H */
