#include "Rended_object.h"

Rended_object::Rended_object(int n, sf::Color col, Specular s, float reflect, float transp = 0) 
				: name(n), color(col), specular(s.val), reflection(reflect), transparent(transp) {};