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
#include "Ovni.h"
#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

class Level4 : public Level
{
private:
	sf::Sprite _image;
	sf::Texture _texture;
	Personaje haleBopp;
	Portal portal{ 100,900 };
	Limite limite1{ 3000,50,0,400 }, limite2{ 300,50,1700,400 }, limite3{ 300,50,0,500 }, limite4{ 1600,50,1000,500 };
	Limite limiteSup{ 5000,1,1,1 }, limiteInf{ 5000,1,1,999 }, limiteDer{ 1,5000,1799,1 }, limiteIzq{ 1,5000,1,1 };
	Asteriode asteroide1{ 100,100 }, asteroide2{ 400,100 }, asteroide3{ 100,800 }, asteroide4{ 400,900 };
	Planeta planeta1{ 65, 1525, 250 }, planeta2{ 65, 1650, 100 }, planeta3{ 65, 175, 645 }, planeta4{ 65,1680,880 };
	Materia materia1{ 1750, 30 }, materia2{ 1600, 700 }, materia3{ 1755, 960 }, materia4{ 1680, 450 };
	Datos datos;
	Astronauta astronauta1{ 500,451,5,0 };
	Satelite satelite1{ 1600, 700 }, satelite2{ 1680,450 };
	Ovni ovni1{ 200,100 }, ovni2{ 200,800 };

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
	Level4(int muertes, int puntos, const sf::String& perfil);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update();

	bool veloLuz = true;
	int timer = 0;
	int timer2 = 0;
	bool flagMateria1 = true, flagMateria2 = true, flagMateria3 = true, flagMateria4 = true;
	int puntos = 0;
	int puntosLevel4;
	int muertesLevel4;
	std::string perfilLevel4;

	void musica();
	void impacto();
	void pickMateria();
	void powerActivo();
	void powerListo();
};

