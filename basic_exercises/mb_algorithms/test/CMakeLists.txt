addflags()

add_executable(mb_algorithms_tests mb_algorithms_test.cpp)

add_dependencies(mb_algorithms_tests mb_algorithms)

include_directories(${GTEST_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/mb_algorithms")

target_link_libraries(mb_algorithms_tests ${GTEST_LIBS_DIR} ${GMOCK_LIBS_DIR} pthread mb_algorithms)