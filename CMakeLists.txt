# CMakeList.txt : CMake project for FastSDL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

message("Building FastSDL...")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("FastSDL")

message("Getting SDL dirs...")

list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SDL")
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SDL_image")
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SDL_mixer")

message("Finding SDL packages...")
set(SDL2_DIR, "${PROJECT_SOURCE_DIR}/SDL/cmake")
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED CONFIG REQUIRED COMPONENTS SDL2_image)
find_package(SDL2_mixer REQUIRED CONFIG REQUIRED COMPONENTS SDL2_mixer)

message("Adding code...")
# Add source to this project's executable.
add_executable (FastSDL "FastSDL.cpp" "FastSDL.h"  "Render/Sdl/SdlRenderer.cpp" "Render/BaseRenderer.h" "Render/Sdl/SdlRenderer.h" "Render/RendererState.h" "Render/RenderObject.cpp" "Render/RenderObject.h" "Core/Vector2.h"  "Render/Component.h" "Core/Color4.h" "Core/Vector3.h" "Core/Matrix33.h" "Core/Matrix22.h" "Core/Vector4.h" "Core/Matrix44.h" "Render/Component.cpp" "Core/Triangle.h")

if (TARGET SDL2::SDL2main)
	target_link_libraries(FastSDL PRIVATE SDL2::SDL2main)
endif()

message("Adding libraries...")
target_link_libraries(FastSDL PRIVATE SDL2::SDL2)
target_link_libraries(FastSDL PRIVATE SDL2_image::SDL2_image)
target_link_libraries(FastSDL PRIVATE SDL2_mixer::SDL2_mixer)

message("Adding postbuild...")
# copy sdl2/sdl2_image/sdl2_mixer to build directories
add_custom_command(
	TARGET FastSDL POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy 
	${PROJECT_SOURCE_DIR}/SDL/lib/x64/SDL2.dll 
	${CMAKE_CURRENT_BINARY_DIR}/SDL2.dll
)

add_custom_command(
	TARGET FastSDL POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy 
	${PROJECT_SOURCE_DIR}/SDL_image/lib/x64/SDL2_image.dll 
	${CMAKE_CURRENT_BINARY_DIR}/SDL2_image.dll
)

add_custom_command(
	TARGET FastSDL POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy 
	${PROJECT_SOURCE_DIR}/SDL_mixer/lib/x64/SDL2_mixer.dll 
	${CMAKE_CURRENT_BINARY_DIR}/SDL2_mixer.dll
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FastSDL PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
