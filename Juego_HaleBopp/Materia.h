#pragma once
#include "SFML\Graphics.hpp"
#include "Collisionable.h"
#include <iostream>

class Materia : public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;

public:
	Materia(int pos1, int pos2);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Sprite getSprite() const;
	sf::FloatRect getBounds() const override;
};

