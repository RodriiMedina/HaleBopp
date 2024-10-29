#include "Materia.h"

Materia::Materia(int pos1, int pos2)
{
    if(!_texture.loadFromFile("materia.png")) {
    std::cout << "la imagen de la materia, no fue cargada correctamente" << std::endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(pos1, pos2);
}

void Materia::update()
{
}

void Materia::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::Sprite Materia::getSprite() const
{
    return _sprite;
}

sf::FloatRect Materia::getBounds() const
{
    return _sprite.getGlobalBounds();
}



