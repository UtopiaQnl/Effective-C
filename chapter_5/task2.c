#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

size_t find_element(size_t len, int32_t arr[len], int32_t key)
{
    for (size_t i = 0; i < len; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return UINTMAX_MAX;
}
