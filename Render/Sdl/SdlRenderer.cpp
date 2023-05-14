#pragma once
#include "SdlRenderer.h"

// idk why this is not here
// shrink final package size by 800 KB.
#define IMG_INIT_ALL_SUPPORTED IMG_INIT_JPG | IMG_INIT_PNG 
#define MIX_INIT_EVERYTHING MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_OPUS

bool SdlRenderer::Init()
{
	std::cout << "Initialising SDL Renderer" << std::endl;

	std::cout << "Initialising SDL" << std::endl;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to start SDL: " << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Initialising SDL_image" << std::endl;

	// SDL_image returns currently initialised flags.
	if (IMG_Init(IMG_INIT_ALL_SUPPORTED) == 0) 
	{
		std::cout << "Failed to start SDL_image: " << IMG_GetError() << std::endl;
		exit(EXIT_FAILURE + 1);
	}

	std::cout << "Initialising SDL_mixer" << std::endl;

	if (Mix_Init(MIX_INIT_EVERYTHING) == 0)
	{
		std::cout << "Failed to start SDL_mixer: " << IMG_GetError() << std::endl;
		exit(EXIT_FAILURE + 2);
	}

	std::cout << "Creating window and renderer" << std::endl;

	// make up some values for now
	memset(&settings, 0x00, sizeof RendererSettings);

	settings.x = 960;
	settings.y = 640;
	settings.posX = 100;
	settings.posY = 100;
	settings.flags = SDL_WindowFlags::SDL_WINDOW_SHOWN;
	settings.renderFlags = (SDL_RendererFlags)0; // defaults to SDL_RenderFlags::SDL_

	if (SDL_CreateWindowAndRenderer(settings.x, settings.y, settings.flags, &window, &renderer) != 0)
	{
		std::cout << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
	}

	isRunning = true; 

	return true; 
}

bool SdlRenderer::Update()
{
	return isRunning;
}

void SdlRenderer::Render()
{
	
	switch (renderState)
	{
		case RendererState::Start:
		case RendererState::Backdrop:
		case RendererState::RenderObjects:
		case RendererState::PostProcessing:
		case RendererState::Present:
			break;
	}
}

void SdlRenderer::DoBackdrop()
{

}

void SdlRenderer::DoRenderObjects()
{

}

void SdlRenderer::DoPostProcessing()
{

}

void SdlRenderer::DoPresent()
{

}

void SdlRenderer::Shutdown()
{

}