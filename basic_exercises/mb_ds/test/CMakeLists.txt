addflags()

add_executable(ds_tests mb_ds_tests.cpp)

add_dependencies(ds_tests mb_datastructures)

include_directories(${GTEST_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/mb_ds")

target_link_libraries(ds_tests ${GTEST_LIBS_DIR} ${GMOCK_LIBS_DIR} pthread mb_datastructures)
