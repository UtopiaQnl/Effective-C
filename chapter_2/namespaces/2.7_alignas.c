#include <stdint.h>
#include <stdlib.h>

struct S {
    int32_t i;
    double d;
    char c;
};

int main(void) {
    uint8_t bad_buff[sizeof(struct S)];                      // не оч' современно
    _Alignas(struct S) uint8_t good_buff[sizeof(struct S)];  // даже оч' совреенно

    struct S *bad_s_ptr = (struct S *)bad_buff;  // неправильное выравнивание указателя
    struct S *good_s_ptr = (struct S *)good_buff;  // правильное выравнивание указателя

    return EXIT_SUCCESS;
}
