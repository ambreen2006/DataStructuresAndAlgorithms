add_executable(userapp main.cpp)
include_directories(../mb_ds)
target_link_libraries(userapp mb_datastructures)