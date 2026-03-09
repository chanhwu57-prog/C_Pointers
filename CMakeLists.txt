cmake_minimum_required(VERSION 3.10)
project(C_Pointers C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# 查找exercises/chapter_01目录下所有.c文件
file(GLOB EXERCISE_SOURCES "exercises/chapter_01/*.c")

# 为每个.c文件创建可执行目标
foreach(src ${EXERCISE_SOURCES})
    get_filename_component(target_name ${src} NAME_WE)
    add_executable(${target_name} ${src})
endforeach()
