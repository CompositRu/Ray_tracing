#pragma once

#include "Vec.h"

struct Specular {
	int val;
	explicit Specular(int value) : val(value) {}
};

class Rended_object
{
public:
	Rended_object(int n, sf::Color col, Specular s, float reflect, float transp);
	virtual bool Intersection(Vec3f pos, Vec3f dir, float& t, Vec3f & normal) = 0;
	virtual Vec3f Get_normal(Vec3f point) = 0;
	virtual ~Rended_object() {};

	int name;
	sf::Color color;
	Specular specular;//блики света
	float reflection;//отражение
	float transparent;
};
