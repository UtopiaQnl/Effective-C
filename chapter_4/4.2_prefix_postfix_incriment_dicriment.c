#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int32_t i = 5;
    printf("i = %d\ne = i++; [", i);
    int32_t e;

    e = i++;
    printf("e - %d; i - %d]\ne = ++i; [", e, i);
    e = ++i;
    printf("e - %d; i - %d]\ne = i--; [", e, i);
    e = i--;
    printf("e - %d; i - %d]\ne = --i; [", e, i);
    e = i--;
    printf("e - %d; i - %d]\n", e, i);

    return EXIT_SUCCESS;
}
