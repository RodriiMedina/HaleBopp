#pragma once
#include "Level.h"
#include "Director.h"
#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include "ArchivoPartidas.h"
#include "Limite.h"

const int Opciones_Jugadores = 3;

class Jugadores : public Level
{
public:
    Jugadores();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

    void MoverArriba();
    void MoverAbajo();

    int OpcionSeleccionada() const;




private:

    int Seleccionador = 0;

    sf::Text menuTexts[Opciones_Jugadores];
    sf::Font font;

    sf::Sprite _image;
    sf::Texture _texture;

    sf::Clock RelojTecla;
    const sf::Time Cooldown = sf::milliseconds(200);

    ArchivoPartidas archi;
};
