#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char abc[] = "abc";
    char xyz[] = "xyz";
    char qwe[] = "qwe";

    char *p = abc;
    printf("*p = %c\n", *p);
    printf("++*p = %c\n", ++*p);
    printf("*p = %c\n", *p);

    puts("");

    p = xyz;
    printf("*p = %c\n", *p);
    printf("*p++ = %c\n", *p++);
    printf("*p = %c\n", *p);

    puts("");

    p = qwe;
    printf("*p = %c\n", *p);
    printf("*++p = %c\n", *++p);
    printf("*p = %c\n", *p);
    return EXIT_SUCCESS;
}
