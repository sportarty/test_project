cmake_minimum_required ( VERSION 3.2.2 )

set( PROJECT test_project )

set ( CMAKE_CXX_STANDARD 14 )

set ( CMAKE_CXX_STANDARD_REQUIRED on )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++" )

SET( FLAG_DEBUG "Debug" )

if( "${CMAKE_BUILD_TYPE}" STREQUAL "${FLAG_DEBUG}" )
    SET( CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "postfix applied to debug build of libraries" )
    SET( CMAKE_CXX_FLAGS_DEBUG "-O0 -g" )
    add_definitions( -D_DEBUG )
else()
    SET( CMAKE_RELEASE_POSTFIX "" CACHE STRING "postfix applied to release build of libraries" )
    SET( CMAKE_CXX_FLAGS_RELEASE "-O3 -g" )
endif()

#путь к исполнеямым файлам
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin )

project( ${PROJECT} )

find_package( Threads )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

set(HEADERS inc/endpoint.h
            inc/endpoint_ipv4.h
            inc/master_connection.h
            inc/slave_connection.h
            inc/tcp_slave_connection.h
            inc/tcp_master_connection.h
            inc/types.h
            )

aux_source_directory( src TEST_PROJECT_SRC )

add_executable( ${PROJECT} ${TEST_PROJECT_SRC} ${HEADERS})

target_link_libraries( ${PROJECT} pthread )
