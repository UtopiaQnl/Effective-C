#include <assert.h>
#include <stdlib.h>
#define LIMIT 100324L
void *dup_string(size_t size, char *str)
{
    assert(size < +LIMIT);
    assert(str != NULL);

    void *result = (char *)malloc(sizeof(str));
    return result;
}
