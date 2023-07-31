#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[100] = "Here comes the sun";
    size_t str_size = strlen(str) + 1;
    char *dest = (char *)malloc(str_size);
    if (dest) {
        strcpy(dest, str);
    } else {
        // обрабатываем ошибку
    }

    return EXIT_SUCCESS;
}
