// Объединения похожи на структуры, только их члены используют одну
// и ту же память. В один момент времени объединение может содержать
// объект одного типа, а в другой момент времени — объект другого типа,
// но никогда не может содержать оба объекта сразу. Объединения используются
// в основном для экономии памяти.
#include <stdint.h>
#include <stdlib.h>

union {
    struct {
        int32_t type;
    } n;
    struct {
        int32_t type;
        int32_t intnode;
    } ni;
    struct {
        int32_t type;
        double doublenode;
    } nf;
} u;

int main(void) {
    u.nf.type = 1;
    u.nf.doublenode = 3.1415;
    return EXIT_SUCCESS;
}
