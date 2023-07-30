#include <stdint.h>

static inline int32_t absolute_value(int32_t a)
{
    return (a < 0) ? -a : a;
}
