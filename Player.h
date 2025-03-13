#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Player:public sf::Drawable, public Collisionable {
public:
    Player();
    void Update();
    void NoSaleDePantalla();
    void addVelocity(float aumentoVel);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
};

