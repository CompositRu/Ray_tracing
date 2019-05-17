#pragma once
#include "Rended_object.h"

class Sphere :
	public Rended_object
{
public:
	Vec3f center;
	float radius;
	
	Sphere(int n, Vec3f c, float r, sf::Color col, Specular s, float reflect, float transp);

	bool Intersection(Vec3f pos, Vec3f dir, float & t, Vec3f & normal) override;
	Vec3f Get_normal(Vec3f point) override;
};

