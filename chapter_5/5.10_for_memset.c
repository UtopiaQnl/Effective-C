#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void *memset(void *dest, int32_t val, size_t n)
{
    uint8_t *ptr = (uint8_t *)dest;
    for (size_t i = 0; i < n; ++i) {
        *(ptr + i) = val;
    }
    return dest;
}

int main(void)
{
    return EXIT_SUCCESS;
}
