#pragma once
#include "SFML\Graphics.hpp"
#include "Collisionable.h"
#include "ctime"
#include "stdlib.h"
class Astronauta : public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _movement;

public:
	Astronauta(int pos1, int pos2, int x, int y);
	void setMoveY();
	void setMoveX();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Sprite getSprite() const;
	sf::FloatRect getBounds() const override;

};

