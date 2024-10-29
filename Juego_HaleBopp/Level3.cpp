#include "Level3.h"

Level3::Level3(int muertes, int puntos, const sf::String& perfil)
{
	if(!_texture.loadFromFile("fondofinal3.png")) {
	std::cout << "la imagen del fondo del nivel 3, no se cargo correctamente" << std::endl;
	}
	_image.setTexture(_texture);

	muertesLevel3 = muertes;
	datos.setMuertes(muertesLevel3);
	puntosLevel3 = puntos;
	datos.setPuntos(puntosLevel3);
	perfilLevel3 = perfil;
	datos.setPerfil(perfilLevel3);
}

void Level3::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_image, states);
	target.draw(haleBopp.getSprite(), states);
	target.draw(portal.getSprite(), states);
	target.draw(limite1.getLimite(), states);
	target.draw(limite2.getLimite(), states);
	target.draw(limite3.getLimite(), states);
	target.draw(limite4.getLimite(), states);
	target.draw(limiteSup.getLimite(), states);
	target.draw(limiteInf.getLimite(), states);
	target.draw(limiteDer.getLimite(), states);
	target.draw(limiteIzq.getLimite(), states);
	target.draw(asteroide1.getSprite(), states);
	target.draw(asteroide2.getSprite(), states);
	target.draw(asteroide3.getSprite(), states);
	target.draw(asteroide4.getSprite(), states);
	target.draw(planeta1.getPlaneta(), states);
	target.draw(planeta2.getPlaneta(), states);
	target.draw(planeta3.getPlaneta(), states);
	target.draw(planeta4.getPlaneta(), states);
	target.draw(datos.getMuertes(), states);
	target.draw(datos.getPoder(), states);
	target.draw(datos.getPerfil(), states);
	target.draw(datos.getPuntos(), states);
	target.draw(datos.getCartelJugador(), states);
	target.draw(datos.getCartelMuertes(), states);
	target.draw(datos.getCartelPuntos(), states);
	target.draw(astronauta1.getSprite(), states);
	target.draw(satelite1.getSprite(), states);
	target.draw(satelite2.getSprite(), states);

	if (flagMateria1 == true) {
		target.draw(materia1.getSprite(), states);
	}
	if (flagMateria2 == true) {
		target.draw(materia2.getSprite(), states);
	}
	if (flagMateria3 == true) {
		target.draw(materia3.getSprite(), states);
	}
	if (flagMateria4 == true) {
		target.draw(materia4.getSprite(), states);
	}
}

void Level3::musica()
{
	if (!_buffer.loadFromFile("audio3.wav")) {
		std::cout << "No se pudo cargar la musica del nivel 3" << std::endl;
	}
	_sound.setBuffer(_buffer);
	//_sound.play();
}

void Level3::impacto()
{
	if (!_buffer2.loadFromFile("impacto.wav")) {
		std::cout << "No se pudo cargar la musica del impacto" << std::endl;
	}
	_sound2.setBuffer(_buffer2);
	_sound2.play();
}

void Level3::pickMateria()
{
	if (!_buffer2.loadFromFile("materia.wav")) {
		std::cout << "No se pudo cargar la musica de materia" << std::endl;
	}
	_sound2.setBuffer(_buffer2);
	_sound2.play();
}

void Level3::powerActivo()
{
	if (!_buffer3.loadFromFile("powerDown.wav")) {
		std::cout << "No se pudo cargar la musica de poder activado" << std::endl;
	}
	_sound3.setBuffer(_buffer3);
	_sound3.play();
}

void Level3::powerListo()
{
	if (!_buffer4.loadFromFile("powerOn.wav")) {
		std::cout << "No se pudo cargar la musica de poder listo" << std::endl;
	}
	_sound4.setBuffer(_buffer4);
	_sound4.play();
}










