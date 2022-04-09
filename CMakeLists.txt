# Version Requirement
cmake_minimum_required(VERSION 3.14)
# Project Name
project(22s_pa03_girvan_newman_cullenwatson)
# Executable
add_executable(22s_pa03_girvan_newman_cullenwatson src/main.cpp src/MyGraph.cpp src/MyGraph.h)
# Configure Files
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# Boost Basic Settings
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
# Finds Boost Packages (Minimum 1.71.0 Requirement, Will Output)
find_package(Boost 1.71.0 REQUIRED COMPONENTS graph system filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")
# Necessary Statement If Cmake Ver < Boost Ver
# if(NOT TARGET Boost::filesystem)
#     add_library(Boost::filesystem IMPORTED INTERFACE)
#     set_property(TARGET Boost::filesystem PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
#     set_property(TARGET Boost::filesystem PROPERTY INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})
# endif()
# Linking Correct Libraries (In Find Package)
target_link_libraries(22s_pa03_girvan_newman_cullenwatson PUBLIC Boost::graph PUBLIC Boost::system PUBLIC Boost::filesystem)
# Other Important Functions
# set(CMAKE_CXX_STANDARD 14)
# configure_file(output/outfile.csv output/outfile.csv COPYONLY)
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})