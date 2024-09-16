#include <stdlib.h>
#include <string.h>

#include "dict.h"
#include "list.h"

dict_t* dict_new() {
    dict_t* dict = list_new(sizeof(dict_entry_t));

    return dict;
}

int dict_find(dict_t* dict, char* key) {
    for (unsigned int i = 0; i< dict->length; i++) {
        if (strcmp(key, (char*)list_get(dict, i))) {
            return i;
        }
    }

    return -1;
}

void dict_set(dict_t* dict, char* key, void* value) {
    int index = dict_find(dict, key);
    dict_entry_t* dict_entry = calloc(1, sizeof(dict_entry_t));

    if (index == -1) {
        dict_entry->key = key;
        dict_entry->value = value;

        list_append(dict, dict_entry);
        return;
    }

    dict_entry = (dict_entry_t*)list_get(dict, index);
    dict_entry->value = value;
}

void* dict_get(dict_t* dict, char* key) {
    int index = dict_find(dict, key);
    if (index == -1) {
        return 0;
    }

    dict_entry_t* dict_entry = (dict_entry_t*)list_get(dict, index);
    return dict_entry->value;
}

void dict_free(dict_t* dict) {
    list_free(dict);
    free(dict);
}
