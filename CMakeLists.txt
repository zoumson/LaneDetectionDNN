#cmake_minimum_required(VERSION 3.0.0)
#project(classify VERSION 0.1.0)

#include(CTest)
#enable_testing()


#find_package(OpenCV REQUIRED)
#find_package(Threads REQUIRED)

#add_executable(classify classify.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX__STANDARD_REQUIRED ON)

#include_directories(${OpenCV_INCLUDE_DIRS})
#target_link_libraries(classify ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_CXX_STANDARD 17)

#Set the executable name
set(EXE main)

project (${EXE})

#Bring the custom libraries
link_directories( lib)


#Bring the headers
include_directories(include)

#Bring the sources
file(GLOB SOURCES "src/*.cpp")

#Add opencv cmake .config path
set (OpenCV_DIR opt/opencv/release)


find_package(Threads REQUIRED)

#Find opencv libs
find_package(OpenCV REQUIRED)

#Build the executable
add_executable(${EXE} ${SOURCES})
#set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
#set(THREADS_PREFER_PTHREAD_FLAG TRUE)
#Link the libraries 
target_link_libraries(${EXE} ${OpenCV_LIBS} Threads::Threads)

