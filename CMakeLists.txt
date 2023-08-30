cmake_minimum_required(VERSION 3.16.3)
project(simple_metaprogramming_library)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDART_REQUIRED True)


add_executable(runTests test/unit_tests.cpp test/type_list_test.cpp test/type_conditions_and_logic_test.cpp test/math_test.cpp)
target_link_libraries(runTests)

add_test(
	NAME runTests
	COMMAND runTests
)
