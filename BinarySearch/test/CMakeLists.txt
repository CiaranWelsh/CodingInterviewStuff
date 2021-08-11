



set(target BinarySearchTests)
add_executable(${target} BinarySearchTests.cpp)
target_include_directories(${target} PRIVATE ${CODING_INTERVIEW_INCLUDE_DIRECTORIES})
target_link_libraries(${target} PRIVATE gtest gtest_main gmock gmock_main)






















