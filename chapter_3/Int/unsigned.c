#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int a = 0;
    printf("%-30s - %-20u sizeof(%zu)\n", "unsigned int", a, sizeof(a));

    uint32_t b = 0;
    printf("%-30s - %-20" PRIu32 " sizeof(%zu)\n", "uint32_t", b, sizeof(b));

    printf("%llu\n", ULLONG_MAX);
    printf("%lu\n", ULONG_MAX);
    printf("%u\n", UINT_MAX);
    long double g = DBL_MAX;
    printf("%Lf\n", g);
    printf("%.10000Lf\n", LDBL_MIN);
    return EXIT_SUCCESS;
}
