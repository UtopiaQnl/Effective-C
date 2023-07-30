#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int32_t count;
    float quant;
    char units[21];
    char item[21];

    do {
        count = fscanf(stdin, "%f%20s of %20s", &quant, units, item);
        fscanf(stdin, "%*[^\n]");
    } while (!feof(stdin) && !ferror(stdin));

    return EXIT_SUCCESS;
}
