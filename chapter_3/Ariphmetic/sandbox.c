#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SAFE(call)        \
    if ((call) == NULL) { \
        perror(__func__); \
        return errno;     \
    }
int main(void) {
    FILE *file = NULL;

    SAFE(file = fopen("some.txt", "r"));

    return EXIT_SUCCESS;
}
