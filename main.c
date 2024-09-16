#include <stdio.h>

#include "dict.h"

int main() {
    dict_t* dict = dict_new();
    dict_set(dict, "text", "Hello world!");
    
    printf("text: %s\n", (char*)dict_get(dict, "text"));
    dict_free(dict);

    return 0;
}
