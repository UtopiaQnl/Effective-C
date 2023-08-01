#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
static uint64_t power(uint64_t x, uint64_t y, uint64_t p)
{
    uint64_t result = 1LLU;
    x %= p;

    while (y) {
        if (y & 1) result = (result * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }

    return result;
}

static bool miller_rabin_test(uint64_t d, uint64_t n)
{
    uint64_t a = 2 + rand() % (n - 4);
    uint64_t x = power(a, d, n);

    if (x == 1 || x == n - 1) return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}
