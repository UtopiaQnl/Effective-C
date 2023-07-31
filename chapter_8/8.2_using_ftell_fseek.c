#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("fred.txt", "r");

    if (!fp) {
        fputs("Cannot open fred.txt", stderr);
        return EXIT_FAILURE;
    }
    if (fseek(fp, 0, SEEK_END) != 0) {
        fputs("Seek to end of file filed.\n", stderr);
        return EXIT_FAILURE;
    }
    int64_t fpi = ftell(fp);
    if (fpi == -1L) {
        perror("Tell");
        return EXIT_FAILURE;
    }
    printf("file positino = %" PRId64 "\n", fpi);
    if (fclose(fp) == EOF) {
        fputs("Failed to close file\n", stderr);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
