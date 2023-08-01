#include <stdio.h>
#include <tgmath.h>

// clang-format off
// #define cbrt(X) _Generic((X), \
//     long double: cbrtl(X), \
//     float: cbrtf(X), \
//     default: cbrt(X) \
// )
// clang-format on

int main(void)
{
    long double a = 34;
    long double result_a = cbrt(a);

    double b = 34;
    double result_b = cbrt(b);

    float c = 34;
    float result_c = cbrt(c);

    long double ld = 625.0L;
    double d = 625.0;
    float f = 625.0f;

    printf("cbrt(%Lf [sizeof %zu]) = %Lf\n", ld, sizeof(ld), cbrt(ld));
    printf("cbrt(%lf [sizeof %zu]) = %lf\n", d, sizeof(d), cbrt(d));
    printf("cbrt(%f [sizeof %zu]) = %f\n", d, sizeof(f), cbrt(f));

    return 0;
}
