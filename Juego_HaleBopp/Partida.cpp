#include "Partida.h"

Partida::Partida()
{
	//_perfil = "a";
	_muertes = 0;
	_puntos = 0;
	_nivel = 1;
}

void Partida::setPerfil(sf::String p)
{
	std::string stdString = p.toAnsiString();
	const char* perfil = stdString.c_str();
	strcpy(_perfil, perfil);

}

void Partida::setMuertes(int m)
{
	_muertes = m;
}

void Partida::setPuntos(int pu)
{
	_puntos = pu;
}

void Partida::setEstado(int e)
{
	estado = e;
}

void Partida::setNivel(int n)
{
	_nivel = n;
}

bool Partida::getEstado()
{
	return estado;
}



int Partida::getMuertes()
{
	return _muertes;
}

int Partida::getPuntos()
{
	return _puntos;
}

int Partida::getNivel()
{
	return _nivel;
}

sf::String Partida::getPerfil() const
{
	sf::String perfil(_perfil);
	return perfil;
}