#include "Player.h"
#include "Colisionable.h"

Player::Player() :
    texture("rulitos.png"),
    sprite(texture)
{
    // Cargar la textura
    if (!texture.loadFromFile("rulitos.png")) {
        // Manejar el error de carga de la textura
        throw std::runtime_error("No se pudo cargar la textura");
    }

    // Asignar la textura al sprite
    sprite.setTexture(texture);
    velocity = { 4,4 };
    sprite.setOrigin({sprite.getGlobalBounds().size.x/2, 0});
    
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void Player::Update() {

    velocity = { 0,0 };
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        velocity.y = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        velocity.x = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        velocity.y = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        velocity.x = -4;
    }
    sprite.move(velocity);
    //flip horinzontal el scale lo achica hasta que 
    //lo achica tanto que lo da vuelta
    
    sf::Vector2f flip{ 1,1 };
    sf::Vector2f antiFlip{ -1,1 };

    if (velocity.x < 0) {
        
        sprite.setScale(antiFlip);
    }
    else if (velocity.x > 0) {
        
        sprite.setScale(flip);
    }

    //Si quiero que se mueva solo
    //sprite.move(velocity); 
}
void Player::NoSaleDePantalla() {
    /*Rebotar: si el if es verdadero, le invierto la velocity segun el eje x o y y a esa velocidad le puedo aumentar la velocidad con cada choque
    velocity.x= -velocity.x*2 (aumenta en dos la velocidad)
    */
    sf::Vector2f spriteSize = sprite.getGlobalBounds().size;

    if (sprite.getPosition().x < 0) {
        
        sprite.setPosition({ 0,sprite.getPosition().y});

    }
    if (sprite.getPosition().y < 0) {
        
        sprite.setPosition({ sprite.getPosition().x,0 });
    }
    
    if (sprite.getPosition().x + spriteSize.x > 600) {
        sprite.setPosition({ 600 - spriteSize.x, sprite.getPosition().y});
    }
    if (sprite.getPosition().y + spriteSize.y > 800) {
        sprite.setPosition({ sprite.getPosition().x,800 - spriteSize.y});
    }   

}

void Player::addVelocity(float aumentoVel) {
    velocity += {aumentoVel,aumentoVel};
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}
