include_directories("../src")

add_executable(test_c_utility_libraries
        run_tests.c
        test_simple_object_pool.c)

target_link_libraries(test_c_utility_libraries
        unity
        lib_simple_object_pool)
