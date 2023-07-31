#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int status = EXIT_SUCCESS;
    FILE *in = NULL;

    struct sigrecord {
        int32_t signum;
        char signame[10];
        char sigdesc[100];
    } sigrec;

    if ((in = fopen("signals.txt", "r")) == NULL) {
        fputs("Cannot open signals.txt file\n", stderr);
        return EXIT_FAILURE;
    }

    do {
        int32_t n = fscanf(in, "%d%9s%*[ \t]%99[^\n]", &sigrec.signum, sigrec.signame, sigrec.sigdesc);
        if (n == 3) {
            printf("Signal\n number = %" PRId32 "\n name = %s\n description = %s\n\n", sigrec.signum, sigrec.signame,
                   sigrec.sigdesc);
        } else if (n != EOF) {
            fputs("Filed to match dignum, digname of sigdesc\n", stderr);
            status = EXIT_FAILURE;
            break;
        } else {
            break;
        }
    } while (1);

    if (fclose(in) == EOF) {
        fputs("Filed to close file\n", stderr);
        status = EXIT_FAILURE;
    }

    return status;
}
