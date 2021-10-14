#include "gtest/gtest.h"

extern "C"{
    #include "upload.h"
}

#define DATA "D:\\C_projects\\Task_1\\data\\data_structs.txt"
#define STRING_BUFFER_SIZE 256

TEST (UPLOAD_TEST, OPEN_FILE){
    FILE* data_file = nullptr;
    data_file = fopen(DATA, "rt");
    ASSERT_NE(data_file, nullptr);
    fclose(data_file);
}

TEST (UPLOAD_TEST, STRUCTS_NUMBER){
    FILE* data_file = fopen(DATA, "rt");
    EXPECT_EQ(get_structs_number(data_file), 10);
    fclose(data_file);
}

TEST (UPLOAD_TEST, FILL_ARRAY_STRCUTS) {
    FILE* data_file = fopen(DATA, "rt");
    int structs_number = get_structs_number(data_file);
    char string_buffer[STRING_BUFFER_SIZE];
    road **array = create_array_of_structs(structs_number);
    for (int i = 0; i < structs_number; i++) {
        array[i] = create_struct();
        ASSERT_NE(array[i], nullptr);
        char road_type_buffer[STRING_BUFFER_SIZE];
        fgets(string_buffer, STRING_BUFFER_SIZE, data_file);
        ASSERT_NE(string_buffer, nullptr);
        sscanf(string_buffer, "%lf %s %lf %d",
               &array[i]->length,
               road_type_buffer,
               &array[i]->quality,
               &array[i]->quantity_lanes);
        array[i]->type = set_type(road_type_buffer);
        EXPECT_NE(array[i]->length, 0);
        EXPECT_NE(array[i]->type, nullptr);
        EXPECT_NE(array[i]->quality, 0);
        EXPECT_NE(array[i]->quantity_lanes, 0);
    }
    all_free_memory(data_file, array, structs_number);
}

int main(int n_args, char* args[]){
    ::testing::InitGoogleTest(&n_args, args);
    return RUN_ALL_TESTS();
}