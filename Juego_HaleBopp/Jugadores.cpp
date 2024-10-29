#include "Jugadores.h"
#include <iostream>

Jugadores::Jugadores()
    {

    if (!font.loadFromFile("Roboto-Black.ttf")) {
        std::cout << "No se pudo cargar la fuente del menu de jugadores" << std::endl;
        exit(1);
    }
    if (!_texture.loadFromFile("fondomenu.png")) {
        std::cout << "No se pudo cargar la imagen del menu de jugadores" << std::endl;
        exit(2);
    }
    _image.setTexture(_texture);


    const char* options[Opciones_Jugadores] = { "Crear Nueva partida", "Cargar partida", "Volver" };

    for (int i = 0; i < Opciones_Jugadores; ++i) {
        menuTexts[i].setFont(font);
        menuTexts[i].setFillColor(i == Seleccionador ? sf::Color::Red : sf::Color::White);
        menuTexts[i].setString(options[i]);
        menuTexts[i].setPosition(sf::Vector2f(100, 1000 / (Opciones_Jugadores + 1) * (i + 1)));
    }
}

void Jugadores::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_image, states);
    for (int i = 0; i < Opciones_Jugadores; ++i) {
        target.draw(menuTexts[i], states);
    }
}





void Jugadores::update()
{
    if (sf::Event::KeyPressed) {
        if (RelojTecla.getElapsedTime() >= Cooldown) {


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                MoverArriba();
                RelojTecla.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                MoverAbajo();
                RelojTecla.restart();
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                int selectedIndex = OpcionSeleccionada();
                if (selectedIndex == 0) {
                    Director::getInstance().changeLevel(10,0,0,"");
                }
                else if (selectedIndex == 1) {
                    Director::getInstance().changeLevel(6, 0, 0, "");

                }
                else if (selectedIndex == 2) {
                    Director::getInstance().changeLevel(0,0, 0, "");
                }
            }
        }
    }
}

void Jugadores::MoverArriba()
{
    if (Seleccionador - 1 >= 0) {
        menuTexts[Seleccionador].setFillColor(sf::Color::White);
        Seleccionador--;
        menuTexts[Seleccionador].setFillColor(sf::Color::Red);
    }
}

void Jugadores::MoverAbajo()
{
    if (Seleccionador + 1 < Opciones_Jugadores) {
        menuTexts[Seleccionador].setFillColor(sf::Color::White);
        Seleccionador++;
        menuTexts[Seleccionador].setFillColor(sf::Color::Red);
    }
}

int Jugadores::OpcionSeleccionada() const
{
    return Seleccionador;
}

