#include <stdint.h>
#include <stdlib.h>


void *memset(void *dest, int32_t val, size_t n)
{
    uint8_t *ptr = (uint8_t *)dest;
    while (n-- > 0) {
        *ptr++ = (uint8_t)val;
    }
    return dest;
}
