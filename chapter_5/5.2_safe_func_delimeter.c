#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

bool safediv(int32_t dividend, int32_t divisor, int32_t *quotient)
{
    if (!quotient) return false;
    if ((divisor == 0) || ((dividend == INT32_MIN) && (divisor == -1))) return false;

    *quotient = dividend / divisor;

    return true;
}
