#pragma once
#include <SFML/Graphics/Rect.hpp>


class Collisionable {
public:
	//no existe la implementacion en esta clase, sino que espera que quien herede el metodo lo utilice
	virtual sf::FloatRect getBounds() const= 0; 
	bool isCollision(Collisionable& col) const;
};