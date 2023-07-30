#include <stdint.h>
#include <stdlib.h>

typedef struct {
    size_t num;
    int32_t data[];
} widget;

void *func(const size_t array_size)
{
    widget *p = (widget *)malloc(sizeof(widget) + sizeof(int32_t) * array_size);
    if (p == NULL) {
        return NULL;
    }
    p->num = array_size;
    for (size_t i = 0; i < p->num; ++i) {
        p->data[i] = 17;
    }
}
