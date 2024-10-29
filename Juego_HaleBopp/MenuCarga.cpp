#include "MenuCarga.h"

MenuCarga::MenuCarga()
{
	_texture.loadFromFile("NombreACargar.png");
	_sprite.setTexture(_texture);

	if (!font.loadFromFile("Roboto-Black.ttf")) {
		std::cout << "no se pudo cargar la fuente" << std::endl;
	}

	caseUser.setFont(font);
	caseUser.setFillColor(sf::Color::Green);
	caseUser.setCharacterSize(50);
	caseUser.setPosition(640, 562);
}

void MenuCarga::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
	target.draw(caseUser, states);
}

void MenuCarga::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '_';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '1';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '2';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '3';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '4';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '5';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '6';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '7';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '8';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '9';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += '0';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'A';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'B';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'C';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'D';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'E';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'F';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'G';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'H';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'I';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'J';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'K';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'L';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'M';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'N';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'O';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'P';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'Q';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'R';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'S';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'T';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'U';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'V';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'W';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'X';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'Y';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && RelojTecla.getElapsedTime() > debounceTime && userName.getSize() < 15) {
		userName += 'Z';
		RelojTecla.restart();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && userName.getSize() > 0 && RelojTecla.getElapsedTime() > debounceTime) {
		userName.erase(userName.getSize() - 1, 1);
		RelojTecla.restart();
	}

	caseUser.setString(userName);



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && RelojTecla.getElapsedTime() > debounceTime) {
		Partida aux = archi.cargarPartida(userName);
		
		Director::getInstance().changeLevel(aux.getNivel(),aux.getMuertes(),aux.getPuntos(), userName);
	}
}


