cmake_minimum_required(VERSION 3.3)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(Conan)

project(TransactionExample CXX)

setup_conan()
conan_set_std()
conan_global_flags()

add_executable(TransactionExample main.cpp)
conan_target_link_libraries(TransactionExample)
