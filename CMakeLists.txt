cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE $ENV{EMSDK}/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake)
set(CMAKE_BUILD_TYPE Debug)
project(app-proj C)



if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(SHELL_FILE ${CMAKE_SOURCE_DIR}/src/shell_dbg.html)
else()
  set(SHELL_FILE ${CMAKE_SOURCE_DIR}/src/shell_run.html)
endif()

# EMSCRIPTEN #
if (EMSCRIPTEN)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1 --shell-file ${SHELL_FILE}")
  set(CMAKE_EXECUTABLE_SUFFIX ".html") # This line is used to set your executable to build with the emscripten html template so that you can directly open it.
endif ()

# RAYLIB #
add_subdirectory(ext/raylib)


file(GLOB_RECURSE SOURCES src/*.h src/*.c)
add_executable(app ${SOURCES})

target_include_directories(app PRIVATE ext/raygui/src)
target_link_libraries(app raylib)