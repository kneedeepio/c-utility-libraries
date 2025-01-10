cmake_minimum_required(VERSION 3.0)
project("C-Utility-Libraries" C)

add_subdirectory(src)

# Our tests need to let CTest know we're running tests
include(CTest)

# It also needs to understand we have code in source and test directories
add_subdirectory(unity)
add_subdirectory(tests)
