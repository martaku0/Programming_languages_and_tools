cmake_minimum_required(VERSION 3.10)
project(
    lab5 
    VERSION 0.0.1 
    DESCRIPTION "Sample Linux VSCode/CMake Project"
    LANGUAGES CXX
)

message("Project_Name: ${PROJECT_NAME}")
message("Project_Dir: ${CMAKE_CURRENT_SOURCE_DIR}")  

set(CMAKE_CXX_STANDARD 20) # '-std=c++20'
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug) # '-ggdb'

set(SOURCE 
    src/main.cpp
    src/butterOverflow.cpp
    src/encryptXOR.cpp
    src/findMalwareSignature.cpp
    src/strcpy.cpp
    src/validationFunctions.cpp
    src/vulnerability.cpp
)
add_executable(main ${SOURCE})
target_include_directories(main PUBLIC include)

###############
# Testy
###############
include(CTest) 
#find_package(GTest REQUIRED) # local package

# online package
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
add_executable(test_komend 
    tests/validationFunctions.cpp
    
    src/validationFunctions.cpp
)
target_link_libraries(test_functions gtest_main)
#target_link_libraries(test_functions GTest::gtest_main) # for local
enable_testing()
gtest_discover_tests(test_functions)