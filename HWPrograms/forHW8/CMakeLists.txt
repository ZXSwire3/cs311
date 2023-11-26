include_directories(HW7Files)

configure_file(input.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(newnewout.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(HW8_client
        slist.cpp
        slist.h
        llist.cpp
        llist.h
        elem.cpp
        elem.h
        htable.cpp
        htable.h
        hw8client.cpp)