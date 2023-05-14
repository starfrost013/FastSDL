#pragma once

#include "RenderObject.h"


void RenderObject::Draw()
{
	for (int n = 0; n < components.size(); n++)
	{
		Component component = components[n];
		component.Draw();
	}
}

void RenderObject::AddComponent(Component component)
{
	// FIGURE OUT IF THIS IS A GOOD IDEA
	if (components.size() == components.max_size())
	{
		components.resize(components.size() + 1);
	}

	components.push_back(component);
}

void RenderObject::UpdateComponents()
{
	for (int n = 0; n < components.size(); n++)
	{
		Component component = components[n];
		component.Update();
	}
}

void RenderObject::DestroyComponents()
{
	for (int n = 0; n < components.size(); n++)
	{
		Component component = components[n];
		component.Destroy();
	}
}