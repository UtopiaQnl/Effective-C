#include <assert.h>
#include <stdint.h>

struct packed {
    uint32_t i;
    char *p;
};


static_assert(sizeof(struct packed) == sizeof(uint32_t) + sizeof(char *), "struct packed must not have any padding");
