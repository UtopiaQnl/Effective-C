#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char c[10];
    int32_t i;
    double d;
} widget;

int main(void)
{
    widget *p = (widget *)malloc(sizeof(widget));
    if (!p) {
        // Обрабатываем ошибку выделения
    }
    // Продолжаем обработку

    widget w = {"abc", 9, 3.2};

    memcpy(p, &w, sizeof(widget));

    printf("p.i = %" PRId32 "\n", p->i);

    return EXIT_SUCCESS;
}
