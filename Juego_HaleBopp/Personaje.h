#pragma once
#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Collisionable.h"
#include "ctime"
#include "stdlib.h"
#include "Datos.h"
#include <iostream>

class Personaje : public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _movement;

	sf::SoundBuffer _buffer5;
	sf::Sound _sound5;

public:
	Personaje();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn();
	void power();
	void impacto();
	int getMoveX();
	int getMoveY();
	sf::Sprite getSprite() const;
	sf::FloatRect getBounds() const override;
};
