#include "gtest/gtest.h"


extern "C"{
    #include "average.h"
    #include "upload.h"
    #include "math.h"
}

#define DATA "D:\\C_projects\\Task_1\\data\\data_structs.txt"

TEST(EXECUTION_TEST, AVERAGE_COMPARISON) {
    FILE* data_file = nullptr;
    data_file = fopen(DATA, "rt");
    int structs_number = get_structs_number(data_file);
    road **array = upload_array_structs(data_file, structs_number);
    ASSERT_EQ(ceil(get_average_quality(array, structs_number, "asphalt", 5) * 100) / 100, 4.27);
    all_free_memory(data_file, array, structs_number);
}

int main(int n_args, char* args[]){
    ::testing::InitGoogleTest(&n_args, args);
    return RUN_ALL_TESTS();
}

