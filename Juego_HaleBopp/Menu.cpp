#include "Menu.h"
#include "Director.h"
#include "Personaje.h"
#include <iostream>

Menu::Menu()
{
    musica();
    if(!font.loadFromFile("Roboto-Black.ttf")) {
        std::cout << "No se pudo cargar la fuente del Menu"<<std::endl;
        exit(1);
    }

    if (!_texture.loadFromFile("fondomenu.png")) {
        std::cout << "No se pudo cargar la imagen del Menu" << std::endl;
        exit(2);
    }
    _image.setTexture(_texture);

    const char* options[Opciones_Menu] = { "Jugar", "Controles", "Salir" };

    for (int i = 0; i < Opciones_Menu; ++i) {
        menuTexts[i].setFont(font);
        menuTexts[i].setFillColor(i == Seleccionador ? sf::Color::Red : sf::Color::White);
        menuTexts[i].setString(options[i]);
        menuTexts[i].setPosition(sf::Vector2f(100, 1000 / (Opciones_Menu + 1) * (i + 1)));
    }
    
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_image, states);

    for (int i = 0; i < Opciones_Menu; ++i) {
        target.draw(menuTexts[i], states);
    }
}

void Menu::MoverArriba()
{
    if (Seleccionador - 1 >= 0) {
        menuTexts[Seleccionador].setFillColor(sf::Color::White);
        Seleccionador--;
        menuTexts[Seleccionador].setFillColor(sf::Color::Red);
    }
}

void Menu::MoverAbajo()
{
    if (Seleccionador + 1 < Opciones_Menu) {
        menuTexts[Seleccionador].setFillColor(sf::Color::White);
        Seleccionador++;
        menuTexts[Seleccionador].setFillColor(sf::Color::Red);
    }
}

int Menu::OpcionSeleccionada() const
{
    return Seleccionador;
}

void Menu::update()
{
    if (sf::Event::KeyPressed) {
        if (RelojTecla.getElapsedTime() >= Cooldown) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                RelojTecla.restart();
                MoverArriba();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                RelojTecla.restart();
                MoverAbajo();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                int selectedIndex = OpcionSeleccionada();
                if (selectedIndex == 0) {
                    Director::getInstance().changeLevel(5,muertesMenu,puntosMenu, perfilMenu);
                }
                else if (selectedIndex == 1) {
                    Director::getInstance().changeLevel(11, 0,0 , "");
                }
                else if (selectedIndex == 2) {
                    exit(1);
                }

            }
        }

    }
}

void Menu::musica()
{
    if (!_buffer.loadFromFile("menu.wav")) {
        std::cout << "No se pudo cargar la musica del menu" << std::endl;
        exit(3);
    }
    _sound.setBuffer(_buffer);
    //_sound.play();
}
