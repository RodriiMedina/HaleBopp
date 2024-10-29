#include "Satelite.h"

Satelite::Satelite(int pos1, int pos2)
{

    if(!_texture.loadFromFile("satelite.png")) {
        std::cout << "la imagen del satelite, no fue cargada correctamente" << std::endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);

    _center.x = pos1;
    _center.y = pos2;

}

void Satelite::setMoveY()
{
    _movement.y = -_movement.y;
}

void Satelite::setMoveX()
{
    _movement.x = -_movement.x;
}


void Satelite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::Sprite Satelite::getSprite() const
{
    return _sprite;
}

sf::FloatRect Satelite::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Satelite::update()
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

    angle += angularSpeed;

    x = _center.x + radius * cos(angle);
    y = _center.y + radius * sin(angle);
    _sprite.setPosition(x, y);
}
