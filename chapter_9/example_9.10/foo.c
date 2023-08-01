#include "my.h"

struct S {
    int x, y;
};

int main(void)
{
    // #define ATOMIC_VAR_INIT(value) (value)
    struct S val = ATOMIC_VAR_INIT({1, 2});
    return 0;
}
