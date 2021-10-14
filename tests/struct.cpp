#include "gtest/gtest.h"

extern "C"{
    #include "struct.h"
    #include "upload.h"
}

#define DATA "D:\\C_projects\\Task_1\\data\\data_structs.txt"

TEST(CREATE_TEST, CREATING_STRUCT) {
    road* new_road = create_struct();
    ASSERT_NE(new_road, nullptr);
    free(new_road);
}

TEST(CREATE_TEST, CREATING_STRING) {
    char* road_type = set_type("asphalt");
    ASSERT_NE(road_type, nullptr);
    free(road_type);
}

TEST(CREATE_TEST, CREATING_ARRAY_STRUCTS) {
    FILE* data_file = fopen(DATA, "rt");
    int structs_number = get_structs_number(data_file);
    road **array = create_array_of_structs(structs_number);
    ASSERT_NE(array, nullptr);
    free(array);
}

int main(int n_args, char* args[]){
    ::testing::InitGoogleTest(&n_args, args);
    return RUN_ALL_TESTS();
}