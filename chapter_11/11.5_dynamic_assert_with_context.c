#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10123L
void *dup_string(size_t size, char *str)
{
    assert(size <= LIMIT && "size is larger than the expected limit");
    assert(str != NULL && "the caller must ensure st ris not null");

    void *result = malloc(sizeof(str));
    memcpy(result, str, sizeof(result));
    return result;
}
