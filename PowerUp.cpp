#include "PowerUp.h"
#include "Colisionable.h"
#include <stdlib.h>

PowerUp::PowerUp() :
    texturePower("powerUp.png"),
    spritePower(texturePower)
{
    // Cargar la textura
    if (!texturePower.loadFromFile("powerUp.png")) {
        // Manejar el error de carga de la textura
        throw std::runtime_error("No se pudo cargar la textura");
    }

    // Asignar la textura al sprite
    spritePower.setTexture(texturePower);
    velocityCoin = 4;
}

void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(spritePower, states);
}

void PowerUp::update() {

}

void PowerUp::respanw() {

    float x = std::rand() % 700 + spritePower.getGlobalBounds().size.x;
    float y = std::rand() % 500 + spritePower.getGlobalBounds().size.y;
    spritePower.setPosition(sf::Vector2f(x, y));
}

sf::FloatRect PowerUp::getBounds() const {
    return spritePower.getGlobalBounds();
}

void PowerUp::NoSaleDeLaPantallaPower() {
    /*Rebotar: si el if es verdadero, le invierto la velocity segun el eje x o y y a esa velocidad le puedo aumentar la velocidad con cada choque
    velocity.x= -velocity.x*2 (aumenta en dos la velocidad)
    */
    sf::Vector2f spriteSize = spritePower.getGlobalBounds().size;

    if (spritePower.getPosition().x < 0) {

        spritePower.setPosition({ 0,spritePower.getPosition().y });

    }
    if (spritePower.getPosition().y < 0) {

        spritePower.setPosition({ spritePower.getPosition().x,0 });
    }

    if (spritePower.getPosition().x + spriteSize.x > 600) {
        spritePower.setPosition({ 600 - spriteSize.x, spritePower.getPosition().y });
    }
    if (spritePower.getPosition().y + spriteSize.y > 800) {
        spritePower.setPosition({ spritePower.getPosition().x,800 - spriteSize.y });
    }

}