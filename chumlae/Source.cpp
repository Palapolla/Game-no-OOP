#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <stdlib.h>
sf::RenderWindow window;
sf::Texture backgroundtexture;
sf::Sprite background;
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
	int n;
	scanf_s("%d", &n);
	//window

	sf::RenderWindow window(sf::VideoMode(1240, 720), "Game");
	printf("Opening window . . .\n");

	//-------------------------------------background-------------------------------------------//

	backgroundtexture.loadFromFile("Background.png");
	sf::Sprite background(backgroundtexture);
	background.setScale(0.6f, 0.5f);
	
	//--------------------------------------player & texture----------------------------------------//
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("player texture the real one for sure dont need to fix anynmore.png");
	printf("Loading. . .\n");
	if (!playerTexture.loadFromFile("player texture the real one for sure dont need to fix anynmore.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Player Done!\n");
	}
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setTexture(&playerTexture);
	sf::Vector2u textureSize = playerTexture.getSize();
	int playerSizeX = textureSize.x / 13;
	int playerSizeY = textureSize.y / 21;
	player.setTextureRect(sf::IntRect(playerSizeX* 2, playerSizeY * 2, playerSizeX, playerSizeY));
	int animationFrame = 0,skillFrame = 0;
	bool spaceCheck = false;



	//---------------------------------------level 1----------------------------------------------//



	bool lv1 = true;
	
	//**********wall1**********//

	sf::Texture wall1_tx;
	wall1_tx.loadFromFile("wall01.png");
	if (!wall1_tx.loadFromFile("wall01.jpg")){
		printf("Loading. . .\n");
	}
	else {
		printf("Loading wall 01 done!\n");
	}
	sf::RectangleShape wall1(sf::Vector2f(600,150));
	wall1.setPosition(0, 310);
	wall1.setTexture(&wall1_tx);

	//**********wall2**********//

	sf::Texture wall2_tx;
	wall2_tx.loadFromFile("wall02.jpg");
	if (!wall2_tx.loadFromFile("wall02.jpg")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading wall 02 done!\n");
	}
	sf::RectangleShape wall2(sf::Vector2f(400, 150));
	wall2.setPosition(900, 310);
	wall2.setTexture(&wall2_tx);
	
	//**********wall3**********//

	sf::RectangleShape wall3(sf::Vector2f(100, 400));
	wall3.setPosition(700, 500);
	wall3.setFillColor(sf::Color(0, 0, 0));

	//**********wall4**********//

	sf::Texture wall4_tx;
	wall4_tx.loadFromFile("wall04.jpg");
	if (!wall4_tx.loadFromFile("wall04.jpg")) {
		printf("loading. . .\n");
	}
	else {
		printf("Loading wall04 done!\n");
	}
	sf::RectangleShape wall4(sf::Vector2f(100, 200));
	wall4.setTexture(&wall4_tx);
	wall4.setPosition(800, 0);

	//**********wall5**********//

	sf::Texture wall5_tx;
	wall4_tx.loadFromFile("wall05.jpg");
	if (!wall5_tx.loadFromFile("wall05.jpg")) {
		printf("loading. . .\n");
	}
	else {
		printf("Loading wall04 done!\n");
	}
	sf::RectangleShape wall5(sf::Vector2f(100, 200));
	wall5.setTexture(&wall5_tx);
	wall5.setPosition(200, 0);


	//**********Enemy01**********//

	sf::Texture enemy01_tx;
	enemy01_tx.loadFromFile("Enemy.png");
	if (!enemy01_tx.loadFromFile("Enemy.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Enemy01 Done!\n");
	}
	sf::RectangleShape enemy01(sf::Vector2f(100.0f, 100.0f));
	enemy01.setTexture(&enemy01_tx);
	sf::Vector2u enemy01TextureSize = enemy01_tx.getSize();
	int enemy01SizeX = enemy01TextureSize.x / 13;
	int enemy01SizeY = enemy01TextureSize.y / 21;
	enemy01.setTextureRect(sf::IntRect(enemy01SizeX * 2, enemy01SizeY * 2, enemy01SizeX, enemy01SizeY));
	enemy01.setPosition(1000, 200);
	int  enemyMaxX = 0;
	float enemyPosX = 0, enemy01FrameX = 0, enemy01FrameY = 9;

	//**********Enemy02**********//

	sf::Texture enemy02_tx;
	enemy02_tx.loadFromFile("Enemy2.png");
	if (!enemy02_tx.loadFromFile("Enemy2.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Enemy02 Done!\n");
	}
	sf::RectangleShape enemy02(sf::Vector2f(100.0f, 100.0f));
	enemy02.setTexture(&enemy02_tx);
	sf::Vector2u enemy02TextureSize = enemy02_tx.getSize();
	int enemy02SizeX = enemy02TextureSize.x / 13;
	int enemy02SizeY = enemy02TextureSize.y / 21;
	enemy02.setTextureRect(sf::IntRect(enemy02SizeX * 2, enemy02SizeY * 2, enemy02SizeX, enemy02SizeY));
	enemy02.setPosition(900, 600);
	int  enemy02MaxY = 0;
	float enemy02PosY = 0, enemy02FrameX = 0, enemy02FrameY = 8;



	//---------------------------------------level 2----------------------------------------------//



	//**********Stage1**********//

	//**********wall1**********//

	sf::Texture wallLV201_tx;
	wallLV201_tx.loadFromFile("wallLV201.jpg");
	if (!wallLV201_tx.loadFromFile("wallLV201.jpg")) {
		printf("Loading. . .\n ");
	}
	else {
		printf("Loading wallLV201 Done!\n");
	}
	sf::RectangleShape wallLV201(sf::Vector2f(1000, 150));
	wallLV201.setPosition(0, 400);
	wallLV201.setTexture(&wallLV201_tx);

	//**********wall2**********//

	sf::Texture wallLV202_tx;
	wallLV202_tx.loadFromFile("wallLV202.jpg");
	if (!wallLV202_tx.loadFromFile("wallLV202.jpg")) {
		printf("Loading. . .\n ");
	}
	else {
		printf("Loading wallLV201 Done!\n");
	}
	sf::RectangleShape wallLV202(sf::Vector2f(1000, 150));
	wallLV202.setPosition(240, 150);
	wallLV202.setTexture(&wallLV202_tx);

	//**********wall3**********//

	sf::RectangleShape wallLV203(sf::Vector2f(100, 400));
	wallLV203.setPosition(400, 600);
	wallLV203.setFillColor(sf::Color(0, 0, 0));

	//**********Enemy01**********//

	sf::Texture enemyLV201_tx;
	enemyLV201_tx.loadFromFile("EnemyLV201.png");
	if (!enemyLV201_tx.loadFromFile("EnemyLV201.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV201 Done!\n");
	}
	sf::RectangleShape enemyLV201(sf::Vector2f(100.0f, 100.0f));
	enemyLV201.setTexture(&enemyLV201_tx);
	sf::Vector2u enemyLV201TextureSize = enemyLV201_tx.getSize();
	int enemyLV201SizeX = enemyLV201TextureSize.x / 13;
	int enemyLV201SizeY = enemyLV201TextureSize.y / 21;
	enemyLV201.setTextureRect(sf::IntRect(enemyLV201SizeX * 2, enemyLV201SizeY * 2, enemyLV201SizeX, enemyLV201SizeY));
	enemyLV201.setPosition(1000, 600);
	int  enemyLV201MaxX = 0;
	float enemyLV201PosX = 0, enemyLV201FrameX = 0, enemyLV201FrameY = 9;

	//**********Enemy02**********//

	sf::Texture enemyLV202_tx;
	enemyLV202_tx.loadFromFile("EnemyLV202.png");
	if (!enemyLV202_tx.loadFromFile("EnemyLV202.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV202 Done!\n");
	}
	sf::RectangleShape enemyLV202(sf::Vector2f(100.0f, 100.0f));
	enemyLV202.setTexture(&enemyLV201_tx);
	sf::Vector2u enemyLV202TextureSize = enemyLV202_tx.getSize();
	int enemyLV202SizeX = enemyLV202TextureSize.x / 13;
	int enemyLV202SizeY = enemyLV202TextureSize.y / 21;
	enemyLV202.setTextureRect(sf::IntRect(enemyLV202SizeX * 2, enemyLV202SizeY * 2, enemyLV202SizeX, enemyLV202SizeY));
	enemyLV202.setPosition(1000, 260);
	int  enemyLV202MaxX = 0;
	float enemyLV202PosX = 0, enemyLV202FrameX = 0, enemyLV202FrameY = 9;


	//**********Stage2**********//

	//**********Wall4**********//

	sf::RectangleShape wallLV204(sf::Vector2f(300, 600));
	wallLV204.setPosition(200,300);
	wallLV204.setFillColor(sf::Color(0, 0, 0));

	//**********Door1**********//

	sf::RectangleShape DoorLV2(sf::Vector2f(50, 720));
	DoorLV2.setPosition(900, 0);
	DoorLV2.setFillColor(sf::Color(0, 0, 0));

	//**********Enemy03**********//

	sf::Texture enemyLV203_tx;
	enemyLV203_tx.loadFromFile("EnemyLV203.png");
	if (!enemyLV203_tx.loadFromFile("EnemyLV203.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV203 Done!\n");
	}
	sf::RectangleShape enemyLV203(sf::Vector2f(100.0f, 100.0f));
	enemyLV203.setTexture(&enemyLV203_tx);
	sf::Vector2u enemyLV203TextureSize = enemyLV203_tx.getSize();
	int enemyLV203SizeX = enemyLV203TextureSize.x / 13;
	int enemyLV203SizeY = enemyLV203TextureSize.y / 21;
	enemyLV203.setTextureRect(sf::IntRect(enemyLV203SizeX * 2, enemyLV203SizeY * 2, enemyLV203SizeX, enemyLV203SizeY));
	enemyLV203.setPosition(1000, 600);
	int  enemyLV203MaxY = 0;
	float enemyLV203PosY = 0, enemyLV203FrameX = 0, enemyLV203FrameY = 8;

	//---------------------------------------level 3----------------------------------------------//



	/*----------------------------------------------------------------------------------------------------------

	-------------------------------------------- Loop Zone ----------------------------------------------------
	
	----------------------------------------------------------------------------------------------------------*/

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (lv1 == true) {
			player.setPosition(20, 600);
			lv1 = false;
		}

		// ---------------------------------KeyboardInput------------------------------------// 

		player.setTextureRect(sf::IntRect(playerSizeX * 0, playerSizeY * 2, playerSizeX, playerSizeY));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.move(4.5f, 0.0f);
			player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 11, playerSizeX, playerSizeY));
			//printf("Keypress : D\n");

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.move(-4.5f, 0.0f);
			player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 9, playerSizeX, playerSizeY));
			//printf("Keypress : A\n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.move(0.0f, -4.5f);
			player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 8, playerSizeX, playerSizeY));
			//printf("Keypress : W\n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.move(0.0f, 4.5f);
			player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 10, playerSizeX, playerSizeY));
			//printf("Keypress : S\n");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			spaceCheck = true;
			//printf("Keypress : Space\n");
		}
		if (spaceCheck == true) {
			skillFrame++;
			player.setTextureRect(sf::IntRect(playerSizeX * skillFrame, playerSizeY * 2, playerSizeX, playerSizeY));
			delay(100);
			if (skillFrame >= 6) {
				skillFrame = 0;
				spaceCheck = false;
				continue;
			}
		}
		else {
			animationFrame++;
			delay(45);
			if (animationFrame >= 9) {
				animationFrame = 0;
			}
		}
		sf::Vector2f playerPosition = player.getPosition();
		//printf("X = %f\nY = %f\n", playerPosition.x, playerPosition.y);


		//--------------------------------------ENEMY LEVEL1------------------------------------------//

		//**********enemy01 animation**********//

		enemy01.move(enemyPosX, 0.0f);
		enemy01.setTextureRect(sf::IntRect(enemy01SizeX * enemy01FrameX, enemy01SizeY * enemy01FrameY, enemy01SizeX, enemy01SizeY));
		enemy01FrameX++;
		if (enemy01FrameX >= 9) {
			enemy01FrameX = 0;
		}

		//Check Enemy 01 Position//

		if (enemyMaxX < 100) {
			enemyPosX = -4.5;
			enemyMaxX++;
		}
		else if (enemyMaxX >= 100 && enemyMaxX < 200) {
			enemy01FrameY = 11;
			enemyPosX = 4.5;
			enemyMaxX++;
		}
		else {
			enemyMaxX = 0;
			enemyPosX = 0;
			enemy01FrameY = 9;
		}

		//**********enemy01 animation**********//

		enemy02.move(0.0f, enemy02PosY);
		enemy02.setTextureRect(sf::IntRect(enemy02SizeX * enemy02FrameX, enemy02SizeY * enemy02FrameY, enemy02SizeX, enemy02SizeY));
		enemy02FrameX++;
		if (enemy02FrameX >= 9) {
			enemy02FrameX = 0;
		}

		//Check Enemy 02 Position//

		if (enemy02MaxY < 50) {
			enemy02PosY = -4.5;
			enemy02MaxY++;
		}
		else if (enemy02MaxY >= 50 && enemy02MaxY < 100) {
			enemy02FrameY = 10;
			enemy02PosY = 4.5;
			enemy02MaxY++;
		}
		else {
			enemy02MaxY = 0;
			enemy02PosY = 0;
			enemy02FrameY = 8;
		}
		sf::Vector2f enemy02Position = enemy02.getPosition();


		//--------------------------------------ENEMY LEVEL2------------------------------------------//

		//**********enemy02 animation**********//

		enemyLV201.move(enemyLV201PosX, 0.0f);
		enemyLV201.setTextureRect(sf::IntRect(enemyLV201SizeX * enemyLV201FrameX, enemyLV201SizeY * enemyLV201FrameY, enemyLV201SizeX, enemyLV201SizeY));
		enemyLV201FrameX++;
		if (enemyLV201FrameX >= 9) {
			enemyLV201FrameX = 0;
		}

		//Check Enemy 02 Position//

		if (enemyLV201MaxX < 100) {
			enemyLV201PosX = -4.5;
			enemyLV201MaxX++;
		}
		else if (enemyLV201MaxX >= 100 && enemyLV201MaxX < 200) {
			enemyLV201FrameY = 11;
			enemyLV201PosX = 4.5;
			enemyLV201MaxX++;
		}
		else {
			enemyLV201MaxX = 0;
			enemyLV201PosX = 0;
			enemyLV201FrameY = 9;
		}

		//**********enemy02 animation**********//

		enemyLV202.move(enemyLV202PosX, 0.0f);
		enemyLV202.setTextureRect(sf::IntRect(enemyLV202SizeX* enemyLV202FrameX, enemyLV202SizeY* enemyLV202FrameY, enemyLV202SizeX, enemyLV202SizeY));
		enemyLV202FrameX++;
		if (enemyLV202FrameX >= 9) {
			enemyLV202FrameX = 0;
		}

		//Check Enemy 02 Position//

		if (enemyLV202MaxX < 200) {
			enemyLV202PosX = -4.5;
			enemyLV202MaxX++;
		}
		else if (enemyLV202MaxX >= 200 && enemyLV202MaxX < 400) {
			enemyLV202FrameY = 11;
			enemyLV202PosX = 4.5;
			enemyLV202MaxX++;
		}
		else {
			enemyLV202MaxX = 0;
			enemyLV202PosX = 0;
			enemyLV202FrameY = 9;
		}

		//**********enemy03 animation**********//

		enemyLV203.move(0.0f,enemyLV203PosY);
		enemyLV203.setTextureRect(sf::IntRect(enemyLV203SizeX* enemyLV203FrameX, enemyLV203SizeY* enemyLV203FrameY, enemyLV203SizeX, enemyLV203SizeY));
		enemyLV203FrameX++;
		if (enemyLV203FrameX >= 9) {
			enemyLV203FrameX = 0;
		}

		//Check Enemy 03 Position//

		if (enemyLV203MaxY < 100) {
			enemyLV203PosY = -4.5;
			enemyLV203MaxY++;
		}
		else if (enemyLV203MaxY >= 100 && enemyLV203MaxY < 200) {
			enemyLV203FrameY = 10;
			enemyLV203PosY = 4.5;
			enemyLV203MaxY++;
		}
		else {
			enemyLV203MaxY = 0;
			enemyLV203PosY = 0;
			enemyLV203FrameY = 8;
		}
		sf::Vector2f enemyLV203Position = enemyLV203.getPosition();

		/*----------------------------------------------------------------------------------------------------------

		------------------------------------------------------------------------------------------------------------

		---------------------------------------------Render Zone----------------------------------------------------
		
		------------------------------------------------------------------------------------------------------------
		
		----------------------------------------------------------------------------------------------------------*/

		window.clear();
		window.draw(background);

		//Render:LEVEL 1//

		if (n == 1) {
			if (playerPosition.y <= 244.5) {
				window.draw(wall4);
				window.draw(wall5);
				if (playerPosition.y <= 195.0) {
					window.draw(player);
					window.draw(enemy01);
				}
				else {
					window.draw(enemy01);
					window.draw(player);
				}
				window.draw(wall1);
				window.draw(wall2);
				window.draw(enemy02);
				window.draw(wall3);

			}
			else {
				window.draw(enemy01);
				
				window.draw(wall4);
				window.draw(wall5);
				window.draw(wall1);
				window.draw(wall2);
				window.draw(enemy02);
				window.draw(player);
				window.draw(wall3);
			}
			if (enemy02Position.y < playerPosition.y) {
				window.draw(enemy02);
				window.draw(player);
			}
			else {
				window.draw(player);
				window.draw(enemy02);
			}
		}

		//RENDER:LEVEL 2//

		else if (n == 2) {
			if (playerPosition.y <= 350 && playerPosition.y > 250) {
				window.draw(wallLV202);
				window.draw(enemyLV202);
				window.draw(player);
				window.draw(enemyLV201);
				window.draw(wallLV201);
			}
			else if (playerPosition.y <= 250 && playerPosition.y > 100) {
				window.draw(wallLV202);
				window.draw(player);
				window.draw(enemyLV202);
				window.draw(enemyLV201);
				window.draw(wallLV201);
			}
			else if (playerPosition.y <= 100) {
				window.draw(player);
				window.draw(wallLV202);
				window.draw(enemyLV202);
				window.draw(enemyLV201);
				window.draw(wallLV201);
			}
			else if (playerPosition.y >= 600) {
				window.draw(wallLV202);
				window.draw(enemyLV202);
				window.draw(enemyLV201);
				window.draw(player);
				window.draw(wallLV201);
			}
			else {
				window.draw(wallLV201);
				window.draw(wallLV202);
				window.draw(player);
				window.draw(enemyLV202);
				window.draw(enemyLV201);
			}
			window.draw(wallLV203);
		}
		else if (n == 3) {
			if (enemy02Position.y < playerPosition.y) {
				window.draw(enemyLV203);
				window.draw(player);
			}
			else {
				window.draw(player);
				window.draw(enemyLV203);
			}
			window.draw(wallLV204);
			window.draw(DoorLV2);
		}

		
		window.display();
	}
	/*----------------------------------------------------------------------------------------------------------

	--------------------------------------------- Loop END -----------------------------------------------------

	----------------------------------------------------------------------------------------------------------*/
}