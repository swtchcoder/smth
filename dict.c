#include <stdlib.h>
#include <string.h>

#include "dict.h"
#include "list.h"

dict_s* dict_new() {
    dict_s* dict = calloc(1, sizeof(dict_s));
    dict->entries = list_new(sizeof(dict_entry_s));

    return dict;
}

int dict_find(dict_s* dict, char* key) {
    for (int i = 0; i< dict->entries->length; i++) {
        if (strcmp(key, (char*)list_get(dict->entries, i))) {
            return i;
        }
    }

    return -1;
}

void dict_set(dict_s* dict, char* key, char* value) {
    int index = dict_find(dict, key);
    dict_entry_s* dict_entry = calloc(1, sizeof(dict_entry_s));

    if (index == -1) {
        dict_entry->key = key;
        dict_entry->value = value;

        list_append(dict->entries, dict_entry);
        return;
    }

    dict_entry = (dict_entry_s*)list_get(dict->entries, index);
    dict_entry->value = value;
}

char* dict_get(dict_s* dict, char* key) {
    int index = dict_find(dict, key);
    if (index == -1) {
        return 0;
    }

    dict_entry_s* dict_entry = (dict_entry_s*)list_get(dict->entries, index);
    return dict_entry->value;
}

void dict_free(dict_s* dict) {
    list_free(dict->entries);
    free(dict);
}