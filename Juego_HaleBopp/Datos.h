#pragma once
#include "SFML\Graphics.hpp"
#include "Level.h"


class Datos :public sf::Drawable, public Level
{
private:
    sf::Text _profile;
    sf::Text _deaths;
    sf::Text _power;
    sf::Text _points;
    sf::Text _cartelJugador;
    sf::Text _cartelMuertes;
    sf::Text _cartelPuntos;

    sf::Font font;

    int _muertes, _puntos;
    bool poder, estado;
    std::string _poder;
    sf::String _perfil;
    std::string cartelJugador, cartelMuertes, cartelPuntos;

public:
    Datos();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();

    void setMuertes(int muertes);
    void setPuntos(int puntos);
    void setPoder(bool poder);
    void setPerfil(const sf::String& perfil);
    void setEstado(bool e);


    sf::Text getPerfil()const;
    sf::Text getMuertes()const;
    sf::Text getPoder()const;
    sf::Text getPuntos()const;
    sf::Text getCartelJugador()const;
    sf::Text getCartelMuertes()const;
    sf::Text getCartelPuntos()const;
    bool getEstado();
    sf::String getPerfilString();
    int getPuntosInt();
    int getMuertesInt();

    
};

