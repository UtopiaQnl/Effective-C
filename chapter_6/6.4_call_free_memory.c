#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int closedir(DIR *dirp)
{
    free(dirp->d_buf);
    free(dirp);
    return close(dirp->d_fd);
}
