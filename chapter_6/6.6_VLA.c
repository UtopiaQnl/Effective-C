#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int* a = alloca(234);
    int len;
    puts("Enter len: ");
    scanf("%d", &len);

    int arr[len];

    for (size_t i = 0; i < len; ++i) {
        *(arr + i) = 34;
    }

    putchar('[');
    for (size_t i = 0; i < len - 1; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[len - 1]);

    return EXIT_SUCCESS;
}
