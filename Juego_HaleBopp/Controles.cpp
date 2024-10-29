#include "Controles.h"

Controles::Controles()
{
    if (!font.loadFromFile("Roboto-Black.ttf")) {
        std::cout << "No se pudo cargar la fuente de los controles" << std::endl;
        exit(1);
    }

    //Space Comics.ttf

    if (!_texture.loadFromFile("Tutorial.png")) {
        std::cout << "No se pudo cargar la imagen de los controles" << std::endl;
        exit(2);



    }
    _image.setTexture(_texture);

        _cartelSalir.setFont(font);
        _cartelSalir.setFillColor(sf::Color::Red);
        _cartelSalir.setString("Salir");
        _cartelSalir.setPosition(1530,825);

}

    void Controles::draw(sf::RenderTarget & target, sf::RenderStates states) const 
    {

        target.draw(_image, states);
        target.draw(_cartelSalir, states);
    }

    void Controles::update()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        
            Director::getInstance().changeLevel(0, 0, 0, "");
        }

    }

