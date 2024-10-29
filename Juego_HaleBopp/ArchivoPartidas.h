#pragma once+
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio> 
#include "Partida.h" 
class ArchivoPartidas
{
private:
	char nombre[30];
public:
	ArchivoPartidas(const char* n = "datos.dat");
	Partida leerRegistro(int pos);
	int contarRegistros();
	bool grabarRegistro(Partida reg);
	bool grabarRegistro(Partida reg, int pos);
	bool guardarPartida(const sf::String& perfil, int muertes, int puntos, int nivel);
	bool buscarRegistro(const sf::String& perfil);
	Partida cargarPartida(const sf::String& perfil);

};

