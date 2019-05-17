#include "Prism.h"


Prism::Prism(int n, Vec3f p, Vec3f v1, Vec3f v2, Vec3f v3, float m1, float m2, float m3, sf::Color col, Specular s, float reflect, float transp) :
	pos(p), vec1(v1), vec2(v2), vec3(v3), max1(m1), max2(m2), max3(m3), Rended_object(n, col, s, reflect, transp)
{
}

Prism::~Prism()
{
}

bool Prism::Intersection(Vec3f camera_pos, Vec3f dir, float & t, Vec3f & normal)
{
	bool flag = true;
	//тут ещё минимальный t надо определить
	//а потом запомнить плоскость
	flag = flag && Intersect_plane(camera_pos, dir, pos, vec1, vec2, max1, max2, t);
	flag = flag && Intersect_plane(camera_pos, dir, pos, vec1, vec3, max1, max3, t);
	flag = flag && Intersect_plane(camera_pos, dir, pos, vec2, vec3, max2, max3, t);

	flag = flag && Intersect_plane(camera_pos, dir, pos + vec1 + vec2 + vec3,   
									-vec1, -vec2, max1, max2, t);
	flag = flag && Intersect_plane(camera_pos, dir, pos + vec1 + vec2 + vec3,
									-vec1, -vec3, max1, max3, t);
	flag = flag && Intersect_plane(camera_pos, dir, pos + vec1 + vec2 + vec3,
									-vec2, -vec3, max2, max3, t);
	return flag;
}

Vec3f Prism::Get_normal(Vec3f point)
{
	return Vec3f();
}

bool Intersect_plane(Vec3f pos, Vec3f dir, Vec3f plane_corner, 
						Vec3f v1, Vec3f v2, float max1, float max2, float & t) {
	Vec3f answer;
	bool flag = Solve_linear_system(dir, v1, v2, plane_corner - pos, answer);
	if (flag) {
		t = answer[0];
		return (answer[1] >= 0) && (answer[1] <= max1) &&
			(answer[2] >= 0) && (answer[2] <= max2);
	}
	return false;
}

bool Solve_linear_system(Vec3f a, Vec3f b, Vec3f c, Vec3f d, Vec3f& answer) {
	float det = Det3d(a, b, c);
	if (det == 0) return false;

	float det1 = Det3d(d, b, c);
	float det2 = Det3d(a, d, c);
	float det3 = Det3d(a, b, d);

	answer = Vec3f(det1 / det, det2 / det, det3 / det);
	return true;
}

float Det3d(Vec3f a, Vec3f b, Vec3f c) {
	return a[1] * Det2d(b[2], b[3], c[2], c[3]) -
			b[1] * Det2d(a[2], a[3], c[2], c[3]) +
			c[1] * Det2d(a[2], a[3], b[2], b[3]);
}

float Det2d(float f11, float f21, float f12, float f22) {
	return f11 * f22 - f12 * f21;
}