void Level3::update()
{
	datos.setPoder(veloLuz);

	///musica
	if (timer2 > 0) {
		timer2--;
	}

	if (timer2 == 0) {
		musica();
		timer2 = 60 * 50;
	}

	///Velocidad de la luz
	if (timer > 0) {
		timer--;
	}
	if (timer == 1) {
		powerListo();
		veloLuz = true;
	}

	if (veloLuz == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timer == 0) {
		haleBopp.power();
		timer = 60 * 4;
		powerActivo();
		puntos = puntos * 1.2;
		veloLuz = false;
	}
	if (haleBopp.getMoveX() != 0 || haleBopp.getMoveY() != 0) {
		puntos++;
	}
	puntosLevel3 += puntos;
	setPuntosTotales(puntos);
	datos.setPuntos(puntosLevel3);

	///Hale Bopp agarra materia
	if (haleBopp.isCollision(materia1) && flagMateria1 == true) {
		flagMateria1 = false;
		pickMateria();
	}
	if (haleBopp.isCollision(materia2) && flagMateria2 == true) {
		flagMateria2 = false;
		pickMateria();
	}
	if (haleBopp.isCollision(materia3) && flagMateria3 == true) {
		flagMateria3 = false;
		pickMateria();
	}
	if (haleBopp.isCollision(materia4) && flagMateria4 == true) {
		flagMateria4 = false;
		pickMateria();
	}

	///colisiones Hale Bopp - Satelites
	if (haleBopp.isCollision(satelite1) || haleBopp.isCollision(satelite2)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	///colisiones Hale Bopp - limites
	if (haleBopp.isCollision(limite1)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	if (haleBopp.isCollision(limite2)) {
			haleBopp.respawn();
			impacto();
			muertesLevel3++;
			setMuertesTotales(1);
			datos.setMuertes(muertesLevel3);
	}

	if (haleBopp.isCollision(limite3)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}
	

	if (haleBopp.isCollision(limite4)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	if (haleBopp.isCollision(limiteSup)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	if (haleBopp.isCollision(limiteInf)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	if (haleBopp.isCollision(limiteDer)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	if (haleBopp.isCollision(limiteIzq)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	///colision Hale Bopp-asteroide
	if (haleBopp.isCollision(asteroide1) || haleBopp.isCollision(asteroide2) || haleBopp.isCollision(asteroide3) || haleBopp.isCollision(asteroide4)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	///colisiones Hale Bopp - Astronautas
	if (haleBopp.isCollision(astronauta1)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	///colision Hale Bopp - planetas
	if (haleBopp.isCollision(planeta1) || haleBopp.isCollision(planeta2) || haleBopp.isCollision(planeta3) || haleBopp.isCollision(planeta4)) {
		haleBopp.respawn();
		impacto();
		muertesLevel3++;
		setMuertesTotales(1);
		datos.setMuertes(muertesLevel3);
	}

	///colisiones de astronauta
	if (astronauta1.isCollision(limite1)) {
		astronauta1.setMoveX();
	}

	if (astronauta1.isCollision(limite2)) {
		astronauta1.setMoveX();
	}

	if (astronauta1.isCollision(limite3)) {
		astronauta1.setMoveX();
	}

	if (astronauta1.isCollision(limite4)) {
		astronauta1.setMoveX();
	}

	if (astronauta1.isCollision(asteroide1) || astronauta1.isCollision(asteroide2) || astronauta1.isCollision(asteroide3) || astronauta1.isCollision(asteroide4)) {
		astronauta1.setMoveX();
	}

	///colisiones de asteroides
	///asteroide 1
	if (asteroide1.isCollision(limite1)) {
		asteroide1.setMoveX();
	}

	if (asteroide1.isCollision(limite2)) {
		asteroide1.setMoveX();
	}

	if (asteroide1.isCollision(limite3)) {
		asteroide1.setMoveX();
	}

	if (asteroide1.isCollision(limite4)) {
		asteroide1.setMoveX();
	}

	if (asteroide1.isCollision(planeta1) || asteroide1.isCollision(planeta2) || asteroide1.isCollision(planeta3) || asteroide1.isCollision(planeta4)
		|| asteroide1.isCollision(asteroide2) || asteroide1.isCollision(asteroide3) || asteroide1.isCollision(asteroide4)) {
		asteroide1.setMoveX();
		asteroide1.setMoveY();
	}

	///asteroide 2
	if (asteroide2.isCollision(limite1)) {
		asteroide2.setMoveX();
	}

	if (asteroide2.isCollision(limite2)) {
		asteroide2.setMoveX();
	}

	if (asteroide2.isCollision(limite3)) {
		asteroide2.setMoveX();
	}

	if (asteroide2.isCollision(limite4)) {
		asteroide2.setMoveX();
	}

	if (asteroide2.isCollision(planeta1) || asteroide2.isCollision(planeta2) || asteroide2.isCollision(planeta3) || asteroide2.isCollision(planeta4)
		|| asteroide2.isCollision(asteroide1) || asteroide2.isCollision(asteroide3) || asteroide2.isCollision(asteroide4)) {
		asteroide2.setMoveX();
		asteroide2.setMoveY();
	}
	///asteroide 3
	if (asteroide3.isCollision(limite1)) {
		asteroide3.setMoveX();
	}

	if (asteroide3.isCollision(limite2)) {
		asteroide3.setMoveX();
	}

	if (asteroide3.isCollision(limite3)) {
		asteroide3.setMoveX();
	}

	if (asteroide3.isCollision(limite4)) {
		asteroide3.setMoveX();
	}

	if (asteroide3.isCollision(planeta1) || asteroide3.isCollision(planeta3) || asteroide3.isCollision(planeta2) || asteroide3.isCollision(planeta4)
		|| asteroide3.isCollision(asteroide2) || asteroide3.isCollision(asteroide1) || asteroide3.isCollision(asteroide4)) {
		asteroide3.setMoveX();
		asteroide3.setMoveY();
	}
	///asteroide 4
	if (asteroide4.isCollision(limite1)) {
		asteroide4.setMoveX();
	}

	if (asteroide4.isCollision(limite2)) {
		asteroide4.setMoveX();
	}

	if (asteroide4.isCollision(limite3)) {
		asteroide4.setMoveX();
	}

	if (asteroide4.isCollision(limite4)) {
		asteroide4.setMoveX();
	}

	if (asteroide4.isCollision(planeta1) || asteroide4.isCollision(planeta2) || asteroide4.isCollision(planeta3) || asteroide4.isCollision(planeta4)
		|| asteroide4.isCollision(asteroide2) || asteroide4.isCollision(asteroide3) || asteroide4.isCollision(asteroide1)) {
		asteroide4.setMoveX();
		asteroide4.setMoveY();
	}




	haleBopp.update();
	portal.update();
	asteroide1.update();
	asteroide2.update();
	asteroide3.update();
	asteroide4.update();
	planeta1.update();
	planeta2.update();
	planeta3.update();
	planeta4.update();
	materia1.update();
	materia2.update();
	materia3.update();
	materia4.update();
	datos.update();
	astronauta1.update();
	satelite1.update();
	satelite2.update();



	///colision portal
	if (haleBopp.isCollision(portal) && flagMateria1 == false && flagMateria2 == false && flagMateria3 == false && flagMateria4 == false) {
		archipart.guardarPartida(perfilLevel3, muertesLevel3, puntosLevel3, 4);
		director.changeLevel(4, muertesLevel3, puntosLevel3, perfilLevel3);
		haleBopp.respawn();
	}


	///cambio de nivel manual
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		Director::getInstance().changeLevel(4, muertesLevel3, puntosLevel3, perfilLevel3);

	}

}

