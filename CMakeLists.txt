cmake_minimum_required(VERSION 3.26)
project(cs311)

set(CMAKE_CXX_STANDARD 98)

include_directories(DemoPrograms/OOP-Demo/1-FriendFunction)
include_directories(DemoPrograms/OOP-Demo/2-References)
include_directories(DemoPrograms/OOP-Demo/3-InheritedFunction)
include_directories(DemoPrograms/OOP-Demo/4-InterfaceClass)
include_directories(DemoPrograms/OOP-Demo/5-SimplyVirtual)
include_directories(DemoPrograms/OOP-Demo/6-Polymorphism)
include_directories(HWPrograms/forEC2/MSTShortest)
include_directories(HWPrograms/forHW1/HW1P1_stack)
include_directories(HWPrograms/forHW1/HW1P2_queue)
include_directories(HWPrograms/forHW3new)
include_directories(HWPrograms/forHW3new/HW3demos)
include_directories(HWPrograms/forHW4)
include_directories(HWPrograms/forHW5)
include_directories(HWPrograms/forHW6)
include_directories(HWPrograms/forHW8)

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