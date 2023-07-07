#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void increment(void) {
    static uint32_t counter = 0;
    counter++;
    printf("%" PRIu32 " ", counter);
}

int main(void) {
    for (size_t i = 0; i < 5; i++) {
        increment();
    }
    return EXIT_SUCCESS;
}
