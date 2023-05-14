#pragma once

#include "../FastSDL.h"

class Component
{
public: 
	void Create();
	void Draw();
	void Update();
	void Destroy();

protected:
	RenderObject* parent;

};