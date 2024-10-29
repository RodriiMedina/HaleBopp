#pragma once


#include "SFML\Graphics.hpp"
#include "Director.h"
#include "Level.h"

#include <iostream>

class Final :public sf::Drawable, public Level
{

public:

	Final(int muertes, int puntos, const sf::String& perfil);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();

private:

	sf::Sprite _image;
	sf::Texture _texture;
	sf::Font font;


	Datos datos;

	sf::Text _cartelSalir;
	sf::Text _cartelVolver;

	sf::Text textVida;
	sf::Text textMuerte;
	sf::Text textPuntos;

	int puntosFinal;
	int muertesFinal;
	sf::String perfilFinal;

	sf::Clock RelojTecla;
	const sf::Time Cooldown = sf::milliseconds(200);

};