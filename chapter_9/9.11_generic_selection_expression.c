#include <math.h>

// clang-format off
#define sin(X) _Generic((X), \
    float: sinf, \
    double: sin, \
    long double: sinl \
)(X)
// clang-format on


int main(void)
{
    float f = sin(1.5708f);
    double d = sin(3.14159);

    return 0;
}
