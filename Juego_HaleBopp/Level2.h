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
#include "ArchivoPartidas.h"
#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"

class Level2 : public Level
{
private:
	sf::Sprite _image;
	sf::Texture _texture;
	Personaje haleBopp;
	Portal portal{50,950};
	Limite limite1{ 3200,10,1800,200 }, limite2{ 3200,10,1800,500 }, limite3{ 3200,10,1800,800 };
	Limite limiteSup{ 5000,1,1,1 }, limiteInf{ 5000,1,1,999 }, limiteDer{ 1,5000,1799,1 }, limiteIzq{ 1,5000,1,1 };
	Asteriode asteroide1{ 1500,100 }, asteroide2{ 300,400 }, asteroide3{ 800,700 }, asteroide4{ 1400,900 };
	Planeta planeta1{ 65, 200,200 }, planeta2{ 65, 200, 500 }, planeta3{ 65, 200, 800 };
	Materia materia1{ 1600, 150 }, materia2{ 1600, 250 }, materia3{ 1600, 750 }, materia4{ 1600, 850 };
	Datos datos;
	Astronauta astronauta1{ 100,950,0,5 };
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
	Level2(int muertes, int puntos, const sf::String& perfil);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update();

	bool veloLuz = true;
	int timer = 0;
	int timer2 = 0;
	bool flagMateria1 = true, flagMateria2 = true, flagMateria3 = true, flagMateria4 = true;
	int puntos = 0;
	int puntosLevel2;
	int muertesLevel2;
	sf::String perfilLevel2;

	void musica();
	void impacto();
	void pickMateria();
	void powerActivo();
	void powerListo();
};

