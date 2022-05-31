cmake_minimum_required(VERSION 3.1)
project(base-cmake VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

File(GLOB MyCppSources src/*.cpp)

add_executable(base-cmake 
    ${MyCppSources}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(CMAKE_GENERATOR MATCHES "Visual Studio") 
    add_custom_command(TARGET base-cmake POST_BUILD
                       COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CMAKE_SOURCE_DIR}/Resources" "${CMAKE_BINARY_DIR}/$<CONFIGURATION>/Resources")
else()
    add_custom_command(TARGET base-cmake POST_BUILD
                       COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CMAKE_SOURCE_DIR}/Resources" "${CMAKE_BINARY_DIR}/Resources")
endif()