#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *temp = getenv("TERM");
    if (temp != NULL) {
        char *tmpvar = strdup(temp);
        if (tmpvar != NULL) {
            printf("TMP = %s\n", tmpvar);
            free(tmpvar);
        }
    }

    return EXIT_SUCCESS;
}
