#ifndef COLLECTION_H
#define COLLECTION_H

#include <stddef.h>

typedef struct collection_type collection;

extern int create_collection(collection **result);

extern void destroy_collection(collection *col);

extern int add_to_collection(collection *col, const void *data, size_t byteCount);

extern int remove_from_collection(collection *col, const void *data, size_t byteCount);

extern int find_in_collection(const collection *col, const void *data, size_t byteCount);

#endif
