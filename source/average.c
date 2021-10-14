#include "average.h"

double get_average_quality(road **array, int structs_number, char *road_type, int road_quantity_lanes) {
    double sum_quality_roads = 0;
    int roads_number = 0;

    for (int i = 0; i < structs_number; i++) {
        if ((!strcmp(array[i]->type, road_type)) && (array[i]->quantity_lanes == road_quantity_lanes)) {
            sum_quality_roads += array[i]->quality;
            roads_number++;
        }
    }
    return sum_quality_roads / roads_number;
}

