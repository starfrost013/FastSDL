// FastSDL.cpp : Defines the entry point for the application.
//

#include "FastSDL.h"
#include "Render/Sdl/SdlRenderer.h"

int main()
{
	std::cout << FASTSDL_VERSION_STRING << std::endl;

	SdlRenderer sRender;

	sRender.Init();

	while (sRender.Update())
	{
		sRender.Render();
	}
	return 0;
}
