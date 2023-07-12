#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t f(void);
void g(int32_t (*func)(void));

int main(void) {
    g(f);
    return EXIT_SUCCESS;
}

int32_t f(void) {
    puts("I'm a f-function!");
    return 0;
}

void g(int32_t (*func)(void)) {
    if (func() != 0)
        puts("g func failed!");
    else
        puts("g func EXIT_SUCCESS");
}
