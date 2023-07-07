#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void) {
    char a = 'A';
    unsigned char b = 'B';
    signed char c = 'C';
    wchar_t X = u'Ы';

    printf("sizeof(char) - %ld\n", sizeof(a));
    printf("sizeof(unsigned char) - %ld\n", sizeof(b));
    printf("sizeof(signed char) - %ld\n\n", sizeof(c));

    printf("sizeof(wchar_t) (unicode) - %ld\n\n", sizeof(X));

    return EXIT_SUCCESS;
}
