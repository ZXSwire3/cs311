include_directories(HW3demos)

#HW3P1_Demos
add_executable(HW3demos_equalstest
        HW3demos/equalstest.cpp
        HW3demos/rlist.o)
add_executable(HW3demos_getstest
        HW3demos/getstest.cpp
        HW3demos/rlist.o)
add_executable(HW3demos_copyconsttest
        HW3demos/copyconsttest.cpp
        HW3demos/rlist.o)

#HW3P1_client
add_executable(HW3P1_client
        llist.cpp
        llist.h
        HW3P1client.cpp)
#HW3P2_client
add_executable(HW3P2_client
        llist.cpp
        llist.h
        slist.cpp
        slist.h
        HW3P2client.cpp)