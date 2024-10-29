#pragma once

#include "Level.h"
#include "Director.h"
#include "SFML\Graphics.hpp"


class Controles :public sf::Drawable, public Level
{

	public:

		Controles();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void update();

	private:

			sf::Sprite _image;
			sf::Texture _texture;
		    sf::Font font;


			sf::Text _cartelSalir;
		
};