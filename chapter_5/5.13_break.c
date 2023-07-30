#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

size_t find_element(size_t len, int32_t arr[len], int32_t key)
{
    size_t pos = (size_t)-1;
    for (size_t i = 0; i < len; ++i) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }
    return pos;
}
