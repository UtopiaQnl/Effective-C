#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    uint64_t a = 2LL;
    signed long long ll = 0LL;
    unsigned long long ull = 0LL;
    signed long l = 0LL;
    unsigned long ul = 0LL;

    printf("a - %" PRId64 "\n", a);
    printf("size a - %zu\n", sizeof(a));
    printf("signed LONG MAX - %ld [sizeof(%zu)]\n", LONG_MAX, sizeof(l));
    printf("unsigned LONG MAX - %lu [sizeof(%zu)]\n", ULONG_MAX, sizeof(ul));
    printf("signed LONG LONG MAX - %lld [sizeof(%zu)]\n", LLONG_MAX, sizeof(ll));
    printf("unsigned LONG LONG MAX - %llu [sizeof(%zu)]\n", ULLONG_MAX, sizeof(ull));
    printf("HEX uint64_t - 0x%" PRIX64 "\n", UINT64_MAX);
    return EXIT_SUCCESS;
}
