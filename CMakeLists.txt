# CMakeList.txt : CMake project for FastSDL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("FastSDL")

list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SDL")
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SDL_image")
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SDL_mixer")

set(SDL2_DIR, "${PROJECT_SOURCE_DIR}/SDL/cmake")
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED CONFIG REQUIRED COMPONENTS SDL2_image)
find_package(SDL2_mixer REQUIRED CONFIG REQUIRED COMPONENTS SDL2_mixer)

# Add source to this project's executable.
add_executable (FastSDL "FastSDL.cpp" "FastSDL.h")

if (TARGET SDL2::SDL2main)
	target_link_libraries(FastSDL PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(FastSDL PRIVATE SDL2::SDL2)
target_link_libraries(FastSDL PRIVATE SDL2_image::SDL2_image)
target_link_libraries(FastSDL PRIVATE SDL2_mixer::SDL2_mixer)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FastSDL PROPERTY CXX_STANDARD 20)
endif()


# TODO: Add tests and install targets if needed.
