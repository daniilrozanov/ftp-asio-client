cmake_minimum_required(VERSION 3.15)
project(
  ftp
  VERSION 0.0.1
  LANGUAGES CXX)

option(FTP_BUILD_TESTS "Enable tests build" OFF)
option(FTP_BUILD_EXAMPLES "Enable examples build" ON)
option(FTP_HEADER_ONLY "Install as header only" ON)

find_package(Boost 1.82.0 REQUIRED COMPONENTS system thread regex context)

add_library(ftp INTERFACE)

add_library(ftp::ftp ALIAS ftp)

target_include_directories(ftp INTERFACE ./include/)

target_link_libraries(ftp INTERFACE Boost::system Boost::thread Boost::context)

set_target_properties(ftp PROPERTIES LINKER_LANGUAGE CXX)

if(FTP_HEADER_ONLY)
  target_compile_definitions(ftp INTERFACE FTP_HEADER_ONLY)
endif()

add_subdirectory(examples)
