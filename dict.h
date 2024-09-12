#ifndef DICT_H
#define DICT_H

#include "list.h"

typedef struct {
    const char* key;
    char* value;
} dict_entry_s;

typedef struct {
    list_s* entries;
} dict_s;

dict_s* dict_new();
int dict_find(dict_s* dict, char* key);
void dict_set(dict_s* dict, char* key, void* value);
void* dict_get(dict_s* dict, char* key);
void dict_free(dict_s* dict);

#endif