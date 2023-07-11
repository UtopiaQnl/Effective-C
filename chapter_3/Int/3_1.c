#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define print(x) printf("%s\n", x);

// void print(const char *restrict line);

int main(void) {
    unsigned int ui = UINT_MAX;  // 4,294,967,295
    ui++;
    printf("ui = %u\n", ui);  // 0
    ui--;
    printf("ui = %u\n", ui);  // 4,294,967,295

    uint32_t ui2 = UINT_MAX;
    ui2++;
    printf("ui2 = %u\n", ui2);  // 0
    ui2--;
    printf("ui2 = %u\n", ui2);  // 4,294,967,295

    int a = 0;
    if (ui + ui2 > UINT_MAX)
        // unreachable code
        print("no way.");

    if (ui - ui2 < 0)
        // unreachable code
        print("no way2");

    if (ui > UINT_MAX - ui2)
        printf("a = %d\n", a);
    else
        print("ok");

    printf("%d\n", a);
    return EXIT_SUCCESS;
}

// void print(const char *restrict line) {
// printf("%s\n", line);
// }
