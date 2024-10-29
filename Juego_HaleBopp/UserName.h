#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "SFML/Audio.hpp"
#include "Level.h"
#include "ArchivoPartidas.h"
#include "Director.h"


class UserName : public sf::Drawable, public Level
{
public:

	UserName();

	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Text caseUser;
	sf::String userName;
	sf::Event event;
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Font font;
	Datos datos;
	Level level;
	ArchivoPartidas archi;

	sf::Clock RelojTecla;
	sf::Time debounceTime = sf::milliseconds(100);

	Director& director = Director::getInstance();

};

