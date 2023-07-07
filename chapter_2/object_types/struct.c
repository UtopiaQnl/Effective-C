#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sigrecord {
    int32_t signum;
    char signame[20];
    char sigdesc[100];

} sigline, *sigline_p;

void print_sigrecord(const struct sigrecord *record) {
    printf("SIG NAME: %s\n", record->signame);
    printf("SIG NUMBER: %" PRId32 "\n", record->signum);
    printf("SIG DESCIPTION: %s\n", record->sigdesc);
}

int main(void) {
    sigline.signum = 5;
    strcpy(sigline.signame, "SIGINT");
    strcpy(sigline.sigdesc, "Interrupt from keyboard");

    print_sigrecord(&sigline);
    putchar('\n');

    sigline_p = &sigline;

    sigline_p->signum = 9;
    strcpy(sigline_p->signame, "SIGTERM");
    strcpy(sigline_p->sigdesc, "Termimate a process");

    print_sigrecord(sigline_p);
    putchar('\n');
    print_sigrecord(&sigline);

    return EXIT_SUCCESS;
}
