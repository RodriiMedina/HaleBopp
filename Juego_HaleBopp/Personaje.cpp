#include "Personaje.h"
#include "SFML\Graphics.hpp"
#include "Collisionable.h"


Personaje::Personaje()
{
    _movement = { 0,0 };
   if(! _texture.loadFromFile("HaleBoppChikito.png")) {
       std::cout << "la imagen del personaje, no se pudo cargar correctamente" << std::endl;
   }
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(50, 100);
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void Personaje::respawn()
{
    _sprite.setPosition(50, 100);
    _movement.x = 0;
    _movement.y = 0;
    _sprite.setRotation(0.f);
}

void Personaje::power()
{
    _movement.y = _movement.y * 2;
    _movement.x = _movement.x * 2;
}

void Personaje::impacto()
{
    _buffer5.loadFromFile("impacto.wav");
    _sound5.setBuffer(_buffer5);
    _sound5.play();
}

int Personaje::getMoveX()
{
    return _movement.x;
}

int Personaje::getMoveY()
{
    return _movement.y;
}


sf::Sprite Personaje::getSprite() const
{
    { return _sprite; }
}

sf::FloatRect Personaje::getBounds() const
{
    return _sprite.getGlobalBounds();
}


void Personaje::update()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _movement.y = -10;
        _movement.x = 0;
        _sprite.setRotation(270.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _movement.x = -10;
        _movement.y = 0;
        _sprite.setRotation(180.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _movement.y = 10;
        _movement.x = 0;
        _sprite.setRotation(90.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _movement.x = 10;
        _movement.y = 0;
        _sprite.setRotation(0.f);
    }

    _sprite.move(_movement.x, _movement.y);

}

