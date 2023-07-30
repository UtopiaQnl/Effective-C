#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int32_t a = 6;
    int32_t c, b = 10;

    size_t count = 0;

    a = 45;
    c = a + b;
    ;  // нулевое выражение, ничего не делает
    ++count;

    return EXIT_SUCCESS;
}
