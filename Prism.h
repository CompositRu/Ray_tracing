#pragma once
#include "Rended_object.h"

class Prism :
	public Rended_object
{
public:
	Vec3f pos;
	Vec3f vec1;
	Vec3f vec2;
	Vec3f vec3;
	float max1;
	float max2;
	float max3;

	Prism(int n, Vec3f p, Vec3f v1, Vec3f v2, Vec3f v3, float m1, float m2, float m3, 
		sf::Color col, Specular s, float reflect, float transp);
	~Prism();

	bool Intersection(Vec3f pos, Vec3f dir, float& t, Vec3f & normal) override;
	Vec3f Get_normal(Vec3f point);
};

bool Intersect_plane(Vec3f pos, Vec3f dir, Vec3f plane_corner,
	Vec3f v1, Vec3f v2, float max1, float max2, float & t);
bool Solve_linear_system(Vec3f a, Vec3f b, Vec3f c, Vec3f d, Vec3f& answer);
float Det3d(Vec3f a, Vec3f b, Vec3f c);
float Det2d(float f11, float f21, float f12, float f22);

