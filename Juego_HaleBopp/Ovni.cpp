#include "Ovni.h"

Ovni::Ovni(int pos1, int pos2)
{
    _movement = { 10,10 };
    if(!_texture.loadFromFile("ovni.png")) {
    std::cout << "la imagen del ovni, no fue cargada correctamente" << std::endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(pos1, pos2);
}

void Ovni::setMoveY()
{
    _movement.y = -_movement.y;
}

void Ovni::setMoveX()
{
    _movement.x = -_movement.x;
}

void Ovni::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::Sprite Ovni::getSprite() const
{
    return _sprite;
}

sf::FloatRect Ovni::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Ovni::update()
{
    _sprite.move(_movement.x, _movement.y);

}
