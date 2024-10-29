#pragma once
#include "Level.h"
#include "Personaje.h"
#include "Portal.h"
#include "Limite.h"
#include "Asteroide.h"
#include "Planeta.h"
#include "Materia.h"
#include "Datos.h"
#include "Director.h"
#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Partida.h"
#include "ArchivoPartidas.h"

class Level1 : public Level
{
private:
	sf::Sprite _image;
	sf::Texture _texture;
	Personaje haleBopp;
	Portal portal{ 100,900 };
	Limite limite1{ 3200,10,0,200 }, limite2{ 3200,10,1800,500 }, limite3{ 3200,10,0,800 };
	Limite limiteSup{ 5000,1,1,1 }, limiteInf{ 5000,1,1,999 }, limiteDer{ 1,5000,1799,1 }, limiteIzq{ 1,5000,1,1 };
	Asteriode asteroide1{ 1500,100 }, asteroide2{ 300,400 }, asteroide3{ 800,700 }, asteroide4{1400,900};
	Planeta planeta1{ 65,1600,200 }, planeta2{ 65, 200, 500 }, planeta3{65, 1600, 800};
	Materia materia{ 400, 550 };
	Datos datos;
	Partida partida;
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
	Level1(int muertes, int puntos, const sf::String& perfil);
	
	 bool veloLuz = true;
	 int timer = 0;
	 int timer2 = 0;
	 bool flagMateria = true;
	 int puntos = 0;
	 int puntosLevel1;
	 int muertesLevel1;
	 sf::String perfilLevel1;

	 void musica();
	 void impacto();
	 void pickMateria();
	 void powerActivo();
	 void powerListo();
	 void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	 void update();
};


