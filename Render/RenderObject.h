#pragma once

#include "../FastSDL.h"
#include "Component.h"

class RenderObject
{
public:
	virtual void Create() = 0;
	void Draw();
	virtual void Update() = 0;
	virtual void Destroy() = 0;

	void AddComponent(Component component);

	void UpdateComponents();
	void DestroyComponents();

	std::vector<Component> components;

	std::vector<Triangle> mesh;

	Vector3 size;

	RenderObject()
	{
		components.reserve(12);
	}
};