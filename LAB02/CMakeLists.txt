add_library(implementations src/Palindrom.cpp)
target_include_directories(implementations PUBLIC include)

add_executable(tests uts/Palindrom_tests.cpp)
target_link_libraries(tests gmock_main gtest gmock implementations)
