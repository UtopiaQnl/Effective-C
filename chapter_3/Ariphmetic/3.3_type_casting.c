#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Явное приведение типов
    int32_t si = 5;
    int16_t ss = 8;
    int64_t sl = (int64_t)si;
    uint16_t us = (uint16_t)(ss + sl);

    printf("int32_t si = %" PRId32 " sizeof(%zu)\n", si, sizeof(si));
    printf("int16_t ss = %" PRId16 " sizeof(%zu)\n", ss, sizeof(ss));
    printf("int64_t sl = %" PRId64 " sizeof(%zu)\n", sl, sizeof(sl));
    printf("uint16_t us = %" PRIu16 " sizeof(%zu)\n", us, sizeof(us));
    printf("sizeof(ss + ls) = %zu, aka long (int64_t)\n", sizeof(ss + sl));

    uint32_t ui = UINT32_MAX;
    signed char c = -1;

    if (c == ui) {
        puts("-1 eq 4,294,967,295");
    }

    return EXIT_SUCCESS;
}
