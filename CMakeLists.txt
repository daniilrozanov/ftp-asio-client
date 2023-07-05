cmake_minimum_required(VERSION 3.15)
project(
  ftp
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(FTP_BUILD_TESTS "Enable tests build" OFF)
option(FTP_BUILD_EXAMPLES "Enable examples build" ON)
option(FTP_HEADER_ONLY "Install as header only" ON)

find_package(Boost 1.82.0 REQUIRED COMPONENTS system thread regex context)

add_library(ftp INTERFACE)
add_library(ftp::ftp ALIAS ftp)

target_include_directories(
  ftp INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                $<INSTALL_INTERFACE:include>)

target_compile_features(ftp INTERFACE cxx_std_17)

if(FTP_HEADER_ONLY)
  target_compile_definitions(ftp INTERFACE "FTP_HEADER_ONLY")
  target_sources(ftp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/ftp/impl)
endif()

target_link_libraries(ftp INTERFACE Boost::thread)

set(CMAKE_CXX_EXTENSIONS OFF)

if(FTP_BUILD_TESTS)
  message("Building tests")
  add_subdirectory(tests)
endif()

message(${FTP_BUILD_EXAMPLES})
if(FTP_BUILD_EXAMPLES)
  message("Building examples")
  add_subdirectory(examples)
endif()
