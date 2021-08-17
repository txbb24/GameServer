# cmake版本要求
cmake_minimum_required(VERSION 2.6)

set(ENV{CC} "gcc")
set(ENV{CXX} "g++")

message("-- CC = $ENV{CC}")
message("-- CXX = $ENV{CXX}")

# 项目信息
project(GameServer)

# 需要编译的可执行模块
list(APPEND EXE_MODULES homeserver)

# 输出位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# 通用头文件
include_directories("common/include")

# 库文件
list(APPEND COMMON_LIB common)

# 编译选项
set(DCMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -g -Wall -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -g -Wall -O0 -DNDEBUG")

# 通用模块
add_subdirectory(common)

# 编译可执行模块
foreach(MODULE ${EXE_MODULES})
    add_subdirectory(servers/${MODULE})
endforeach(MODULE)
