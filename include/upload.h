#ifndef UPLOAD_H
#define UPLOAD_H

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

#define STRING_BUFFER_SIZE 256

road **upload_array_structs(FILE *, int structs_number);

int get_structs_number(FILE *);

void file_free_memory(FILE *);

void all_free_memory(FILE *, road **, int structs_number);

#endif //UPLOAD_H
