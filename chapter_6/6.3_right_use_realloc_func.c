#include <stdlib.h>


int main(void)
{
    void *p2;
    void *p = malloc(100);

    size_t nsize = 34;
    if ((nsize == 0) || (p2 = realloc(p, nsize)) == NULL) {
        free(p);
        return EXIT_FAILURE;  // return NULL
    }
    p = p2;

    return EXIT_SUCCESS;
}
