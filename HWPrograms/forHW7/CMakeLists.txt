include_directories(HW1StackFiles)
include_directories(HW6Files)

configure_file(table.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(HW7_client
        HW6Files/dgraph.cpp
        HW6Files/dgraph.h
        HW6Files/slist.cpp
        HW6Files/slist.h
        HW6Files/llist.cpp
        HW6Files/llist.h
        HW1StackFiles/stack.cpp
        HW1StackFiles/stack.h
        hw7client.cpp)