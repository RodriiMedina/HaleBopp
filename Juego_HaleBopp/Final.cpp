#include "Final.h"

Final::Final(int muertes, int puntos, const sf::String& perfil)
{

    if (!font.loadFromFile("Roboto-Black.ttf")) {
        std::cout << "No se pudo cargar la fuente del final" << std::endl;
        exit(1);
    }

    /* Space Comics.ttf  | fuente bug */

    if (!_texture.loadFromFile("Final.png")) {
        std::cout << "No se pudo cargar la imagen del final" << std::endl;
        exit(2);
    }
    _image.setTexture(_texture);
    
    //setear los datos a mostrar

    muertesFinal = muertes;
    datos.setMuertes(muertesFinal);

    puntosFinal = puntos;
    datos.setPuntos(puntosFinal);

    perfilFinal = perfil;
    datos.setPerfil(perfilFinal);


    textVida.setFont(font);
    textVida.setString(perfilFinal);
    textVida.setFillColor(sf::Color::White);
    textVida.setPosition(900, 420);

    textPuntos.setFont(font);
    textPuntos.setString(std::to_string(puntosFinal));
    textPuntos.setFillColor(sf::Color::White);
    textPuntos.setPosition(900, 555);


    textMuerte.setFont(font);
    textMuerte.setString(std::to_string(muertesFinal));
    textMuerte.setFillColor(sf::Color::White);
    textMuerte.setPosition(930, 700);
}

void Final::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    target.draw(_image, states);
    target.draw(_cartelSalir, states);
    target.draw(_cartelVolver, states);

	target.draw(textVida, states);
    target.draw(textMuerte, states);
    target.draw(textPuntos, states);

}

void Final::update()
{
}