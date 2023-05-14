#pragma once 

struct Color4
{
	float a;
	float r;
	float g;
	float b;

private: 
	Color4(float initialA,
		float initialR,
		float initialG,
		float initialB)
	{
		a = initialA;
		r = initialR;
		g = initialG;
		b = initialB;
	}
};