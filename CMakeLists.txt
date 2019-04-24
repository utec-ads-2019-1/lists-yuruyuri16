cmake_minimum_required(VERSION 3.14)
project(lists)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

file(GLOB src
	"*.cpp"
	"*/*.cpp")

add_executable(lists ${src})
