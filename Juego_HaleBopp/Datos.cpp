#include "Datos.h"
#include <iostream>

Datos::Datos()
{
	_poder = "BUENO GENTES!!";
	cartelJugador = "JUGADOR:";
	cartelMuertes = "MUERTES:";
	cartelPuntos = "PUNTAJE:";

	font.loadFromFile("Roboto-Black.ttf");

	_cartelJugador.setFont(font);
	_cartelJugador.setFillColor(sf::Color::Yellow);
	_cartelJugador.setString(cartelJugador);
	_cartelJugador.setPosition(0, 0);

	_cartelMuertes.setFont(font);
	_cartelMuertes.setFillColor(sf::Color::Yellow);
	_cartelMuertes.setString(cartelMuertes);
	_cartelMuertes.setPosition(500, 0);

	_cartelPuntos.setFont(font);
	_cartelPuntos.setFillColor(sf::Color::Yellow);
	_cartelPuntos.setString(cartelPuntos);
	_cartelPuntos.setPosition(800, 0);

	_profile.setFont(font);
	_profile.setFillColor(sf::Color::Yellow);
	_profile.setString(_perfil);
	_profile.setPosition(150, 0);

	_deaths.setFont(font);
	_deaths.setFillColor(sf::Color::Yellow);
	_deaths.setString(std::to_string(_muertes));
	_deaths.setPosition(650, 0);

	_points.setFont(font);
	_points.setFillColor(sf::Color::Yellow);
	_points.setString(std::to_string(_puntos));
	_points.setPosition(950, 0);

	_power.setFont(font);
	_power.setFillColor(sf::Color::Green);
	_power.setString(_poder);
	_power.setPosition(1200, 0);


}


void Datos::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_deaths, states);
	target.draw(_power, states);
	target.draw(_points, states);
	target.draw(_cartelJugador, states);
	target.draw(_cartelMuertes, states);
	target.draw(_cartelPuntos, states);
	target.draw(_profile, states);
}

void Datos::update()
{
}

sf::Text Datos::getPerfil()const
{
	return _profile;
}

sf::Text Datos::getMuertes()const
{
	return _deaths;
}


sf::Text Datos::getPoder()const
{
	return _power;
}

sf::Text Datos::getPuntos() const
{
	return _points;
}

sf::Text Datos::getCartelJugador() const
{
	return _cartelJugador;
}

sf::Text Datos::getCartelMuertes() const
{
	return _cartelMuertes;
}

sf::Text Datos::getCartelPuntos() const
{
	return _cartelPuntos;
}

bool Datos::getEstado()
{
	return estado;
}

sf::String Datos::getPerfilString()
{
	return _perfil;
}

int Datos::getPuntosInt()
{
	return _puntos;
}

int Datos::getMuertesInt()
{
	return _muertes;
}





void Datos::setMuertes(int muertes)
{
	_muertes = muertes;
	_deaths.setString(std::to_string(_muertes));
}

void Datos::setPuntos(int puntos)
{
	_puntos = puntos;
	_points.setString(std::to_string(_puntos));
}

void Datos::setPerfil(const sf::String& perfil)
{
	_perfil = perfil;
	_profile.setString(_perfil);
}

void Datos::setEstado(bool e)
{
	estado = e;
}


void Datos::setPoder(bool poder)
{
	if (poder == true) {
		_poder = "Velocidad de la luz PREPARADA";
		_power.setString(_poder);
		_power.setFillColor(sf::Color::Green);
	}
	else {
		_poder = "Cargando velocidad de la luz...";
		_power.setString(_poder);
		_power.setFillColor(sf::Color::Red);
	}
}





