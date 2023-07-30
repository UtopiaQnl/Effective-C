#include <stdint.h>

int32_t absolute_value(int32_t a)
{
    if (a < 0) {
        return -a;
    }
    return a;

    // return (a < 0) ? -a : a;
}
