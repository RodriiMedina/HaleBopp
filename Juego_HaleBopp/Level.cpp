#include "Level.h"

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void Level::update()
{
}

void Level::setMuertesTotales(int muertes)
{
	_muertesTotales += muertes;
}

void Level::setPuntosTotales(int puntos)
{
	_puntosTotales += puntos;
}


int Level::getPuntosTotales()
{
	return _puntosTotales;
}

int Level::getMuertesTotales()
{
	return _muertesTotales;
}

