#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

extern int32_t si1, si2, sresult;
extern uint32_t ui1, ui2, uresult;

int main(void)
{
    if ((si2 < 0) || (si2 >= sizeof(int32_t) * CHAR_BIT)) {
        // Error нельзя делать сдвиг
    } else {
        sresult = si1 >> si2;
    }

    if (ui2 >= sizeof(uint32_t) * CHAR_BIT) {
        // Error нельзя делать сдвиг
    } else {
        uresult = ui1 >> ui2;
    }
    return EXIT_SUCCESS;
}
