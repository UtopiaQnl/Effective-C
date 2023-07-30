#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef DMALLOC
#include "dmalloc.h"
#endif

int main(void)
{
    // int* a = alloca(234);
    int len;
    puts("Enter len: ");
    scanf("%d", &len);

    int arr[len];

    for (size_t i = 0; i < len; ++i) {
        scanf("%d", arr + i);
    }

    putchar('[');
    for (size_t i = 0; i < len - 1; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[len - 1]);

    return EXIT_SUCCESS;
}
