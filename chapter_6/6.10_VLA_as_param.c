#include <stdint.h>
#include <stdlib.h>

int32_t matrix_sum(size_t rows, size_t cols, int32_t m[rows][cols])
{
    int32_t result = 0;
    for (size_t r = 0; r < rows; r++) {
        for (size_t c = 0; c < cols; c++) {
            result += m[r][c];
        }
    }
    return result;
}
