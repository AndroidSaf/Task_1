#ifndef MEMORY_H
#define MEMORY_H

#include "stdlib.h"
#include "string.h"

typedef struct road_struct {
    double length;
    char *type;
    double quality;
    int quantity_lanes;
} road;

char *set_type(char *type_name);

road *create_struct();

road **create_array_of_structs(int structs_number);

#endif //MEMORY_H