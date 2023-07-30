#include <assert.h>
#include <inttypes.h>
#include <stdalign.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int32_t arr[5];
    static_assert(_Alignof(arr) == 4, "unexpected aligment");  // статическое утверждение
    assert(alignof(max_align_t) == 16);  // динамическое утверждение

    printf("Alignment of arr = %zu\n", _Alignof(arr));
    printf("alignment of max_align_t = %zu\n", alignof(max_align_t));


    return EXIT_SUCCESS;
}
