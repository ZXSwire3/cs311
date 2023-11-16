#cpp (GCC) 4.8.5 20150623 (Red Hat 4.8.5-44)
#gcc version 4.8.5 20150623 (Red Hat 4.8.5-44) (GCC)
cmake_minimum_required(VERSION 3.26)
project(cs311)

set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(HWPrograms/forHW1/HW1P1_stack)
#add_subdirectory(HWPrograms/forHW3new)
#add_subdirectory(HWPrograms/forHW4)
#add_subdirectory(HWPrograms/forHW5)
#add_subdirectory(HWPrograms/forHW6)
add_subdirectory(HWPrograms/forHW7)
#[[
#HW1P1_stack
add_executable(HW1P1_stack_stacktest
        HWPrograms/forHW1/HW1P1_stack/stack.cpp
        HWPrograms/forHW1/HW1P1_stack/stack.h
        HWPrograms/forHW1/HW1P1_stack/stacktest.cpp)
add_executable(HW1P1_stack_client1
        HWPrograms/forHW1/HW1P1_stack/stack.cpp
        HWPrograms/forHW1/HW1P1_stack/stack.h
        HWPrograms/forHW1/HW1P1_stack/client1.cpp)
#HW1P2_queue
add_executable(HW1P2_queue_queuetest
        HWPrograms/forHW1/HW1P2_queue/queue.cpp
        HWPrograms/forHW1/HW1P2_queue/queue.h
        HWPrograms/forHW1/HW1P2_queue/queuetest.cpp)
add_executable(HW1P2_queue_client2
        HWPrograms/forHW1/HW1P2_queue/queue.cpp
        HWPrograms/forHW1/HW1P2_queue/queue.h
        HWPrograms/forHW1/HW1P2_queue/client2.cpp)
#HW1P3_matrix
add_executable(HW1P3_matrix
        HWPrograms/forHW1/HW1P3_matrix/mat.cpp)
#HW2P1_search
add_executable(HW2P1_search
        HWPrograms/forHW2/HW2P1_search/binsearch.cpp)
#HW2P2_sort
add_executable(HW2P2_partition
        HWPrograms/forHW2/HW2P2_sort/partition.cpp)
add_executable(HW2P2_combine
        HWPrograms/forHW2/HW2P2_sort/combine.cpp)
]]