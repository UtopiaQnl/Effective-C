#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (puts("Hello, world") == EOF) {
        return EXIT_FAILURE;
        // здесь код никогда не выполняется
    }
    printf("some string\n");
    return EXIT_SUCCESS;
    // здесь код никогда не выполняется
}
