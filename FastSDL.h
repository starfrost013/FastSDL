// FastSDL.h : Include file for standard system include files,
// or project specific include files.

// © 2023 starfrost (2023-04-29)

#pragma once

#include <iostream>
#include <vector>

#include "SDL/include/SDL.h" // SDL
#undef main
#include "SDL_image/include/SDL_image.h" // SDL_image
#include "SDL_mixer/include/SDL_mixer.h" // SDL_mixer

// Core Functionality

#include "Core/Vector2.h" // 2D vector
#include "Core/Vector3.h" // 3D vector
#include "Core/Vector4.h" // 4D vector
#include "Core/Color4.h" // ARGB color
#include "Core/Matrix22.h" // 2D matrix
#include "Core/Matrix33.h" // 3D matrix
#include "Core/Matrix44.h" // 4d matrix

// Build metadata stuff

#define FASTSDL_VERSION "0.1"
#define FASTSDL_VERSION_STRING "FastSDL Version " FASTSDL_VERSION " built " __DATE__ " " __TIME__
// TODO: Reference additional headers your program requires here.