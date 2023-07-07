#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(int32_t arr[5]);

int main(void) {
    uint32_t i = 0;
    uint32_t j = 0;
    int32_t arr[3][5];
    func(arr[i]);
    int32_t x = arr[i][j];
    return EXIT_SUCCESS;
}
