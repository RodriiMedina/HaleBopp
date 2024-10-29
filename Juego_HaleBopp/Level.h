#pragma once
#include "SFML/Graphics.hpp"
class Level : public sf::Drawable
{
private:
	int _muertesTotales, _puntosTotales;
	sf::String _perfilGeneral;
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update();

	void setMuertesTotales(int muertes);
	void setPuntosTotales(int puntos);

	int getPuntosTotales();
	int getMuertesTotales();

};


