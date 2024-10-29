#include "Director.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Final.h"
#include "Controles.h"
#include "UserName.h"
#include "MenuCarga.h"

Director* Director::_pDirector = nullptr;


Director::Director()
{
	_pCurrentLevel = nullptr;
}

void Director::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_pCurrentLevel, states);
}

void Director::update()
{
	_pCurrentLevel->update();
	datos.setMuertes(level.getMuertesTotales());
	datos.setPuntos(level.getPuntosTotales());
	datos.setPerfil(perfil);
}

Director& Director::getInstance()
{
	if (Director::_pDirector == nullptr) {
		Director::_pDirector = new Director();
	}
	return *Director::_pDirector;
}

void Director::changeLevel(int number, int m, int p, const sf::String& n)
{
	if (_pCurrentLevel != nullptr) {
		muertes = m;
		puntos = p;
		perfil = n;
		delete _pCurrentLevel;
	}


	switch (number)
	{
	case 0:
		_pCurrentLevel = new Menu;
		break;
	case 1:
		_pCurrentLevel = new Level1(muertes, puntos, perfil);
		break;
		case 2:
		_pCurrentLevel = new Level2(muertes, puntos, perfil);
		break;
	case 3:
		_pCurrentLevel = new Level3(muertes, puntos, perfil);
		break;
	case 4:
		_pCurrentLevel = new Level4(muertes, puntos, perfil);
		break;
	case 5:
		_pCurrentLevel = new Jugadores;
		break;
	case 6:
		_pCurrentLevel = new MenuCarga;
		break;
	case 10:
		_pCurrentLevel = new UserName;
		break;
	case 11:
		_pCurrentLevel = new Controles;
		break;
	case 12:
		_pCurrentLevel = new Final(muertes, puntos, perfil);
		break;
	default:
		break;
	}
}


 


