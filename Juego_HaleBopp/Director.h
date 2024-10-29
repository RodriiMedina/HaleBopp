#pragma once
#include "SFML/Graphics.hpp"
#include "Level.h"
#include "Personaje.h"
#include "Menu.h"
#include "Jugadores.h"
#include "Datos.h"


class Director : public sf::Drawable
{
private:
	Director();
	static Director* _pDirector;

private:
	Level* _pCurrentLevel, level;
	Datos datos;
	int muertes, puntos;
	sf::String perfil;
public:
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update();
	static Director &getInstance();
	void changeLevel(int number, int m, int p, const sf::String& perfil);

};

