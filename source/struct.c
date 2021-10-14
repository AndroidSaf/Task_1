#include "struct.h"
#include "stdlib.h"

road *create_struct() {
    road *new_road = (road *) malloc(sizeof(road));
    new_road->length = 0;
    new_road->type = NULL;
    new_road->quality = 0;
    new_road->quantity_lanes = 0;
    return new_road;
};

char *set_type(char *name_type) {
    char *memory = (char *) malloc(sizeof(char) * strlen(name_type) + 1);
    return strcpy(memory, name_type);
};

road **create_array_of_structs(int structs_number) {
    return (road **) malloc(sizeof(road *) * structs_number);
};