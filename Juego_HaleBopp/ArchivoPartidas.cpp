#include "ArchivoPartidas.h"
#include <iostream>
#include <cstring>

ArchivoPartidas::ArchivoPartidas(const char* n)
{
	strcpy(nombre, n);
}

Partida ArchivoPartidas::leerRegistro(int pos)
{
	Partida reg;
	reg.setEstado(false);
	FILE* p;
	p = fopen(nombre, "rb");
	if (p == NULL) return reg;
	fseek(p, sizeof reg * pos, 0);
	fread(&reg, sizeof reg, 1, p);
	fclose(p);
	return reg;

}

int ArchivoPartidas::contarRegistros()
{
	FILE* p;
	p = fopen(nombre, "rb");
	if (p == NULL) return -1;
	fseek(p, 0, 2);
	int tam = ftell(p);
	fclose(p);
	return tam / sizeof(Partida);

}

bool ArchivoPartidas::grabarRegistro(Partida reg)
{
	FILE* p;
	p = fopen(nombre, "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof reg, 1, p);
	fclose(p);
	return escribio;

}

bool ArchivoPartidas::grabarRegistro(Partida reg, int pos)
{
	FILE* p;
	p = fopen(nombre, "rb+");
	if (p == NULL) return false;
	fseek(p, sizeof reg * pos, SEEK_SET);
	bool escribio = fwrite(&reg, sizeof reg, 1, p);
	fclose(p);
	return escribio;
}

bool ArchivoPartidas::guardarPartida(const sf::String& perfil, int muertes, int puntos, int nivel)
{
	ArchivoPartidas archi;
	Partida obj;
	bool escribio=true;
	int cant = archi.contarRegistros();
	for (int i = 0; i < cant; i++) {
		if (archi.leerRegistro(i).getPerfil()==perfil) {
			obj = archi.leerRegistro(i);
			obj.setMuertes(muertes);
			obj.setPuntos(puntos);
			obj.setNivel(nivel);
			obj.setPerfil(perfil);
			archi.grabarRegistro(obj, i);
			std::cout << "Partida guardada correctamente" << std::endl;
			return escribio;
		}
	}
	obj.setPerfil(perfil);
	obj.setMuertes(muertes);
	obj.setPuntos(puntos);
	obj.setNivel(nivel);
	archi.grabarRegistro(obj);
	std::cout << "Nueva partida guardada correctamente" << std::endl;
	return escribio;
}

bool ArchivoPartidas::buscarRegistro(const sf::String& perfil)
{
	ArchivoPartidas archi;
	Partida obj;
	int cant = archi.contarRegistros();
	for (int i = 0; i < cant; i++) {
		obj = archi.leerRegistro(i);
		if (obj.getPerfil()==perfil) {
			return true;
		}
	}
	return false;
}

Partida ArchivoPartidas::cargarPartida(const sf::String& perfil)
{
	ArchivoPartidas archi;
	Partida obj, obj2;
	obj2.setNivel(5);
	obj2.setMuertes(0);
	obj2.setPuntos(0);
	obj2.setPerfil("");
	int cant = archi.contarRegistros();
	for (int i = 0; i < cant; i++) {
		obj = archi.leerRegistro(i);
		if (obj.getPerfil()==perfil) {
			return obj;
		}
	}
	std::cout << "No se pudo cargar partida" << std::endl;
	return obj2;
}
