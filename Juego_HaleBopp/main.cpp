#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Personaje.h"
#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Director.h"
#include "Portal.h"
#include "Controles.h"
#include <iostream>


int main()
{

    //inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "Hale Bopp");
    window.setFramerateLimit(60);

    Director  &director = Director::getInstance();

    director.changeLevel(0,0,0,"");


    //GameLoop
    while (window.isOpen())
    {
        //Read input
        //Leer la cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                std::cout << "la ventana del juego fue finalizada" << std::endl;
            }
        }


        //UPDATE - Actualiza los estados del juego


        director.update();


        window.clear();

        //Dibujar
        window.draw(director);
             
       
        //Display-Flip
        window.display();


    }
    return 0;
}