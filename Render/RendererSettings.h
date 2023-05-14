
#pragma once
#include "../FastSDL.h"

struct RendererSettings
{
	int x, y; // size
	int posX, posY; // position
	SDL_WindowFlags flags;
	SDL_RendererFlags renderFlags;
};