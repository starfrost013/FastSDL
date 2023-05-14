#pragma once
#include "../BaseRenderer.h"

class SdlRenderer : public BaseRenderer
{
public:
	bool Init();
	bool Update();
	void Render();
	void Shutdown();
	SdlRenderer()
	{
		renderState = RendererState::Init;
		window = NULL;
		renderer = NULL;
	}
protected:
	SDL_Window* window; // ptr to SDL window instance
	SDL_Renderer* renderer; // ptr to SDL renderer instance
private:
	// Specific phases of rendering
	void DoBackdrop();
	void DoRenderObjects();
	void DoPostProcessing();
	void DoPresent();

};
