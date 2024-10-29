#pragma once
#include "Level.h"
#include "Director.h"
#include "Personaje.h"
#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"


const int Opciones_Menu = 3;

class Menu :public sf::Drawable, public Level
{
public:
    Menu();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void MoverArriba();
    void MoverAbajo();
    int OpcionSeleccionada() const;
    void update();
    void musica();
    int muertesMenu;
    int puntosMenu;
    sf::String perfilMenu;

private:
    sf::Sprite _image;
    sf::Texture _texture;

    sf::Clock RelojTecla;
    const sf::Time Cooldown = sf::milliseconds(200);

    sf::Text menuTexts[Opciones_Menu];
    sf::Font font;
    int Seleccionador = 0;
    sf::SoundBuffer _buffer;
    sf::Sound _sound;

};

