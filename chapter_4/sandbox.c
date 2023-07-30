#include <inttypes.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5

int32_t m[N] = {1, 2, 3, 4, 5};

int sum_m_elems(void)
{
    int32_t result = 0;
    for (int32_t *pi = m; pi < m + N; ++pi) result += *pi;
    // for (int32_t *pi = m + 0; pi < &(m + N); ++pi) result += *pi;
    // for (int32_t *pi = &m[0]; pi < &m[N]; ++pi) result += *pi;
    return result;
}
int main(void)
{
    uint32_t a = 100;
    printf("sizeof(uint32_t a) = %zu\n", sizeof(a));
    printf("sizeof(a) * CHARBIT = %lubit\n", sizeof(a) * CHAR_BIT);

    uint8_t order = 0x01;
    printf("%s-endian\n", ((order & 1) == 1) ? "little" : "big");
    // OR
    uint16_t order_ = 0x0001;
    printf("%s-endian\n", *((uint8_t *)&order_) ? "little" : "big");

    int32_t A = 1;
    int32_t b = 2;
    int32_t c = -1;

    if (A < b < c) {
        puts("ok?");
    }

    int32_t arr[100] = {0};
    int32_t *arrp1 = &arr[40];
    int32_t *arrp2 = arrp1 + 20;  // &arr[40 + 20] => &arr[60]
    ptrdiff_t diffarr = arrp2 - arrp1;
    printf("diff between arrp1 (%p) and arrp2 (%p) = %td\n", (void *)arrp1, (void *)arrp2, diffarr);


    int32_t sum_of_m = sum_m_elems();
    printf("sum of m = %" PRId32 "\n", sum_of_m);

    return EXIT_SUCCESS;
}
