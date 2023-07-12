#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    uint32_t a = 100;
    printf("sizeof(uint32_t a) = %zu\n", sizeof(a));
    printf("sizeof(a) * CHARBIT = %lubit\n", sizeof(a) * CHAR_BIT);

    uint8_t order = 0x01;
    printf("%s-endian\n", ((order & 1) == 1) ? "little" : "big");
    // OR
    uint16_t order_ = 0x0001;
    printf("%s-endian\n", *((uint8_t *)&order_) ? "little" : "big");
    return EXIT_SUCCESS;
}
