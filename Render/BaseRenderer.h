#pragma once
#include "../FastSDL.h"
#include "RendererState.h"
#include "RendererSettings.h"

class BaseRenderer
{
public:
	virtual bool Init() = 0;
	virtual bool Update() = 0;
	virtual void Render() = 0;
	virtual void Shutdown() = 0;
	RendererSettings settings;

protected:
	RendererState renderState = RendererState::Init;

	bool isRunning = false;
private:
	// Specific phases of rendering
	virtual void DoBackdrop() = 0;
	virtual void DoRenderObjects() = 0;
	virtual void DoPostProcessing() = 0;
	virtual void DoPresent() = 0;
};