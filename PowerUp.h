#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class PowerUp:public sf::Drawable, public Collisionable
{
public:

	PowerUp();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();
	void respanw();
	sf::FloatRect getBounds() const override;
	void NoSaleDeLaPantallaPower();

private:
	sf::Texture texturePower;
	sf::Sprite spritePower;
	float velocityCoin;
	int valor;

};
