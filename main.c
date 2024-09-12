#include <stdio.h>

#include "dict.h"

int main(int argc, char** argv) {
    dict_s* dict = dict_new();
    dict_set(dict, "text", "Hello world!");
    
    printf("text: %s\n", (char*)dict_get(dict, "text"));

    return 0;
}