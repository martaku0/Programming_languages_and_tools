cmake_minimum_required(VERSION 3.10)
project(
    zaj4 
    VERSION 0.0.1 
    DESCRIPTION "Sample Linux VSCode/CMake Project"
    LANGUAGES CXX
)

# Wypisz nazwę oraz katalog główny projektu
message("Project_Name: ${PROJECT_NAME}")
message("Project_Dir: ${CMAKE_CURRENT_SOURCE_DIR}")  

# Opcje kompilatora
set(CMAKE_CXX_STANDARD 20) # Dodaj opcję '-std=c++20'
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug) # Dodaj opcję '-ggdb'

# Pliki źródłowe naszego przykładowego projektu
set(SOURCE 
    src/grep.cpp 
    src/sort.cpp
    src/tail.cpp
    src/main.cpp
)
add_executable(main ${SOURCE}) #  Jako wynik kompilacji podanych plików źródłowych ma być tworzony plik wykonywalny 'main' 
target_include_directories(main PUBLIC include) # Określamy katalogi, w których kompilator ma szukać plików nagłówkowych

###############
# Testy
###############
include(CTest) 
#find_package(GTest REQUIRED)

# POBIERANIE GTEST Z SIECI (Zamiast find_package)
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
    tests/test_grep.cpp
    tests/test_sort.cpp
    tests/test_tail.cpp
    
    src/grep.cpp
    src/sort.cpp
    src/tail.cpp
)
target_link_libraries(test_komend gtest_main)
#target_link_libraries(test_komend GTest::gtest_main)
enable_testing()
gtest_discover_tests(test_komend)