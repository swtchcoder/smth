#ifndef LIST_H
#define LIST_H

typedef struct {
    void** elements;
    int element_size;
    int length;
} list_s;

list_s* list_new(int element_size);
void list_append(list_s* list, void* element);
void* list_get(list_s* list, int index);
void list_free(list_s* list);

#endif