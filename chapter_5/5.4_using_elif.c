18 void printgrade(uint32_t marks) …
{
#include <stdio.h>
#include <stdlib.h>

    void printgrade(uint32_t marks)
    {
        char *mark;
        if (marks >= 90) {
            mark = "A";
        } else if (marks >= 80) {
            mark = "B";
        } else if (marks >= 70) {
            mark = "C";
        } else {
            mark = "Failed";
        }

        if (!marks) puts("234");
        puts("234");

        printf("YOUR GRADE : %s", mark);
    }
