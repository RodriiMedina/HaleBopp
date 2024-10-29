#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include "Datos.h"
class Partida 
{
private:
	char _perfil[16];
	int _muertes, _puntos, _nivel;
	bool estado;
public:
	Partida();

	void setPerfil(sf::String p);
	void setMuertes(int m);
	void setPuntos(int pu);
	void setEstado(int e);
	void setNivel(int n);

	bool getEstado();
	sf::String getPerfil() const;
	int getMuertes();
	int getPuntos();
	int getNivel();
};

