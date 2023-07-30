#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int32_t marks = 23;

    switch (marks / 10) {
        case 10:
        case 9:
            puts("YOUR GRADE : A");
            break;
        case 8:
            puts("YOUR GRADE : B");
            break;
        case 7:
            puts("YOUR GRADE : C");
            break;
        default:
            puts("YOUR GRADE : Failed");
    }

    return EXIT_SUCCESS;
}
