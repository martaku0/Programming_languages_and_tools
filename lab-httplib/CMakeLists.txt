cmake_minimum_required(VERSION 3.10)
project(WWW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Server
add_executable(server src/server.cpp)
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/httplib/include)

# Client
add_executable(client src/client.cpp)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/httplib/include)