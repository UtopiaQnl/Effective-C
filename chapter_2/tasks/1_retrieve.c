#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint32_t counter = 0;

void increment(void) {
    counter++;
}

uint32_t get_counter(void) {
    return counter;
}

int main(void) {
    for (size_t i = 0; i < 5; i++) {
        increment();
        printf("counter - %" PRIu32 "\n", get_counter());
    }
    return EXIT_SUCCESS;
}
