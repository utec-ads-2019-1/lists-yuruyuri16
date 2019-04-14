cmake_minimum_required(VERSION 3.14)
project(lists)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

add_executable(
    lists
    circular.h
    forward.h
    iterator.h
    linked.h
    list.h
    main.cpp
    node.h
    iterators/bidirectional_iterator.h
    iterators/forward_iterator.h
    mock/mocker.h
    mock/mocker.cpp
)
