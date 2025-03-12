#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<ctime>
#include<stdlib.h>
#include "Player.h"
#include "Coin.h"


int main()
{
    std::srand((unsigned)std::time(0));

    sf::RenderWindow window(sf::VideoMode({ 600, 800 }), "Prueba");
    window.setFramerateLimit(60);

    sf::Font fontNumeric("PWSmokey.ttf");
    // Throws sf::Exception if an error occurs
    
    sf::Text text(fontNumeric);
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::Yellow);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    int puntos = 0;

    Player playerUno;
    Coin Moneda;

    Moneda.respanw();
   

    // READINPUT ACTUALIZAR LOS PERIFERICOS
    // 
    // LEER LA COLA DE MENSAJES
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        //CMD - joy EJECUTAR COMANDOS (ARRIBA,ABAJO,ETC)
        playerUno.Update();
        playerUno.NoSaleDePantalla();
        Moneda.NoSaleDeLaPantallaCoin();

        if (playerUno.isCollision(Moneda)) {
            Moneda.respanw();
            puntos++;

        }

        text.setString("Puntos"+std::to_string(puntos));

        //Update -- Actualiza los estados del juego
        window.clear();
       
        //Draw
        window.draw(playerUno);
        window.draw(Moneda);
        window.draw(text);

        //Display - Flip
        window.display();
        
    } 
    //Liberacion del juego 

    return 0;
}