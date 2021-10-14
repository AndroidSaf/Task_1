#include <stdio.h>
#include "upload.h"
#include "average.h"

#define DATA "D:\\C_projects\\Task_1\\data\\data_structs.txt"

int main() {

    FILE *data_file = fopen(DATA, "rt");
    if (data_file == NULL) {
        fprintf(stderr, "File not found!\n");
        file_free_memory(data_file);
        return EXIT_FAILURE;
    }

    int structs_number = get_structs_number(data_file);
    road **array = upload_array_structs(data_file, structs_number);
    for (int i = 0; i < 10; i++) {
        printf("struct: %d\nroad_long = %lf\nroad_type: %s\nroad_quality = %lf\nroad_quantity_lanes = %d\n+-----------------------+\n",
               i + 1, array[i]->length, array[i]->type, array[i]->quality, array[i]->quantity_lanes);
    }

    char *road_type = "asphalt";
    int road_quantity_lanes = 5;
    double average_quality_roads = get_average_quality(array, structs_number, road_type, road_quantity_lanes);
    printf("\nAverage quality roads with type <%s> and <%d> quantity lanes equals <%2.2lf>\n", road_type,
           road_quantity_lanes, average_quality_roads);

    all_free_memory(data_file, array, structs_number);
    return EXIT_SUCCESS;
}
