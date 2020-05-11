cmake_minimum_required(VERSION 3.10)
project(mzpatterns)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CLANG_COVERAGE_COMPILE_FLAGS
    "-fprofile-instr-generate=codecov_data.profraw -fcoverage-mapping")
set(CMAKE_CXX_FLAGS "-g -O0")
set(CMAKE_DEBUG_POSTFIX "_d")

set(MZLIB "_MZ_")

set(MZ_PATTERNS
    pimpl
    singleton)

foreach(PATTERN ${MZ_PATTERNS})
    add_library(${MZLIB}${PATTERN} src/${PATTERN}/${PATTERN}.cpp)
    set_target_properties(${MZLIB}${PATTERN}
        PROPERTIES COMPILE_FLAGS ${CLANG_COVERAGE_COMPILE_FLAGS} DEBUG_POSTFIX _d)
    add_executable(${PATTERN} src/${PATTERN}/${PATTERN}_main.cpp)
    target_link_libraries(${PATTERN} ${MZLIB}${PATTERN})
endforeach(PATTERN ${MZ_PATTERNS})

include_directories(inc)

add_custom_target(debug ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE:String=Debug ${PROJECT_SOURCE_DIR})
add_custom_target(release ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE:String=Release ${PROJECT_SOURCE_DIR})