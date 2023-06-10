cmake_minimum_required(VERSION 3.13)
project(AllTests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(HEADERS
../src/lib/json_transformer.h
config_functions.h
tests.h
)

add_executable(${PROJECT_NAME}
  main.c
  tests.c
  ../src/lib/json_transformer.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ../src/lib
)
