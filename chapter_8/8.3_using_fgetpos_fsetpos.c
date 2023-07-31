#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("fred.txt", "w+");
    if (!fp) {
        fputs("Cannot open fred.txt\n", stderr);
        return EXIT_FAILURE;
    }

    fpos_t pos;

    if (fgetpos(fp, &pos) != 0) {
        perror("get position");
        return EXIT_FAILURE;
    }

    if (fputs("_BEGIiiiiiiiiiiiiiiiiiiN_", fp) == EOF) {
        fputs("[_BEGIN_]:Cannot write to fred.txt file\n", stderr);
    }

    if (fsetpos(fp, &pos) != 0) {
        perror("set position");
        return EXIT_FAILURE;
    }

    int64_t fpi = ftell(fp);
    if (fpi == -1L) {
        perror("seek");
        return EXIT_FAILURE;
    }

    printf("file position = %" PRId64 "\n", fpi);

    if (fputs("+END+", fp) == EOF) {
        fputs("[+END+]:Cannot write to fred.txt file\n", stderr);
    }

    if (fclose(fp) == EOF) {
        fputs("Failed to close file\n", stderr);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
