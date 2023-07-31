#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(void)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    const char *pathname = "/tmp/file";
    int fd;

    if ((fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode) == -1)) {
        fprintf(stderr, "Can't open %s\n", pathname);
        exit(1);
    }

    return EXIT_SUCCESS;
}
