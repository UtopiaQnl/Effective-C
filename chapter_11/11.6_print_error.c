#define __STDC_WANT_LIB_EXT1__ 1
#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENERRORSTR 1024

errno_t print_error(errno_t errnum)
{
    rsize_t size = MAXLENERRORSTR;
    char* msg = (char*)malloc(size);

    if ((msg != NULL) && (strerror_s(msg, size, errnum) != 0)) {
        fputs(msg, stderr);
        return 0;
    } else {
        fputs("unknown error :3", stderr);
        return ENOMEM;
    }
}

int main(void)
{
    print_error(ENOMEM);
}
