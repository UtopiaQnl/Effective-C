#include <stdint.h>

int *func(int32_t i) {
    const int32_t j = i;   // правильно
    static int32_t k = j;  // ошибка
    return &k;
}
