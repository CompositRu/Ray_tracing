#include "Sphere.h"


Sphere::Sphere(int n, Vec3f c, float r, sf::Color col, Specular s, float reflect, float transp = 0) :
	center(c), radius(r), Rended_object(n, col, s, reflect, transp)
{
}

bool Sphere::Intersection(Vec3f pos, Vec3f dir, float & t, Vec3f& normal)
{
	float a = (dir % dir);
	float half_b = (dir % (pos - center));
	float c = (pos - center) % (pos - center) - radius * radius;

	float D1 = half_b * half_b - a * c;

	if (D1 < 0) return false;
	/*if (D1 == 0) {
		t = -half_b / a;
		normal = pos + t * dir;
		return t;
	}*/
	//normal = pos + t * dir;
	t = (-half_b - sqrt(D1)) / a;
	return t;
}

Vec3f Sphere::Get_normal(Vec3f point)
{
	return point - center;
}
