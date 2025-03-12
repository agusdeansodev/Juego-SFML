#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Coin:public sf::Drawable, public Collisionable
{
public:	
	
	Coin();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();
	void respanw();
	sf::FloatRect getBounds() const override;
	void NoSaleDeLaPantallaCoin();

private:
	sf::Texture textureCoin;
	sf::Sprite spriteCoin;
	float velocityCoin;
	int valor;
	
};
