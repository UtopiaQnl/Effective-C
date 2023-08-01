#include <stddef.h>

struct node_type {
    void *data;
    size_t size;
    struct node_type *next;
};

struct collection_type {
    size_t num_elements;
    struct node_type *head;
};
