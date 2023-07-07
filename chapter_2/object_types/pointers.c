#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t some_func(void) {
    uint16_t a = 24;
    return (int64_t)a;
}

int main(void) {
    int32_t a = 173;
    int32_t b = 2;

    int32_t *p_a = &a;
    int32_t *p_b = &b;

    printf("a - %" PRId32 ", b - %" PRId32 "\n", a, b);
    printf("p_a - %p, p_b - %p\n", (void *)p_a, (void *)p_b);
    printf("*p_a - %" PRId32 ", *p_b - %" PRId32 "\n\n", *p_a, *p_b);

    printf("a + b = %" PRId32 "\n", a + b);
    printf("*p_a + *p_b = %" PRId32 "\n\n", *p_a + *p_b);

    // Если операнд указывает на функцию, то результатом использования * будет ее обозначение (designator)
    printf("&som_func - %p\n", (void *)&some_func);
    printf("*som_func - %p\n", (void *)*some_func);

    return EXIT_SUCCESS;
}
