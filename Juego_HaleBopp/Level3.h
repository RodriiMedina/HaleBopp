#pragma once

#include "Level.h"
#include "Personaje.h"
#include "Portal.h"
#include "Limite.h"
#include "Asteroide.h"
#include "Astronauta.h"
#include "Planeta.h"
#include "Materia.h"
#include "Director.h"
#include "Satelite.h"
#include "ArchivoPartidas.h"
#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

class Level3 : public Level
{
private:
	sf::Sprite _image;
	sf::Texture _texture;
	Personaje haleBopp;
	Portal portal{ 1700,100 };
	Limite limite1{ 10,1500,300,0 }, limite2{ 10,1500,700,1000 }, limite3{ 10,1500,1100,1000 }, limite4{ 10,1500,1500,0 };
	Limite limiteSup{ 5000,1,1,1 }, limiteInf{ 5000,1,1,999 }, limiteDer{ 1,5000,1799,1 }, limiteIzq{ 1,5000,1,1 };
	Asteriode asteroide1{ 100,500 }, asteroide2{ 400,500 }, asteroide3{ 1200,500 }, asteroide4{ 1700,500 };
	Planeta planeta1{ 65, 300, 750 }, planeta2{ 65, 700, 250 }, planeta3{ 65, 1100, 250 }, planeta4{ 65,1500,750 };
	Materia materia1{ 500, 500 }, materia2{ 900, 500 }, materia3{ 1300, 500 }, materia4{ 900, 800 };
	Datos datos;
	Astronauta astronauta1{ 500,100,5,0 };
	Satelite satelite1{ 900,800 }, satelite2{ 900,500 };
	ArchivoPartidas archipart;


	sf::SoundBuffer _buffer;
	sf::SoundBuffer _buffer2;
	sf::SoundBuffer _buffer3;
	sf::SoundBuffer _buffer4;
	sf::Sound _sound;
	sf::Sound _sound2;
	sf::Sound _sound3;
	sf::Sound _sound4;

	Director& director = Director::getInstance();


public:
	Level3(int muertes, int puntos, const sf::String& perfil);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update();

	bool veloLuz = true;
	int timer = 0;
	int timer2 = 0;
	bool flagMateria1 = true, flagMateria2 = true, flagMateria3 = true, flagMateria4 = true;
	int puntos = 0;
	int puntosLevel3;
	int muertesLevel3;
	sf::String perfilLevel3;

	void musica();
	void impacto();
	void pickMateria();
	void powerActivo();
	void powerListo();
};

