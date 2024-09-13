#ifndef DICT_H
#define DICT_H

#include "list.h"

typedef struct {
    const char* key;
    void* value;
} dict_entry_t;

typedef struct {
    list_t* entries;
} dict_t;

dict_t* dict_new();
int dict_find(dict_t* dict, char* key);
void dict_set(dict_t* dict, char* key, void* value);
void* dict_get(dict_t* dict, char* key);
void dict_free(dict_t* dict);

#endif