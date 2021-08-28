cmake_minimum_required(VERSION 3.3)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/sc-components/cmake)

include(Conan)

project(TransactionExample CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

setup_conan()

find_package(SystemC REQUIRED)
if(SystemC_FOUND)
    include_directories(${SystemC_INCLUDE_DIRS})
    link_directories(${SystemC_LIBRARY_DIRS})
else()
    message( FATAL_ERROR "SystemC library not found." )
endif()

if(SCV_FOUND)   
    add_definitions(-DWITH_SCV)
    include_directories(${SCV_INCLUDE_DIRS})
    link_directories(${SCV_LIBRARY_DIRS})
else()
    message( FATAL_ERROR "SystemC Verification library not found." )
endif(SCV_FOUND)

add_executable(TransactionExample main.cpp)
target_link_libraries(TransactionExample ${CONAN_LIBS})

# CTest is a testing tool that can be used to test your project.
# enable_testing()
# add_test(NAME example
#          WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#          COMMAND example)
