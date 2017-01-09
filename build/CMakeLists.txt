cmake_minimum_required (VERSION 2.6)

set (PROJECT mysql-fast-search)

set (HEADERS 
	../includes/counter.h)

set (SOURCES 
	../sources/counter.cpp 
	../sources/main.cpp)

set (LIBRARIES
	calculator
	generator
	mysql-accessor
	users-controller)

set (BOOST_COMPONENTS
	system 
	thread
	date_time)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set (Boost_USE_STATIC_LIBS ON)

set (Boost_USE_MULTITHREADED ON)

project (${PROJECT})

include_directories (../)

find_package (Threads)

find_package (Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

foreach (LIBRARY ${LIBRARIES})
	add_subdirectory (../${LIBRARY}/build bin/${LIBRARY})
endforeach ()

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${PROJECT} ${HEADERS} ${SOURCES})

target_link_libraries (${PROJECT} ${LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})

enable_testing ()
