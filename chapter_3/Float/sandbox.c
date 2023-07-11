#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdc-predef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("__STDC_IEC_559__ - %d\n", __STDC_IEC_559__);
    printf("__STDC_IEC_559__ - %ld\n", __STDC_IEC_60559_BFP__);
    printf("NaN - %f\n", NAN);
    printf("+Infinity - +%f\n", INFINITY);
    printf("-Infinity - %f\n", -INFINITY);

    puts("");

    printf("FP_ZERO - %d\n", FP_ZERO);
    printf("FP_NAN - %d\n", FP_NAN);
    printf("FP_INFINITE - %d\n", FP_INFINITE);
    printf("FP_NORMAL - %d\n", FP_NORMAL);
    printf("FP_SUBNORMAL - %d\n", FP_SUBNORMAL);

    puts("");

    printf("fpclassify(0.0) - %d\n", fpclassify(0.0));
    printf("fpclassify(Nan) - %d\n", fpclassify(NAN));
    printf("fpclassify(INFINITY) - %d\n", fpclassify(INFINITY));
    printf("fpclassify(-INFINITY) - %d\n", fpclassify(-INFINITY));
    printf("fpclassify(234.5) - %d\n", fpclassify(234.5));
    printf("fpclassify(%.46f) - %d\n", FLT_MIN, fpclassify(FLT_MIN));

    puts("");

    float a = 15.75f;
    float a2 = 1.575e1f;  // 1.575E1f
    long double b = -2.5e-3L;
    double b2 = 25E-5;

    printf("a - %f\n", a);
    printf("a2 - %f\n", a2);
    printf("b - %Lf\n", b);
    printf("b2 - %lf\n", b2);

    // 10.0     double
    // 10.0f    float
    // 10.0F    float
    // 10.0l    long double
    // 10.0L    long double

    return EXIT_SUCCESS;
}
