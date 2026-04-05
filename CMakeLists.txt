cmake_minimum_required(VERSION 3.10)
project(OS_Lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
    main.cpp
    marker.cpp
)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    tests/test_marker.cpp
    marker.cpp
)

target_link_libraries(tests gtest_main)

add_test(NAME MyTests COMMAND tests)