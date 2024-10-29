#include "Astronauta.h"
#include <iostream>

Astronauta::Astronauta(int pos1, int pos2, int x, int y)
{
    _movement.x = x;
    _movement.y = y;
    if (!_texture.loadFromFile("astronauta.png")) {
        std::cout << "No se pudo cargar la imagen del astronauta" << std::endl;
        exit(2);
    }
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(pos1, pos2);
}

void Astronauta::setMoveY()
{
    _movement.y = -_movement.y;
}

void Astronauta::setMoveX()
{
    _movement.x = -_movement.x;
}


void Astronauta::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::Sprite Astronauta::getSprite() const
{
    return _sprite;
}

sf::FloatRect Astronauta::getBounds() const
{
     return _sprite.getGlobalBounds();
}




void Astronauta::update()
{

    _sprite.move(_movement.x, _movement.y);


    if (_sprite.getGlobalBounds().left < 0) {
        _movement.x = -_movement.x;
        _sprite.setRotation(0.f);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _movement.y = -_movement.y;
        _sprite.setRotation(0.f);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 1800) {
        _movement.x = -_movement.x;
        _sprite.setRotation(0.f);
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 1000) {
        _movement.y = -_movement.y;
        _sprite.setRotation(0.f);
    }
}




