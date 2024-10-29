#pragma once
#include "SFML\Graphics.hpp"
#include "Collisionable.h"
#include "ctime"
#include "stdlib.h"
#include <iostream>
class Satelite : public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _movement;
	sf::Vector2f _center;

public:
	Satelite(int pos1, int pos2);
	void setMoveY();
	void setMoveX();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Sprite getSprite() const;
	sf::FloatRect getBounds() const override;

	float radius = 100.0f;
	float angle = 0.1f; 
	float angularSpeed = 0.07f;
	float x, y;

};

