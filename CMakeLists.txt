cmake_minimum_required(VERSION 3.29)
project(
  GameBoy
  VERSION 0.1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_GENERATOR STREQUAL "Unix Makefiles")
    message(FATAL_ERROR "This project requires Unix Makefiles. 
      Please run cmake with -G 'Unix Makefiles'.")
endif()

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(BINDATA ${BIN_DIR}/data)

file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

add_executable(main ${SOURCES})

set_target_properties(main PROPERTIES 
  RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

target_include_directories(
  main PRIVATE
    src/core 
    src/graphics 
    src/utility
    C:/Programs/raylib/include
)

target_link_libraries(main PRIVATE -LC:/Programs/raylib/lib -lraylibdll)

target_compile_options(
  main PRIVATE
    -Wall 
    -Wextra 
    -Wpedantic 
    -Wconversion
)

# install(TARGETS main DESTINATION ${BIN_DIR})

add_custom_target(
  run
  COMMAND ${BIN_DIR}/main ${BINDATA}/GameBoyDev.gb ${BINDATA}/tileset.gb ${BINDATA}/level.tilemap
  DEPENDS main
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_custom_target(
  clean-all
  COMMAND ${CMAKE_COMMAND} -E rm -rf ${BUILD_DIR}
  COMMENT "Cleaning build artifacts"
)

#[[
Helpful commands:
cmake -S . -B build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target run -- -j 8
cmake --build build --target clean-all
cmake --build build --target install
]]
