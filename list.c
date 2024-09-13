#include <stdlib.h>

#include "list.h"

list_t* list_new(int element_size) {
    list_t* list = calloc(1, sizeof(list_t));
    list->elements = 0;
    list->element_size = element_size;
    list->length = 0;
    
    return list;
}

void list_append(list_t* list, void* element) {
    list->length++;

    if (list->length == 1) {
        list->elements = calloc(1, list->element_size);
    } else {
        list->elements = realloc(list->elements, list->length * list->element_size);
    }

    list->elements[list->length - 1] = element;
}

void* list_get(list_t* list, int index) {
    if (index < 0 || index >= list->length) {
        return NULL;
    }

    return list->elements[index];
}

void list_free(list_t* list) {
    for (int i = 0; i < list->length; i++) {
        free(list_get(list, i));
    }

    free(list->elements);
    free(list);
}