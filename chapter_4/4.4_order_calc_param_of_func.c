#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// #include <sys/param.h> MAX, MIN - marcos
#define MAX(a, b)               \
    ({                          \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        _a > _b ? _a : _b;      \
    })

int32_t glob;  // статическое хранилище инициализаируется с помощью 0

int32_t f(void);
int32_t g(void);

int main(void) {
    int32_t max_value = MAX(g(), f());
    printf("max_value - %" PRId32 "\n", max_value);
    glob = 0;
    max_value = MAX(f(), g());
    printf("max_value - %" PRId32 "\n", max_value);
    return EXIT_SUCCESS;
}

int32_t f(void) {
    return glob + 10;
}

int32_t g(void) {
    glob = 42;
    return glob;
}
