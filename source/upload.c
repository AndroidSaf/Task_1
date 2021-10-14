#include "upload.h"

int get_structs_number(FILE *data_file) {
    int structs_number = 0;
    char read_buffer[STRING_BUFFER_SIZE];
    while (fgets(read_buffer, STRING_BUFFER_SIZE, data_file) != NULL) {
        structs_number++;
    }
    fseek(data_file, 0, SEEK_SET);
    return structs_number;
}

road **upload_array_structs(FILE *data_file, int structs_number) {

    char string_buffer[STRING_BUFFER_SIZE];
    road **array = create_array_of_structs(structs_number);
    for (int i = 0; i < structs_number; i++) {
        array[i] = create_struct();
        if (array[i] == NULL) {
            fprintf(stderr, "Error with allocating memory for struct.");
            return NULL;
        }
        char road_type_buffer[STRING_BUFFER_SIZE];
        fgets(string_buffer, STRING_BUFFER_SIZE, data_file);
        sscanf(string_buffer, "%lf %s %lf %d",
               &array[i]->length,
               road_type_buffer,
               &array[i]->quality,
               &array[i]->quantity_lanes);
        array[i]->type = set_type(road_type_buffer);
    }
    return array;
};

void file_free_memory(FILE *data_file) {
    fclose(data_file);
};

void all_free_memory(FILE *data_file, road **array, int structs_number) {
    fclose(data_file);
    if (array != NULL) {
        for (int i = 0; i < structs_number; i++) {
            free(array[i]->type);
            free(array[i]);
        }
        free(array);
    }
};
