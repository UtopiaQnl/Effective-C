#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/*
 * pow(base, exponent) - функции для возведения base в степень exponent: base^exponent.
 *
 * Разные pow:
 *
 *   *   pow(double base, double exponent) для double
 *
 *   *   powf(float base, float exponent) для float
 *
 *   *   powl(long double base, long exponent) для long double
 *
 * */
int main(void)
{
    int32_t i = 128;
    if (i == pow(2, 7)) {
        return puts("128 == 2^7");
    }


    return EXIT_SUCCESS;
}
