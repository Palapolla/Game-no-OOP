#include <SFML/Graphics.hpp>
#include <stdlib.h>

void delay(int number_of_seconds)
{
	// Converting time into milli_seconds 
	int milli_seconds = number_of_seconds;

	// Storing start time 
	clock_t start_time = clock();

	// looping till required time is not achieved 
	while (clock() < start_time + milli_seconds)
		;
}

int main() {
	//window

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
	
	//--------------------------------------player & texture----------------------------------------//
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("player texture the real one for sure dont need to fix anynmore.png");
	sf::RectangleShape player(sf::Vector2f(60.0f, 60.0f));
	player.setTexture(&playerTexture);
	sf::Vector2u textureSize = playerTexture.getSize();
	int playerSizeX = textureSize.x / 13;
	int playerSizeY = textureSize.y / 21;
	player.setTextureRect(sf::IntRect(playerSizeX* 2, playerSizeY * 2, playerSizeX, playerSizeY));

	int animationFrame = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// -------------------------KeyboardInput------------------------------------// 

		player.setTextureRect(sf::IntRect(playerSizeX * 0, playerSizeY * 2, playerSizeX, playerSizeY));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.move(6.0f, 0.0f);
			player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 11, playerSizeX, playerSizeY));
			
			printf("Keypress : D\n");
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.move(-6.0f, 0.0f);
			player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 9, playerSizeX, playerSizeY));
			
			printf("Keypress : A\n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.move(0.0f, -6.0f);
			player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 8, playerSizeX, playerSizeY));
			
			printf("Keypress : W\n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.move(0.0f, 6.0f);
			player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 10, playerSizeX, playerSizeY));
			
			printf("Keypress : S\n");
		}
		animationFrame++;
		delay(30);
		if (animationFrame >= 9) {
			animationFrame = 0;
		}


		window.clear();
		window.draw(player);
		//keyboardinput();
		window.display();
	}
}