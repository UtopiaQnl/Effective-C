#include <stdio.h>
#include <stdlib.h>


typedef struct object {
    int32_t a;
} object_t;


int32_t do_something(void)
{
    FILE *file1;
    FILE *file2;

    object_t *obj;
    int32_t ret_val = 0;  // изначально ожидаем возвращения успеногоз значения

    file1 = fopen("a_file", "w");
    if (file1 == NULL) {
        ret_val = -1;
        goto FAIL_FILE1;
    }
    file2 = fopen("another_file", "w");
    if (file2 == NULL) {
        ret_val = -1;
        goto FAIL_FILE2;
    }
    obj = malloc(sizeof(object_t));
    if (obj == NULL) {
        ret_val = -1;
        goto FAIL_OBJ;
    }
    // Работает с выделенными ресурсами

    // Освобождение ресурсов
    free(obj);
FAIL_OBJ:
    fclose(file2);
FAIL_FILE2:
    fclose(file1);
FAIL_FILE1:
    return ret_val;
}

int main(void)
{
    return EXIT_SUCCESS;
}
