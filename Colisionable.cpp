#include "Colisionable.h"
#include <SFML/Graphics/Rect.hpp>

bool Collisionable::isCollision(Collisionable& obj) const {
	return (bool) getBounds().findIntersection(obj.getBounds());
}