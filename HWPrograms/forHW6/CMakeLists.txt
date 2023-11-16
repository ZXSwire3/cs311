include_directories(modifiedllist)
include_directories(slistTest)

configure_file(table.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

#HW6_slistTest
add_executable(HW6_slistTest
        modifiedllist/slist.cpp
        modifiedllist/slist.h
        modifiedllist/llist.cpp
        modifiedllist/llist.h
        slistTest/slisttest.cpp)
#HW6_client
add_executable(HW6_client
        modifiedllist/slist.cpp
        modifiedllist/slist.h
        modifiedllist/llist.cpp
        modifiedllist/llist.h
        dgraph.cpp
        dgraph.h
        hw6client.cpp)
