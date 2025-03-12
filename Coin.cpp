#include "Coin.h"
#include "Colisionable.h"
#include <stdlib.h>

Coin::Coin():
    textureCoin("Coin.png"),
    spriteCoin(textureCoin)
{
    // Cargar la textura
    if (!textureCoin.loadFromFile("Coin.png")) {
        // Manejar el error de carga de la textura
        throw std::runtime_error("No se pudo cargar la textura");
    }

    // Asignar la textura al sprite
    spriteCoin.setTexture(textureCoin);
    velocityCoin = 4;
}

void Coin::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(spriteCoin, states);
}

void Coin::update() {

}

void Coin::respanw() {
    
        float x = std::rand() % 700 + spriteCoin.getGlobalBounds().size.x;
        float y = std::rand() % 500 + spriteCoin.getGlobalBounds().size.y;
        spriteCoin.setPosition(sf::Vector2f(x, y));
    }

sf::FloatRect Coin::getBounds() const {
    return spriteCoin.getGlobalBounds();
}

void Coin::NoSaleDeLaPantallaCoin() {
    /*Rebotar: si el if es verdadero, le invierto la velocity segun el eje x o y y a esa velocidad le puedo aumentar la velocidad con cada choque
    velocity.x= -velocity.x*2 (aumenta en dos la velocidad)
    */
    sf::Vector2f spriteSize = spriteCoin.getGlobalBounds().size;

    if (spriteCoin.getPosition().x < 0) {
        
        spriteCoin.setPosition({ 0,spriteCoin.getPosition().y});

    }
    if (spriteCoin.getPosition().y < 0) {
        
        spriteCoin.setPosition({ spriteCoin.getPosition().x,0 });
    }
    
    if (spriteCoin.getPosition().x + spriteSize.x > 600) {
        spriteCoin.setPosition({ 600 - spriteSize.x, spriteCoin.getPosition().y});
    }
    if (spriteCoin.getPosition().y + spriteSize.y > 800) {
        spriteCoin.setPosition({ spriteCoin.getPosition().x,800 - spriteSize.y});
    }   

}
