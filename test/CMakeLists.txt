
include_directories(${SOURCE_DIR})

add_executable(unit_test test_main.cpp regularity_test.cpp matrix_test.cpp)
target_link_libraries(unit_test gtest pthread)
add_test(unit::test unit_test)
