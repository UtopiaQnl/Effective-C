#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdc-predef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// В макросе fpclassify используется функция show_classification
const char *show_classification(double x) {
    switch (fpclassify(x)) {
    case FP_INFINITE:
        return "Inf";
    case FP_NAN:
        return "NaN";
    case FP_NORMAL:
        return "normal";
    case FP_SUBNORMAL:
        return "subnormal";
    case FP_ZERO:
        return "zero";
    default:
        return "unknown";
    }
}

int main(void) {

    printf("%s\n", show_classification(INFINITY));
    return EXIT_SUCCESS;
}
