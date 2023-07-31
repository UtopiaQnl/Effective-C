#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>

size_t gets_s(char* restrict dest, const size_t len)
{
    size_t count = 0;
    int c;

    char* p = dest;
    while (count++ < len - 1 && (c = getchar()) != EOF && c != '\n') {
        *p++ = c;
    }
    *p = '\n';

    return count;
}

void get_y_or_n(void)
{
    char responce[8];
    size_t len = sizeof(responce);
    puts("Continue? [y] n: ");
    gets_s(responce, len);
}

int main(void)
{
    get_y_or_n();

    return EXIT_SUCCESS;
}
