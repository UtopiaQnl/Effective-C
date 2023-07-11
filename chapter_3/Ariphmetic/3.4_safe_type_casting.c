#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t do_stuff(int64_t value) {
    if ((value < SCHAR_MIN) || (value > SCHAR_MAX)) {
        return ERANGE;
    }
    signed char sc = (signed char)value;
    printf("sc - %d [sizeof(%d) = %zu]\n", sc, sc, sizeof(sc));

    return 0;
}

int main(void) {

    printf("returncode - %" PRId32 "\n", do_stuff(SCHAR_MAX + 2));
    printf("returncode - %" PRId32 "\n", do_stuff(SCHAR_MAX));
    printf("returncode - %" PRId32 "\n", do_stuff(423L));
    return EXIT_SUCCESS;
}
