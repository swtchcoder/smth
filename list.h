#ifndef LIST_H
#define LIST_H

typedef struct {
    void** elements;
    int element_size;
    int length;
} list_t;

list_t* list_new(int element_size);
void list_append(list_t* list, void* element);
void* list_get(list_t* list, int index);
void list_free(list_t* list);

#endif