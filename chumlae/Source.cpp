/*
background
wall top
player & texture
Level 1
Level 2
Level 3
Level 4
LOOP Zone
*/
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
	int n = 1;
	bool lv1ch = true;
	//window

	sf::RenderWindow window(sf::VideoMode(1240, 720), "Game");
	printf("Opening window . . .\n");

	//-------------------------------------background-------------------------------------------//

	backgroundtexture.loadFromFile("Background.png");
	sf::Sprite background(backgroundtexture);
	background.setScale(0.6f, 0.5f);

	//-------------------------------------Wall top-------------------------------------------//

	sf::Texture walltop_tx;
	walltop_tx.loadFromFile("walltop.jpg");
	if (!walltop_tx.loadFromFile("walltop.jpg")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading wall 01 done!\n");
	}
	sf::RectangleShape walltop(sf::Vector2f(1240, 100));
	walltop.setPosition(0, 0);
	walltop.setTexture(&walltop_tx);
	sf::Vector2f walltopPos = walltop.getPosition();

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
	player.setTextureRect(sf::IntRect(playerSizeX * 2, playerSizeY * 2, playerSizeX, playerSizeY));
	int animationFrame = 0, skillFrame = 0;
	bool spaceCheck = false;
	bool KeyW = false, KeyA = false, KeyS = false, KeyD = false;
	player.setTextureRect(sf::IntRect(playerSizeX * 0, playerSizeY * 2, playerSizeX, playerSizeY));
	//player.setOrigin(50, 50);


	//Player > > Bullet//

	//BullKeyState//

	bool bullW = false, bullA = false, bullS = false, bullD = false;
	int  bulletNo[3] = { 0, 0, 0}, bullOrder = 0;
	bool bull1State = false, bull2State = false, bull3State = false;
	
	//Bullet > > 1//

	sf::Texture bullet1_tx;
	bullet1_tx.loadFromFile("bullet.png");
	printf("Loading. . .\n");
	if (!bullet1_tx.loadFromFile("bullet.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading bullet Done!\n");
	}
	sf::RectangleShape bullet1(sf::Vector2f(20.0f, 20.0f));
	bullet1.setTexture(&bullet1_tx);
	bullet1.setOrigin(15, 15);
	bool bull1out = false, bull1Col = false;


	//Bullet > > 2//
	
	sf::Texture bullet2_tx;
	bullet2_tx.loadFromFile("bullet2.png");
	printf("Loading. . .\n");
	if (!bullet2_tx.loadFromFile("bullet2.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading bullet Done!\n");
	}
	sf::RectangleShape bullet2(sf::Vector2f(20.0f, 20.0f));
	bullet2.setTexture(&bullet2_tx);
	bullet2.setOrigin(15, 15);
	bool bull2out = false, bull2Col = false;

	//Bullet > > 3//

	sf::Texture bullet3_tx;
	bullet3_tx.loadFromFile("bullet3.png");
	printf("Loading. . .\n");
	if (!bullet3_tx.loadFromFile("bullet3.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading bullet Done!\n");
	}
	sf::RectangleShape bullet3(sf::Vector2f(20.0f, 20.0f));
	bullet3.setTexture(&bullet3_tx);
	bullet3.setOrigin(15, 15);
	bool bull3out = false, bull3Col = false;


	//---------------------------------------level 1----------------------------------------------//



	//**********wall1**********//

	sf::Texture wall1_tx;
	wall1_tx.loadFromFile("wall01.jpg");
	if (!wall1_tx.loadFromFile("wall01.jpg")){
		printf("Loading. . .\n");
	}
	else {
		printf("Loading wall 01 done!\n");
	}
	sf::RectangleShape wall1(sf::Vector2f(600,150));
	wall1.setPosition(0, 310);
	wall1.setTexture(&wall1_tx);
	sf::Vector2f wall1Pos = wall1.getPosition();

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
	sf::Vector2f wall2Pos = wall2.getPosition();
	
	//**********wall3**********//

	sf::RectangleShape wall3(sf::Vector2f(100, 400));
	wall3.setPosition(700, 500);
	wall3.setFillColor(sf::Color(0, 0, 0));
	sf::Vector2f wall3Pos = wall3.getPosition();

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
	sf::Vector2f wall4Pos = wall4.getPosition();

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
	sf::Vector2f wall5Pos = wall5.getPosition();


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
	sf::Vector2f enemyLV101Position = enemy01.getPosition();
	int  enemyMaxX = 0;
	float enemyPosX = 0, enemy01FrameX = 0, enemy01FrameY = 9;
	bool enemy1SetState = true;
	int enemy1Life = 3;

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
	bool enemy2SetState = true;
	int enemy2Life = 3;

	//**********Democrac Level 1**********//

	sf::Texture democrac_tx;
	democrac_tx.loadFromFile("Democrac mk2.png");
	if (!democrac_tx.loadFromFile("Democrac mk2.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Democrac Done!\n");
	}
	sf::Texture DemocracLV1_tx;
	sf::RectangleShape DemocracLV1(sf::Vector2f(80.0f, 80.0f));
	DemocracLV1.setTexture(&democrac_tx);
	sf::Vector2u DemocracLV1TextureSize = democrac_tx.getSize();
	int democracSizeX = DemocracLV1TextureSize.x / 10;
	int democracSizeY = DemocracLV1TextureSize.y / 1;
	DemocracLV1.setTextureRect(sf::IntRect(democracSizeX * 0, democracSizeY * 0, democracSizeX, democracSizeY));
	DemocracLV1.setPosition(50, 150);
	float animateDemocracFrame = 0;

	//**********Door Level 1**********//
	
	sf::RectangleShape DoorLV1(sf::Vector2f(50.0f, 200.0f));
	DoorLV1.setPosition(225, 125);
	DoorLV1.setFillColor(sf::Color(0, 0, 0));
	sf::Vector2f DoorLV1Pos = DoorLV1.getPosition();
	bool DoorLV1Check = false;

	//**********Key Level 1**********//

	sf::Texture KeyLV1_tx;
	KeyLV1_tx.loadFromFile("Key LV1.png");
	if (!KeyLV1_tx.loadFromFile("Key LV1.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Key LV1 Done!\n");
	}
	
	sf::RectangleShape KeyLV1(sf::Vector2f(50.0f, 50.0f));
	KeyLV1.setTexture(&KeyLV1_tx);
	sf::Vector2u KeyLV1TextureSize = KeyLV1_tx.getSize();
	int KeyLV1SizeX = KeyLV1TextureSize.x / 14;
	int KeyLV1SizeY = KeyLV1TextureSize.y / 1;
	KeyLV1.setTextureRect(sf::IntRect(KeyLV1SizeX * 0, KeyLV1SizeY * 0, KeyLV1SizeX, KeyLV1SizeY));
	KeyLV1.setPosition(1100, 150);
	KeyLV1.setOrigin(25, 25);
	bool KeyLV1Check = false;
	float animateKeyLV1Frame = 0;


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
	sf::Vector2f wallLV201Pos = wallLV201.getPosition();


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
	sf::Vector2f wallLV202Pos = wallLV202.getPosition();

	//**********wall3**********//

	sf::RectangleShape wallLV203(sf::Vector2f(100, 400));
	wallLV203.setPosition(400, 600);
	wallLV203.setFillColor(sf::Color(0, 0, 0));
	sf::Vector2f wallLV203Pos = wallLV203.getPosition();

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

	//**********Gate2**********//

	sf::Texture GateLV2_tx;
	GateLV2_tx.loadFromFile("gate.png");
	if (!GateLV2_tx.loadFromFile("gate.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Gate Done!\n");
	}
	sf::RectangleShape GateLV2(sf::Vector2f(100.0f, 80.0f));
	GateLV2.setTexture(&GateLV2_tx);
	sf::Vector2u GateLV2TextureSize = GateLV2_tx.getSize();
	int GateLV2SizeX = GateLV2TextureSize.x / 8;
	int GateLV2SizeY = GateLV2TextureSize.y / 1;
	GateLV2.setTextureRect(sf::IntRect(GateLV2SizeX * 0, GateLV2SizeY * 0, GateLV2SizeX, GateLV2SizeY));
	GateLV2.setPosition(1100, 80);
	float animateGateLV2Frame = 0;


	//**********Stage2**********//

	//**********Wall4**********//

	sf::RectangleShape wallLV204(sf::Vector2f(300, 600));
	wallLV204.setPosition(200,300);
	wallLV204.setFillColor(sf::Color(0, 0, 0));
	sf::Vector2f wallLV204Pos = wallLV204.getPosition();


	//**********DoorLV2**********//

	sf::RectangleShape DoorLV2(sf::Vector2f(50, 720));
	DoorLV2.setPosition(900, 0);
	DoorLV2.setFillColor(sf::Color(0, 0, 0));
	sf::Vector2f DoorLV2Pos = DoorLV2.getPosition();
	bool DoorLV2Check = false;

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

	//**********DemocracLevel 2**********//

	sf::Texture DemocracLV2_tx;
	DemocracLV2_tx.loadFromFile("Democrac mk2 LV2.png");
	if (!DemocracLV2_tx.loadFromFile("Democrac mk2 LV2.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Democrac Done!\n");
	}
	sf::RectangleShape DemocracLV2(sf::Vector2f(80.0f, 80.0f));
	DemocracLV2.setTexture(&DemocracLV2_tx);
	sf::Vector2u DemocracLV2TextureSize = DemocracLV2_tx.getSize();
	int democracLV2SizeX = DemocracLV2TextureSize.x / 10;
	int democracLV2SizeY = DemocracLV2TextureSize.y / 1;
	DemocracLV2.setTextureRect(sf::IntRect(democracLV2SizeX * 0, democracLV2SizeY * 0, democracLV2SizeX, democracLV2SizeY));
	DemocracLV2.setPosition(1100, 150);
	float animateDemocracLV2Frame = 0;

	//**********KeyLevel 2**********//
	
	sf::Texture KeyLV2_tx;
	KeyLV2_tx.loadFromFile("Key LV2.png");
	if (!KeyLV2_tx.loadFromFile("Key LV2.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Key LV2 Done!\n");
	}

	sf::RectangleShape KeyLV2(sf::Vector2f(50.0f, 50.0f));
	KeyLV2.setTexture(&KeyLV2_tx);
	sf::Vector2u KeyLV2TextureSize = KeyLV2_tx.getSize();
	int KeyLV2SizeX = KeyLV2TextureSize.x / 14;
	int KeyLV2SizeY = KeyLV2TextureSize.y / 1;
	KeyLV2.setTextureRect(sf::IntRect(KeyLV2SizeX * 0, KeyLV2SizeY * 0, KeyLV2SizeX, KeyLV2SizeY));
	KeyLV2.setPosition(600, 600);
	bool KeyLV2Check = false;
	KeyLV2.setOrigin(25, 25);
	float animateKeyLV2Frame = 0;
	


	//---------------------------------------level 3----------------------------------------------//



	//**********wall1**********//

	sf::RectangleShape wallLV301(sf::Vector2f(200, 600));
	wallLV301.setPosition(200, 300);
	wallLV301.setFillColor(sf::Color(0, 0, 0));
	sf::Vector2f wallLV301Pos = wallLV301.getPosition();

	//**********wall2**********//

	sf::Texture wallLV302_tx;
	wallLV302_tx.loadFromFile("wallLV302.jpg");
	if (!wallLV302_tx.loadFromFile("wallLV302.jpg")) {
		printf("loading. . .\n");
	}
	else {
		printf("Loading wallLV302 done!\n");
	}
	sf::RectangleShape wallLV302(sf::Vector2f(100, 200));
	wallLV302.setTexture(&wallLV302_tx);
	wallLV302.setPosition(300, 0);
	sf::Vector2f wallLV302Pos = wallLV302.getPosition();


	//**********wall3**********//

	sf::Texture wallLV303_tx;
	wallLV303_tx.loadFromFile("wallLV303.jpg");
	if (!wallLV303_tx.loadFromFile("wallLV303.jpg")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading wallLV303 done!\n");
	}
	sf::RectangleShape wallLV303(sf::Vector2f(500, 150));
	wallLV303.setPosition(400, 300);
	wallLV303.setTexture(&wallLV303_tx);
	sf::Vector2f wallLV303Pos = wallLV303.getPosition();

	//**********Enemy01**********//

	sf::Texture enemyLV301_tx;
	enemyLV301_tx.loadFromFile("EnemyLV301.png");
	if (!enemyLV301_tx.loadFromFile("EnemyLV301.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV301 Done!\n");
	}
	sf::RectangleShape enemyLV301(sf::Vector2f(100.0f, 100.0f));
	enemyLV301.setTexture(&enemyLV301_tx);
	sf::Vector2u enemyLV301TextureSize = enemyLV301_tx.getSize();
	int enemyLV301SizeX = enemyLV301TextureSize.x / 13;
	int enemyLV301SizeY = enemyLV301TextureSize.y / 21;
	enemyLV301.setTextureRect(sf::IntRect(enemyLV301SizeX * 2, enemyLV301SizeY * 2, enemyLV301SizeX, enemyLV301SizeY));
	enemyLV301.setPosition(500, 200);
	int  enemyLV301MaxX = 0;
	float enemyLV301PosX = 0, enemyLV301FrameX = 0, enemyLV301FrameY = 9;

	//**********Enemy02**********//

	sf::Texture enemyLV302_tx;
	enemyLV302_tx.loadFromFile("EnemyLV302.png");
	if (!enemyLV302_tx.loadFromFile("EnemyLV302.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV302 Done!\n");
	}
	sf::RectangleShape enemyLV302(sf::Vector2f(100.0f, 100.0f));
	enemyLV302.setTexture(&enemyLV302_tx);
	sf::Vector2u enemyLV302TextureSize = enemyLV302_tx.getSize();
	int enemyLV302SizeX = enemyLV302TextureSize.x / 13;
	int enemyLV302SizeY = enemyLV302TextureSize.y / 21;
	enemyLV302.setTextureRect(sf::IntRect(enemyLV302SizeX * 2, enemyLV302SizeY * 2, enemyLV302SizeX, enemyLV302SizeY));
	enemyLV302.setPosition(1000, 600);
	int  enemyLV302MaxY = 0;
	float enemyLV302PosY = 0, enemyLV302FrameX = 0, enemyLV302FrameY = 8;


	//**********Democrac Level 3**********//

	sf::Texture DemocracLV3_tx;
	DemocracLV3_tx.loadFromFile("Democrac mk2 LV3.png");
	if (!DemocracLV3_tx.loadFromFile("Democrac mk2 LV3.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Democrac Done!\n");
	}
	sf::RectangleShape DemocracLV3(sf::Vector2f(80.0f, 80.0f));
	DemocracLV3.setTexture(&DemocracLV3_tx);
	sf::Vector2u DemocracLV3TextureSize = DemocracLV3_tx.getSize();
	int democracLV3SizeX = DemocracLV3TextureSize.x / 10;
	int democracLV3SizeY = DemocracLV3TextureSize.y / 1;
	DemocracLV3.setTextureRect(sf::IntRect(democracLV3SizeX * 0, democracLV3SizeY * 0, democracLV3SizeX, democracLV3SizeY));
	DemocracLV3.setPosition(500, 550);
	float animateDemocracLV3Frame = 0;

	//---------------------------------------level 4----------------------------------------------//

	

	//**********Stage1**********//

	//**********wall1**********//

	sf::Texture wallLV401_tx;
	wallLV401_tx.loadFromFile("wallLV401.jpg");
	if (!wallLV401_tx.loadFromFile("wallLV401.jpg")) {
		printf("loading. . .\n");
	}
	else {
		printf("Loading wallLV401 done!\n");
	}
	sf::RectangleShape wallLV401(sf::Vector2f(900, 150));
	wallLV401.setTexture(&wallLV401_tx);
	wallLV401.setPosition(0, 400);
	sf::Vector2f wallLV401Pos= wallLV401.getPosition();
	
	//**********wall2**********//

	sf::Texture wallLV402_tx;
	wallLV402_tx.loadFromFile("wallLV402.jpg");
	if (!wallLV402_tx.loadFromFile("wallLV402.jpg")) {
		printf("loading. . .\n");
	}
	else {
		printf("Loading wallLV402 done!\n");
	}
	sf::RectangleShape wallLV402(sf::Vector2f(100, 200));
	wallLV402.setTexture(&wallLV402_tx);
	wallLV402.setPosition(300, 0);
	sf::Vector2f wallLV402Pos = wallLV402.getPosition();

	//**********Enemy01**********//

	sf::Texture enemyLV401_tx;
	enemyLV401_tx.loadFromFile("EnemyLV401.png");
	if (!enemyLV401_tx.loadFromFile("EnemyLV401.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV401 Done!\n");
	}
	sf::RectangleShape enemyLV401(sf::Vector2f(100.0f, 100.0f));
	enemyLV401.setTexture(&enemyLV401_tx);
	sf::Vector2u enemyLV401TextureSize = enemyLV401_tx.getSize();
	int enemyLV401SizeX = enemyLV401TextureSize.x / 13;
	int enemyLV401SizeY = enemyLV401TextureSize.y / 21;
	enemyLV401.setTextureRect(sf::IntRect(enemyLV401SizeX * 2, enemyLV401SizeY * 2, enemyLV401SizeX, enemyLV401SizeY));
	enemyLV401.setPosition(1000, 600);
	int  enemyLV401MaxX = 0;
	float enemyLV401PosX = 0, enemyLV401FrameX = 0, enemyLV401FrameY = 9;

	//**********Enemy02**********//

	sf::Texture enemyLV402_tx;
	enemyLV402_tx.loadFromFile("EnemyLV402.png");
	if (!enemyLV402_tx.loadFromFile("EnemyLV402.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV402 Done!\n");
	}
	sf::RectangleShape enemyLV402(sf::Vector2f(100.0f, 100.0f));
	enemyLV402.setTexture(&enemyLV402_tx);
	sf::Vector2u enemyLV402TextureSize = enemyLV402_tx.getSize();
	int enemyLV402SizeX = enemyLV402TextureSize.x / 13;
	int enemyLV402SizeY = enemyLV402TextureSize.y / 21;
	enemyLV402.setTextureRect(sf::IntRect(enemyLV402SizeX * 2, enemyLV402SizeY * 2, enemyLV402SizeX, enemyLV402SizeY));
	enemyLV402.setPosition(1000, 450);
	int  enemyLV402MaxY = 0;
	float enemyLV402PosY = 0, enemyLV402FrameX = 0, enemyLV402FrameY = 8;

	//**********Gate4**********//

	sf::Texture GateLV4_tx;
	GateLV4_tx.loadFromFile("gate4.png");
	if (!GateLV4_tx.loadFromFile("gate4.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Gate Done!\n");
	}
	sf::RectangleShape GateLV4(sf::Vector2f(100.0f, 80.0f));
	GateLV4.setTexture(&GateLV4_tx);
	sf::Vector2u GateLV4TextureSize = GateLV4_tx.getSize();
	int GateLV4SizeX = GateLV4TextureSize.x / 8;
	int GateLV4SizeY = GateLV4TextureSize.y / 1;
	GateLV4.setTextureRect(sf::IntRect(GateLV4SizeX * 0, GateLV4SizeY * 0, GateLV4SizeX, GateLV4SizeY));
	GateLV4.setPosition(100, 150);
	float animateGateLV4Frame = 0;

	//**********Stage2**********//



	//**********Enemy03**********//

	sf::Texture enemyLV403_tx;
	enemyLV403_tx.loadFromFile("EnemyLV403.png");
	if (!enemyLV403_tx.loadFromFile("EnemyLV403.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV403 Done!\n");
	}
	sf::RectangleShape enemyLV403(sf::Vector2f(100.0f, 100.0f));
	enemyLV403.setTexture(&enemyLV403_tx);
	sf::Vector2u enemyLV403TextureSize = enemyLV403_tx.getSize();
	int enemyLV403SizeX = enemyLV403TextureSize.x / 13;
	int enemyLV403SizeY = enemyLV403TextureSize.y / 21;
	enemyLV403.setTextureRect(sf::IntRect(enemyLV403SizeX * 2, enemyLV403SizeY * 2, enemyLV403SizeX, enemyLV403SizeY));
	enemyLV403.setPosition(300, 500);
	int  enemyLV403MaxY = 0;
	float enemyLV403PosY = 0, enemyLV403FrameX = 0, enemyLV403FrameY = 8;

	//**********Enemy04**********//

	sf::Texture enemyLV404_tx;
	enemyLV404_tx.loadFromFile("EnemyLV404.png");
	if (!enemyLV404_tx.loadFromFile("EnemyLV404.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading EnemyLV404 Done!\n");
	}
	sf::RectangleShape enemyLV404(sf::Vector2f(100.0f, 100.0f));
	enemyLV404.setTexture(&enemyLV404_tx);
	sf::Vector2u enemyLV404TextureSize = enemyLV404_tx.getSize();
	int enemyLV404SizeX = enemyLV404TextureSize.x / 13;
	int enemyLV404SizeY = enemyLV404TextureSize.y / 21;
	enemyLV404.setTextureRect(sf::IntRect(enemyLV404SizeX * 2, enemyLV404SizeY * 2, enemyLV404SizeX, enemyLV404SizeY));
	enemyLV404.setPosition(600, 100);
	int  enemyLV404MaxY = 0;
	float enemyLV404PosY = 0, enemyLV404FrameX = 0, enemyLV404FrameY = 10;


	//**********Democrac Level 4**********//

	sf::Texture DemocracLV4_tx;
	DemocracLV4_tx.loadFromFile("Democrac mk2 LV4.png");
	if (!DemocracLV4_tx.loadFromFile("Democrac mk2 LV4.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Democrac Done!\n");
	}
	sf::RectangleShape DemocracLV4(sf::Vector2f(80.0f, 80.0f));
	DemocracLV4.setTexture(&DemocracLV4_tx);
	sf::Vector2u DemocracLV4TextureSize = DemocracLV4_tx.getSize();
	int democracLV4SizeX = DemocracLV4TextureSize.x / 10;
	int democracLV4SizeY = DemocracLV4TextureSize.y / 1;
	DemocracLV4.setTextureRect(sf::IntRect(democracLV4SizeX * 0, democracLV4SizeY * 0, democracLV4SizeX, democracLV4SizeY));
	DemocracLV4.setPosition(900, 350);
	float animateDemocracLV4Frame = 0;

	//scanf_s("%d", &n);




	/*#########################################################################################################

													Heart

	###########################################################################################################*/

	int imortalTime = 0;
	//1

	sf::Texture heart1_tx;
	heart1_tx.loadFromFile("Heart 1.png");
	if (!heart1_tx.loadFromFile("Heart 1.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Heart 1 Done!\n");
	}
	sf::RectangleShape heart1(sf::Vector2f(25.0f, 25.0f));
	heart1.setTexture(&heart1_tx);
	heart1.setPosition(10, 10);
	bool heart1Check = true;

	//2

	sf::Texture heart2_tx;
	heart2_tx.loadFromFile("Heart 2.png");
	if (!heart2_tx.loadFromFile("Heart 2.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Heart 2 Done!\n");
	}
	sf::RectangleShape heart2(sf::Vector2f(25.0f, 25.0f));
	heart2.setTexture(&heart2_tx);
	heart2.setPosition(50, 10);
	bool heart2Check = true;

	//3

	sf::Texture heart3_tx;
	heart3_tx.loadFromFile("Heart 3.png");
	if (!heart3_tx.loadFromFile("Heart 3.png")) {
		printf("Loading. . .\n");
	}
	else {
		printf("Loading Heart 3 Done!\n");
	}
	sf::RectangleShape heart3(sf::Vector2f(25.0f, 25.0f));
	heart3.setTexture(&heart3_tx);
	heart3.setPosition(90, 10);
	bool heart3Check = true;

	//####################################Timer##############################################//


	sf::Clock clock;
	sf::Font font;
	sf::Text timerClock;
	font.loadFromFile("arial.ttf");
	timerClock.setFont(font);
	timerClock.setCharacterSize(40);
	timerClock.setFillColor(sf::Color::White);
	sf::Text time;
	time.setFont(font);
	time.setCharacterSize(40);
	time.setFillColor(sf::Color::White);
	time.setString("Time : ");
	time.setPosition(750, 0);
	sf::Text unit;
	unit.setFont(font);
	unit.setCharacterSize(40);
	unit.setFillColor(sf::Color::White);
	unit.setString("sec");
	unit.setPosition(1100, 0);



	/**********************************************************************************************************

	-----------------------------------------------------------------------------------------------------------

	-----------------------------------------> > Loop Zone < <-------------------------------------------------
	
	-----------------------------------------------------------------------------------------------------------

	***********************************************************************************************************/



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (lv1ch == true) {
			player.setPosition(20, 600);
			lv1ch = false;
			KeyLV1Check = false;
		}

		//###########################################Clock###################################################//


		sf::Time timer = clock.getElapsedTime();
		printf("timer %f\n", timer.asSeconds());
		char timetext[100];
		if (timer.asSeconds() > 10) {
			_gcvt_s(timetext, 100, timer.asSeconds(), 6);
		}
		else {
			_gcvt_s(timetext, 100, timer.asSeconds(), 4);
		}
		timerClock.setString(timetext);
		timerClock.setPosition(900, 0);


		//Set Status//


		if (n == 1) {
			if (enemy1SetState == true) {
				enemy1Life = 3;
				enemy1SetState = false;
			}
			if (enemy2SetState == true) {
				enemy2Life = 3;
				enemy2SetState = false;
			}
		}

		/*------------------------------------------------------------------------------------------------------------------------

		-------------------------------------------- //Collision Check Zone// ----------------------------------------------------

		------------------------------------------------------------------------------------------------------------------------*/

		sf::Vector2f playerPosition = player.getPosition();
		sf::Vector2f bull1Pos = bullet1.getPosition();
		sf::Vector2f bull2Pos = bullet2.getPosition();
		sf::Vector2f bull3Pos = bullet3.getPosition();
		bool w = true, a = true, s = true, d = true;


		//collison with edge//

		if (playerPosition.x <= -20) {
			a = false;
		}
		if (playerPosition.x > 1160 || bull1Pos.x > 1160 || bull2Pos.x > 1160 || bull3Pos.x > 1160) {
			d = false;
		}
		if (playerPosition.y >= 620) {
			s = false;
		}

		if (bull1Pos.x <= -20 || bull1Pos.x > 1240 || bull1Pos.y >= 720 || bull1Pos.y < 0) {
			bull1out = false;
			bull1Col = false;
			bullet1.setPosition(0, 0);
		}

		if (bull2Pos.x <= -20 || bull2Pos.x > 1240 || bull2Pos.y >= 720 || bull2Pos.y < 0) {
			bull2out = false;
			bull2Col = false;
			bullet2.setPosition(0, 0);
		}

		if (bull3Pos.x <= -20 || bull3Pos.x > 1240 || bull3Pos.y >= 720 || bull3Pos.y < 0) {
			bull3out = false;
			bull3Col = false;
			bullet3.setPosition(0, 0);
		}

		//collision with walls check//



		if ((playerPosition.y < walltopPos.y + 20)) {
			w = false;
		}

		//LEVEL 1//

		if (n == 1) {

			//Level1 > > wall1//

			if ((playerPosition.y < wall1Pos.y + 75 && playerPosition.y>wall1Pos.y) && (playerPosition.x < wall1Pos.x + 570)) {
				w = false;
				//printf("w\n");
			}
			if ((playerPosition.y < wall1Pos.y + 40 && playerPosition.y > wall1Pos.y - 80) && (playerPosition.x < wall1Pos.x + 570)) {
				s = false;
				//printf("s\n");
			}
			if ((playerPosition.y<wall1Pos.y + 75 && playerPosition.y > wall1Pos.y - 80) && (playerPosition.x < wall1Pos.x + 580 && playerPosition.x > wall1Pos.x + 570)) {
				a = false;
				//printf("a\n");
			}

			//Level1 > > wall2//

			if ((playerPosition.y < wall2Pos.y + 75 && playerPosition.y > wall2Pos.y) && (playerPosition.x > wall2Pos.x - 70)) {
				w = false;
				//printf("w1\n");
			}
			if ((playerPosition.y < wall2Pos.y + 40 && playerPosition.y > wall2Pos.y - 80) && (playerPosition.x > wall2Pos.x - 70)) {
				s = false;
				//printf("s1\n");
			}
			if ((playerPosition.y<wall2Pos.y + 75 && playerPosition.y > wall2Pos.y - 80) && (playerPosition.x < wall2Pos.x - 70 && playerPosition.x > wall2Pos.x - 80)) {
				d = false;
				//printf("d1\n");
			}

			//Level1 > > wall3//

			if ((playerPosition.y < wall3Pos.y + 40 && playerPosition.y > wall3Pos.y - 80) && (playerPosition.x > wall3Pos.x - 70 && playerPosition.x < wall3Pos.x + 70)) {
				s = false;
				//printf("d2\n");
			}
			if ((playerPosition.y > wall3Pos.y - 80) && (playerPosition.x < wall3Pos.x - 70 && playerPosition.x > wall3Pos.x - 80)) {
				d = false;
				//printf("d2\n");
			}
			if ((playerPosition.y > wall3Pos.y - 80) && (playerPosition.x > wall3Pos.x + 70 && playerPosition.x < wall3Pos.x + 80)) {
				a = false;
				//printf("a2\n");
			}

			//Level1 > > wall4//

			if ((playerPosition.y < wall4Pos.y + 130) && (playerPosition.x > wall4Pos.x - 70 && playerPosition.x < wall4Pos.x + 70)) {
				w = false;
				//printf("w\n");
			}
			if ((playerPosition.y < wall4Pos.y + 130) && (playerPosition.x < wall4Pos.x - 70 && playerPosition.x > wall4Pos.x - 80)) {
				d = false;
				//printf("d\n");
			}
			if ((playerPosition.y < wall4Pos.y + 130) && (playerPosition.x > wall4Pos.x + 70 && playerPosition.x < wall4Pos.x + 80)) {
				a = false;
				//printf("a\n");
			}

			//Level1 > > wall5//

			if ((playerPosition.y < wall5Pos.y + 130) && (playerPosition.x > wall5Pos.x - 70 && playerPosition.x < wall5Pos.x + 70)) {
				w = false;
				//printf("w\n");
			}
			if ((playerPosition.y < wall5Pos.y + 130) && (playerPosition.x < wall5Pos.x - 70 && playerPosition.x > wall5Pos.x - 80)) {
				d = false;
				//printf("d\n");
			}
			if ((playerPosition.y < wall5Pos.y + 130) && (playerPosition.x > wall5Pos.x + 70 && playerPosition.x < wall5Pos.x + 80)) {
				a = false;
				//printf("a\n");
			}

			//Level1 > > Door//

			if (DoorLV1Check == false) {
				if ((playerPosition.y < DoorLV1Pos.y + 150) && (playerPosition.x < DoorLV1Pos.x + 40 && playerPosition.x > DoorLV1Pos.x + 30)) {
					a = false;
					//printf("d2\n");
				}
			}

			//Level1 > > Democrac//

			if (player.getGlobalBounds().intersects(DemocracLV1.getGlobalBounds())) {
				n = 2;
				player.setPosition(20, 600);
			}

			//Level1 > > Key//

			if (KeyLV1Check == false) {
				if (player.getGlobalBounds().intersects(KeyLV1.getGlobalBounds())) {
					KeyLV1Check = true;
					DoorLV1Check = true;
				}
			}

			//Level1 > > Enemy 1//
			/*if ((playerPosition.y + 100 >= enemyLV101Position.y || playerPosition.y <= enemyLV101Position.y + 100) && (playerPosition.x + 70 >= enemyLV101Position.x + 30 || playerPosition.x + 30 <= enemyLV101Position.y + 70)) {
				//printf("chonlaew");
			}*/

			// bullet collision //

			//bullet 1//

			if ((bullet1.getGlobalBounds().intersects(wall1.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wall2.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wall3.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wall4.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wall5.getGlobalBounds()))

				) {
				bull1out = false;
				bull1Col = false;
				bullet1.setPosition(0, 0);
			}
			if (DoorLV1Check == false) {
				if (bullet1.getGlobalBounds().intersects(DoorLV1.getGlobalBounds())) {
					bull1out = false;
					bull1Col = false;
					bullet1.setPosition(0, 0);
				}
			}

			//bullet 2//

			if ((bullet2.getGlobalBounds().intersects(wall1.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wall2.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wall3.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wall4.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wall5.getGlobalBounds()))
				) {
				bull2out = false;
				bull2Col = false;
				bullet2.setPosition(0, 0);
			}
			if (DoorLV1Check == false) {
				if (bullet2.getGlobalBounds().intersects(DoorLV1.getGlobalBounds())) {
					bull2out = false;
					bull2Col = false;
					bullet2.setPosition(0, 0);
				}
			}

			//bullet 3//

			if ((bullet3.getGlobalBounds().intersects(wall1.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wall2.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wall3.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wall4.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wall5.getGlobalBounds()))
				) {
				bull3out = false;
				bull3Col = false;
				bullet3.setPosition(0, 0);
			}
			if (DoorLV1Check == false) {
				if (bullet3.getGlobalBounds().intersects(DoorLV1.getGlobalBounds())) {
					bull3out = false;
					bull3Col = false;
					bullet3.setPosition(0, 0);
				}
			}

			//Level 1 > > bullet > > Enemy1//

			if (bullet1.getGlobalBounds().intersects(enemy01.getGlobalBounds())) {
				bull1out = false;
				bull1Col = false;
				bullet1.setPosition(0, 0);
				enemy1Life -= 1;
				printf("hit - enemyLife = %d\n",enemy1Life);
			}
			if (bullet2.getGlobalBounds().intersects(enemy01.getGlobalBounds())) {
				bull2out = false;
				bull2Col = false;
				bullet2.setPosition(0, 0);
				enemy1Life -= 1;
				printf("hit - enemyLife = %d\n", enemy1Life);
			}
			if (bullet3.getGlobalBounds().intersects(enemy01.getGlobalBounds())) {
				bull3out = false;
				bull3Col = false;
				bullet3.setPosition(0, 0);
				enemy1Life -= 1;
				printf("hit - enemyLife = %d\n", enemy1Life);
			}

			//Level 1 > > bullet > > Enemy2//

			if (bullet1.getGlobalBounds().intersects(enemy02.getGlobalBounds())) {
				bull1out = false;
				bull1Col = false;
				bullet1.setPosition(0, 0);
				enemy2Life -= 1;
				printf("hit - enemyLife = %d\n", enemy2Life);
			}
			if (bullet2.getGlobalBounds().intersects(enemy02.getGlobalBounds())) {
				bull2out = false;
				bull2Col = false;
				bullet2.setPosition(0, 0);
				enemy2Life -= 1;
				printf("hit - enemyLife = %d\n", enemy2Life);
			}
			if (bullet3.getGlobalBounds().intersects(enemy02.getGlobalBounds())) {
				bull3out = false;
				bull3Col = false;
				bullet3.setPosition(0, 0);
				enemy2Life -= 1;
				printf("hit - enemyLife = %d\n", enemy2Life);
			}
		}
			

		//LEVEL 2//

		//stage 1//

		if (n == 2) {

			//Level2 > > wall2//

			if ((playerPosition.y < wallLV201Pos.y + 75 && playerPosition.y>wallLV201Pos.y) && (playerPosition.x < wallLV201Pos.x + 975)) {
				w = false;
				//printf("w\n");
			}
			if ((playerPosition.y < wallLV201Pos.y + 40 && playerPosition.y > wallLV201Pos.y - 80) && (playerPosition.x < wallLV201Pos.x + 975)) {
				s = false;
				//printf("s\n");
			}
			if ((playerPosition.y<wallLV201Pos.y + 75 && playerPosition.y > wallLV201Pos.y - 80) && (playerPosition.x < wallLV201Pos.x + 985 && playerPosition.x > wallLV201Pos.x + 975)) {
				a = false;
				//printf("a\n");
			}

			//Level2 > > wall2//

			if ((playerPosition.y < wallLV202Pos.y + 75 && playerPosition.y > wallLV202Pos.y) && (playerPosition.x > wallLV202Pos.x - 70)) {
				w = false;
				//printf("w1\n");
			}
			if ((playerPosition.y < wallLV202Pos.y + 40 && playerPosition.y > wallLV202Pos.y - 80) && (playerPosition.x > wallLV202Pos.x - 70)) {
				s = false;
				//printf("s1\n");
			}
			if ((playerPosition.y < wallLV202Pos.y + 75 && playerPosition.y > wallLV202Pos.y - 80) && (playerPosition.x < wallLV202Pos.x - 70 && playerPosition.x > wallLV202Pos.x - 80)) {
				d = false;
				//printf("d1\n");
			}

			//Level2 > > wall3//

			if ((playerPosition.y < wallLV203Pos.y + 40 && playerPosition.y > wallLV203Pos.y - 80) && (playerPosition.x > wallLV203Pos.x - 70 && playerPosition.x < wallLV203Pos.x + 70)) {
				s = false;
				//printf("d2\n");
			}
			if ((playerPosition.y > wallLV203Pos.y - 80) && (playerPosition.x < wallLV203Pos.x - 70 && playerPosition.x > wallLV203Pos.x - 80)) {
				d = false;
				//printf("d2\n");
			}
			if ((playerPosition.y > wallLV203Pos.y - 80) && (playerPosition.x > wallLV203Pos.x + 70 && playerPosition.x < wallLV203Pos.x + 80)) {
				a = false;
				//printf("a2\n");
			}

			//Level2 > > Gate//

			if (player.getGlobalBounds().intersects(GateLV2.getGlobalBounds())) {
				n = 3;
				player.setPosition(20, 600);
			}

			// bullet collision //

			//bullet 1//

			if ((bullet1.getGlobalBounds().intersects(wallLV201.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wallLV202.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wallLV203.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(enemyLV201.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(enemyLV202.getGlobalBounds()))) {
				bull1out = false;
				bullet1.setPosition(0, 0);
			}

			//bullet 2//

			if ((bullet2.getGlobalBounds().intersects(wallLV201.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wallLV202.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wallLV203.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(enemyLV201.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(enemyLV202.getGlobalBounds()))) {
				bull2out = false;
				bullet2.setPosition(0, 0);
			}
			//bullet 3//

			if ((bullet3.getGlobalBounds().intersects(wallLV201.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wallLV202.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wallLV203.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(enemyLV201.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(enemyLV202.getGlobalBounds()))) {
				bull3out = false;
				bullet3.setPosition(0, 0);
			}

		}

		//stage 2//

		if (n == 3) {

			//Level1 > > wall3//

			if ((playerPosition.y < wallLV204Pos.y + 40 && playerPosition.y > wallLV204Pos.y - 80) && (playerPosition.x > wallLV204Pos.x - 70 && playerPosition.x < wallLV204Pos.x + 270)) {
				s = false;
				//printf("d2\n");
			}
			if ((playerPosition.y > wallLV204Pos.y - 80) && (playerPosition.x < wallLV204Pos.x - 70 && playerPosition.x > wallLV204Pos.x - 80)) {
				d = false;
				//printf("d2\n");
			}
			if ((playerPosition.y > wallLV204Pos.y - 80) && (playerPosition.x > wallLV204Pos.x + 270 && playerPosition.x < wallLV204Pos.x + 280)) {
				a = false;
				//printf("a2\n");

			}

			//Level2 > > Door//

			if (DoorLV2Check == false) {
				if ((playerPosition.y > DoorLV2Pos.y - 80) && (playerPosition.x < DoorLV2Pos.x - 70 && playerPosition.x > DoorLV2Pos.x - 80)) {
					d = false;
					//printf("d2\n");
				}
			}

			//Level2 > > Democrac//

			if (player.getGlobalBounds().intersects(DemocracLV2.getGlobalBounds())) {
				n = 4;
				player.setPosition(20, 600);
			}

			//Level 2 >> Key//

			if (KeyLV2Check == false) {
				if (player.getGlobalBounds().intersects(KeyLV2.getGlobalBounds())) {
					KeyLV2Check = true;
					DoorLV2Check = true;
				}
			}

			// bullet collision //

			//bullet 1//

			if ((bullet1.getGlobalBounds().intersects(wallLV204.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(enemyLV203.getGlobalBounds()))) {
				bull1out = false;
				bullet1.setPosition(0, 0);
			}
			if (DoorLV2Check == false) {
				if ((bullet1.getGlobalBounds().intersects(DoorLV2.getGlobalBounds()))) {
					bull1out = false;
					bullet1.setPosition(0, 0);
				}
			}

			//bullet 2//

			if ((bullet2.getGlobalBounds().intersects(wallLV204.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(enemyLV203.getGlobalBounds()))) {
				bull2out = false;
				bullet2.setPosition(0, 0);
			}
			if (DoorLV2Check == false) {
				if ((bullet2.getGlobalBounds().intersects(DoorLV2.getGlobalBounds()))) {
					bull2out = false;
					bullet2.setPosition(0, 0);
				}
			}

			//bullet 3//

			if ((bullet3.getGlobalBounds().intersects(wallLV204.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(enemyLV203.getGlobalBounds()))) {
				bull3out = false;
				bullet3.setPosition(0, 0);
			}
			if (DoorLV2Check == false) {
				if ((bullet3.getGlobalBounds().intersects(DoorLV2.getGlobalBounds()))) {
					bull3out = false;
					bullet3.setPosition(0, 0);
				}
			}
		}

		//LEVEL 3//

		if (n == 4) {

			//Level3 > > wall1//

			if ((playerPosition.y < wallLV301Pos.y + 40 && playerPosition.y > wallLV301Pos.y - 80) && (playerPosition.x > wallLV301Pos.x - 70 && playerPosition.x < wallLV301Pos.x + 270)) {
				s = false;
				//printf("d2\n");
			}
			if ((playerPosition.y > wallLV301Pos.y - 80) && (playerPosition.x < wallLV301Pos.x - 70 && playerPosition.x > wallLV301Pos.x - 80)) {
				d = false;
				//printf("d2\n");
			}
			if ((playerPosition.y > wallLV301Pos.y - 80) && (playerPosition.x > wallLV301Pos.x + 170 && playerPosition.x < wallLV301Pos.x + 180)) {
				a = false;
				//printf("a2\n");

			}
			//Level3 > > wall2//

			if ((playerPosition.y < wallLV302Pos.y + 130) && (playerPosition.x > wallLV302Pos.x - 70 && playerPosition.x < wallLV302Pos.x + 70)) {
				w = false;
				//printf("w\n");
			}
			if ((playerPosition.y < wallLV302Pos.y + 130) && (playerPosition.x < wallLV302Pos.x - 70 && playerPosition.x > wallLV302Pos.x - 80)) {
				d = false;
				//printf("d\n");
			}
			if ((playerPosition.y < wallLV302Pos.y + 130) && (playerPosition.x > wallLV302Pos.x + 70 && playerPosition.x < wallLV302Pos.x + 80)) {
				a = false;
				//printf("a\n");
			}

			//Level3 > > wall3//

			if ((playerPosition.y < wallLV303Pos.y + 75 && playerPosition.y>wallLV303Pos.y) && (playerPosition.x < wallLV303Pos.x + 470 && playerPosition.x > wallLV303Pos.x - 70)) {
				w = false;
				//printf("w\n");
			}
			if ((playerPosition.y < wallLV303Pos.y + 40 && playerPosition.y > wallLV303Pos.y - 80) && (playerPosition.x < wallLV303Pos.x + 470 && playerPosition.x > wallLV303Pos.x - 70)) {
				s = false;
				//printf("s\n");
			}
			if ((playerPosition.y<wallLV303Pos.y + 75 && playerPosition.y > wallLV303Pos.y - 80) && (playerPosition.x < wallLV303Pos.x + 480 && playerPosition.x > wallLV303Pos.x + 470)) {
				a = false;
				//printf("a\n");
			}

			//Level3 > > Democradc//

			if (player.getGlobalBounds().intersects(DemocracLV3.getGlobalBounds())) {
				n = 5;
				player.setPosition(20, 600);
			}

			// bullet collision //

			//bullet 1//

			if ((bullet1.getGlobalBounds().intersects(wallLV301.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wallLV302.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wallLV303.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(enemyLV301.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(enemyLV302.getGlobalBounds()))) {
				bull1out = false;
				bullet1.setPosition(0, 0);
			}

			//bullet 2//

			if ((bullet2.getGlobalBounds().intersects(wallLV301.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wallLV302.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wallLV303.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(enemyLV301.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(enemyLV302.getGlobalBounds()))) {
				bull2out = false;
				bullet2.setPosition(0, 0);
			}

			//bullet 3//

			if ((bullet3.getGlobalBounds().intersects(wallLV301.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wallLV302.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wallLV303.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(enemyLV301.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(enemyLV302.getGlobalBounds()))) {
				bull3out = false;
				bullet3.setPosition(0, 0);
			}
		}

		//LEVEL 4//

		if (n == 5) {

			//Level4 > > wall1//

			if ((playerPosition.y < wallLV401Pos.y + 75 && playerPosition.y>wallLV401Pos.y) && (playerPosition.x < wallLV401Pos.x + 870)) {
				w = false;
				//printf("w\n");
			}
			if ((playerPosition.y < wallLV401Pos.y + 40 && playerPosition.y > wallLV401Pos.y - 80) && (playerPosition.x < wallLV401Pos.x + 870)) {
				s = false;
				//printf("s\n");
			}
			if ((playerPosition.y<wallLV401Pos.y + 75 && playerPosition.y > wallLV401Pos.y - 80) && (playerPosition.x < wallLV401Pos.x + 880 && playerPosition.x > wallLV401Pos.x + 870)) {
				a = false;
				//printf("a\n");
			}

			//Level4 > > wall2//

			if ((playerPosition.y < wallLV402Pos.y + 130) && (playerPosition.x > wallLV402Pos.x - 70 && playerPosition.x < wallLV402Pos.x + 70)) {
				w = false;
				//printf("w\n");
			}
			if ((playerPosition.y < wallLV402Pos.y + 130) && (playerPosition.x < wallLV402Pos.x - 70 && playerPosition.x > wallLV402Pos.x - 80)) {
				d = false;
				//printf("d\n");
			}
			if ((playerPosition.y < wallLV402Pos.y + 130) && (playerPosition.x > wallLV402Pos.x + 70 && playerPosition.x < wallLV402Pos.x + 80)) {
				a = false;
				//printf("a\n");
			}

			//Level4 > > Gate//

			if (player.getGlobalBounds().intersects(GateLV4.getGlobalBounds())) {
				n = 6;
				player.setPosition(20, 600);
			}

			// bullet collision //

			//bullet 1//

			if ((bullet1.getGlobalBounds().intersects(wallLV401.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(wallLV402.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(enemyLV401.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(enemyLV402.getGlobalBounds()))) {
				bull1out = false;
				bullet1.setPosition(0, 0);
			}

			//bullet 2//

			if ((bullet2.getGlobalBounds().intersects(wallLV401.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(wallLV402.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(enemyLV401.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(enemyLV402.getGlobalBounds()))) {
				bull2out = false;
				bullet2.setPosition(0, 0);
			}

			//bullet 3//

			if ((bullet3.getGlobalBounds().intersects(wallLV401.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(wallLV402.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(enemyLV401.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(enemyLV402.getGlobalBounds()))) {
				bull3out = false;
				bullet3.setPosition(0, 0);
			}
		}
		if (n == 6) {
			// bullet collision //

			//bullet 1//

			if ((bullet1.getGlobalBounds().intersects(enemyLV403.getGlobalBounds()))
				|| (bullet1.getGlobalBounds().intersects(enemyLV404.getGlobalBounds()))) {
				bull1out = false;
				bullet1.setPosition(0, 0);
			}

			//bullet 2//

			if ((bullet2.getGlobalBounds().intersects(enemyLV403.getGlobalBounds()))
				|| (bullet2.getGlobalBounds().intersects(enemyLV404.getGlobalBounds()))) {
				bull2out = false;
				bullet2.setPosition(0, 0);
			}

			//bullet 3//

			if ((bullet3.getGlobalBounds().intersects(enemyLV403.getGlobalBounds()))
				|| (bullet3.getGlobalBounds().intersects(enemyLV404.getGlobalBounds()))) {
				bull3out = false;
				bullet3.setPosition(0, 0);
			}
		}

		// ---------------------------------KeyboardInput------------------------------------// 

		int initialFrame = 0;

		if (KeyD == true) {

			initialFrame = 3;
		}
		else if (KeyA == true) {
			initialFrame = 1;
		}
		else if (KeyW == true) {
			initialFrame = 0;
		}
		else if (KeyS == true) {
			initialFrame = 2;
		}
		player.setTextureRect(sf::IntRect(playerSizeX * 0, playerSizeY * initialFrame, playerSizeX, playerSizeY));

		if (d == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				player.move(4.5f, 0.0f);
				player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 11, playerSizeX, playerSizeY));
				//printf("Keypress : D\n");
				KeyW = false;
				KeyA = false;
				KeyS = false;
				KeyD = true;

			}
		}
		if (a == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				player.move(-4.5f, 0.0f);
				player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 9, playerSizeX, playerSizeY));
				//printf("Keypress : A\n");
				KeyW = false;
				KeyA = true;
				KeyS = false;
				KeyD = false;
			}
		}
		if (w == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				player.move(0.0f, -4.5f);
				player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 8, playerSizeX, playerSizeY));
				//printf("Keypress : W\n");
				KeyW = true;
				KeyA = false;
				KeyS = false;
				KeyD = false;
			}
		}
		if (s == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				player.move(0.0f, 4.5f);
				player.setTextureRect(sf::IntRect(playerSizeX * animationFrame, playerSizeY * 10, playerSizeX, playerSizeY));
				//printf("Keypress : S\n");
				KeyW = false;
				KeyA = false;
				KeyS = true;
				KeyD = false;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			spaceCheck = true;
			//printf("Keypress : Space\n");
		}
		/*if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& !sf::Keyboard::isKeyPressed(sf::Keyboard::A)&& !sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.setTextureRect(sf::IntRect(playerSizeX* animationFrame, playerSizeY * 2, playerSizeX, playerSizeY));
			if (animationFrame >= 2 ) {
				animationFrame = 0;
			}
		}*/
		
		if (spaceCheck == true) {
			skillFrame++;
			player.setTextureRect(sf::IntRect(playerSizeX * skillFrame, playerSizeY * 2, playerSizeX, playerSizeY));
			delay(50);
			if (KeyA == true) {
				bullA = true;
				bullW = false;
				bullS = false;
				bullD = false;
			}
			if (KeyW == true) {
				bullA = false;
				bullW = true;
				bullS = false;
				bullD = false;
			}
			if (KeyD == true) {
				bullA = false;
				bullW = false;
				bullS = false;
				bullD = true;
			}
			if (KeyS == true) {
				bullA = false;
				bullW = false;
				bullS = true;
				bullD = false;
			}
			if (skillFrame >= 6) {
				skillFrame = 0;
				spaceCheck = false;
				if (bull1Col == false || bull2Col == false || bull3Col == false) {
					bulletNo[bullOrder] = 1;
					switch (bullOrder) {
					case 0: {bull1State = true; break; }
					case 1: {bull2State = true; break; }
					case 2: {bull3State = true; break; }
					}
					bullOrder++;
					if (bullOrder > 2) {
						bullOrder = 0;
					}
				}
				continue;
			}

		}
		else {
			animationFrame++;
			delay(40);
			if (animationFrame >= 9) {
				animationFrame = 0;
			}
		}



		//printf("X = %f\nY = %f\n", playerPosition.x, playerPosition.y);

		//--------------------------------------Bullet 1------------------------------------------//
		
		if (bull1State == true) {
			if (bull1Col == false) {
				bull1Col = true;
				bullet1.setPosition(playerPosition.x + 50, playerPosition.y + 60);
				bull1out = true;

				//printf("bull1 State %d", bull1out);
				bull1State = false;
				bulletNo[0] = 1;
			}
		}
			//printf("bull1 State %d\n", bull1out);
		if (bulletNo[0] == 1) {
			if (bullA == true) {
				bullet1.move(-25.0f, 0.0f);
				//printf("1");
			}
			else if (bullD == true) {
				bullet1.move(25.0f, 0.0f);
				//printf("1");
			}
			else if (bullW == true) {
				bullet1.move(0.0f, -25.0f);
				//printf("1");
			}
			else if (bullS == true) {
				bullet1.move(0.0f, 25.0f);
				//printf("1");
			}
		}
		

		//--------------------------------------Bullet 2------------------------------------------//

		
		if (bull2State == true) {
			if (bull2Col == false) {
				bull2Col = true;
				bullet2.setPosition(playerPosition.x + 50, playerPosition.y + 60);
				bull2out = true;

				//printf("bull1 State %d", bull1out);
				bull2State = false;
				bulletNo[1] = 1;
			}
		}
			//printf("bull1 State %d\n", bull1out);
		if (bulletNo[1] == 1) {
			if (bullA == true) {
				bullet2.move(-25.0f, 0.0f);
				//printf("1");
			}
			if (bullD == true) {
				bullet2.move(25.0f, 0.0f);
				//printf("1");
			}
			if (bullW == true) {
				bullet2.move(0.0f, -25.0f);
				//printf("1");
			}
			if (bullS == true) {
				bullet2.move(0.0f, 25.0f);
				//printf("1");
			}
		}

		//--------------------------------------Bullet 3------------------------------------------//

		
		if (bull3State == true) {
			if (bull3Col == false) {
				bull3Col = true;
				bullet3.setPosition(playerPosition.x + 50, playerPosition.y + 60);
				bull3out = true;

				//printf("bull1 State %d", bull1out);
				bull3State = false;
				bulletNo[2] = 1;
			}
		}
			//printf("bull1 State %d\n", bull1out);
		if (bulletNo[2] == 1) {
			if (bullA == true) {
				bullet3.move(-25.0f, 0.0f);
				//printf("1");
			}
			if (bullD == true) {
				bullet3.move(25.0f, 0.0f);
				//printf("1");
			}
			if (bullW == true) {
				bullet3.move(0.0f, -25.0f);
				//printf("1");
			}
			if (bullS == true) {
				bullet3.move(0.0f, 25.0f);
				//printf("1");
			}
		}
		

		
		//printf("Bulleet Col1 %d\nBulleet Col2 %d\nBulleet Col3 %d\n", bull1Col, bull2Col, bull3Col);
		//--------------------------------------Democrac LEVEL1------------------------------------------//

		DemocracLV1.setTextureRect(sf::IntRect(democracSizeX * animateDemocracFrame, democracSizeY * 0, democracSizeX, democracSizeY));
		animateDemocracFrame++;

		if (animateDemocracFrame > 9) {
			animateDemocracFrame=0;
		}

		//--------------------------------------Democrac LEVEL2------------------------------------------//

		DemocracLV2.setTextureRect(sf::IntRect(democracLV2SizeX* animateDemocracLV2Frame, democracLV2SizeY * 0, democracLV2SizeX, democracLV2SizeY));
		animateDemocracLV2Frame++;

		if (animateDemocracLV2Frame > 9) {
			animateDemocracLV2Frame = 0;
		}

		//--------------------------------------Democrac LEVEL3------------------------------------------//

		DemocracLV3.setTextureRect(sf::IntRect(democracLV3SizeX* animateDemocracLV3Frame, democracLV3SizeY * 0, democracLV3SizeX, democracLV3SizeY));
		animateDemocracLV3Frame++;

		if (animateDemocracLV3Frame > 9) {
			animateDemocracLV3Frame = 0;
		}

		//--------------------------------------Democrac LEVEL4------------------------------------------//

		DemocracLV4.setTextureRect(sf::IntRect(democracLV4SizeX* animateDemocracLV4Frame, democracLV4SizeY * 0, democracLV4SizeX, democracLV4SizeY));
		animateDemocracLV4Frame++;

		if (animateDemocracLV4Frame > 9) {
			animateDemocracLV4Frame = 0;
		}

		//--------------------------------------Gate LEVEL2------------------------------------------//

		GateLV2.setTextureRect(sf::IntRect(GateLV2SizeX * animateGateLV2Frame, GateLV2SizeY * 0, GateLV2SizeX, GateLV2SizeY));
		animateGateLV2Frame++;

		if (animateGateLV2Frame >= 8) {
			animateGateLV2Frame = 0;
		}
		//--------------------------------------Gate LEVEL4------------------------------------------//

		GateLV4.setTextureRect(sf::IntRect(GateLV4SizeX* animateGateLV4Frame, GateLV4SizeY * 0, GateLV4SizeX, GateLV4SizeY));
		animateGateLV4Frame++;

		if (animateGateLV4Frame >= 8) {
			animateGateLV4Frame = 0;
		}

		//--------------------------------------Key LEVEL1------------------------------------------//

		KeyLV1.setTextureRect(sf::IntRect(KeyLV1SizeX* animateKeyLV1Frame, KeyLV1SizeY * 0, KeyLV1SizeX, KeyLV1SizeY));
		animateKeyLV1Frame++;

		if (animateKeyLV1Frame >= 13) {
			animateKeyLV1Frame = 0;
		}
		KeyLV1.rotate(10.0f);

		//--------------------------------------Key LEVEL2------------------------------------------//

		KeyLV2.setTextureRect(sf::IntRect(KeyLV2SizeX * animateKeyLV2Frame, KeyLV2SizeY * 0, KeyLV2SizeX, KeyLV2SizeY));
		animateKeyLV2Frame++;

		if (animateKeyLV2Frame >= 13) {
			animateKeyLV2Frame = 0;
		}
		KeyLV2.rotate(10.0f);

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



		//**********enemy01 animation**********//

		enemyLV201.move(enemyLV201PosX, 0.0f);
		enemyLV201.setTextureRect(sf::IntRect(enemyLV201SizeX * enemyLV201FrameX, enemyLV201SizeY * enemyLV201FrameY, enemyLV201SizeX, enemyLV201SizeY));
		enemyLV201FrameX++;
		if (enemyLV201FrameX >= 9) {
			enemyLV201FrameX = 0;
		}

		//Check Enemy 01 Position//

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



		//--------------------------------------ENEMY LEVEL3------------------------------------------//



		//**********enemy01 animation**********//

		enemyLV301.move(enemyLV301PosX, 0.0f);
		enemyLV301.setTextureRect(sf::IntRect(enemyLV301SizeX * enemyLV301FrameX, enemyLV301SizeY * enemyLV301FrameY, enemyLV301SizeX, enemyLV301SizeY));
		enemyLV301FrameX++;
		if (enemyLV301FrameX >= 9) {
			enemyLV301FrameX = 0;
		}

		//Check Enemy 01 Position//

		if (enemyLV301MaxX < 100) {
			enemyLV301PosX = -4.5;
			enemyLV301MaxX++;
		}
		else if (enemyLV301MaxX >= 100 && enemyLV301MaxX < 200) {
			enemyLV301FrameY = 11;
			enemyLV301PosX = 4.5;
			enemyLV301MaxX++;
		}
		else {
			enemyLV301MaxX = 0;
			enemyLV301PosX = 0;
			enemyLV301FrameY = 9;
		}

		//**********enemy02 animation**********//

		enemyLV302.move(0.0f, enemyLV302PosY);
		enemyLV302.setTextureRect(sf::IntRect(enemyLV302SizeX* enemyLV302FrameX, enemyLV302SizeY* enemyLV302FrameY, enemyLV302SizeX, enemyLV302SizeY));
		enemyLV302FrameX++;
		if (enemyLV302FrameX >= 9) {
			enemyLV302FrameX = 0;
		}

		//Check Enemy 02 Position//

		if (enemyLV302MaxY < 100) {
			enemyLV302PosY = -4.5;
			enemyLV302MaxY++;
		}
		else if (enemyLV302MaxY >= 100 && enemyLV302MaxY < 200) {
			enemyLV302FrameY = 10;
			enemyLV302PosY = 4.5;
			enemyLV302MaxY++;
		}
		else {
			enemyLV302MaxY = 0;
			enemyLV302PosY = 0;
			enemyLV302FrameY = 8;
		}
		sf::Vector2f enemyLV302Position = enemyLV302.getPosition();


		//--------------------------------------ENEMY LEVEL4------------------------------------------//


		//**********enemy01 animation**********//

		enemyLV401.move(enemyLV401PosX, 0.0f);
		enemyLV401.setTextureRect(sf::IntRect(enemyLV401SizeX* enemyLV401FrameX, enemyLV401SizeY* enemyLV401FrameY, enemyLV401SizeX, enemyLV401SizeY));
		enemyLV401FrameX++;
		if (enemyLV401FrameX >= 9) {
			enemyLV401FrameX = 0;
		}

		//Check Enemy 01 Position//

		if (enemyLV401MaxX < 100) {
			enemyLV401PosX = -4.5;
			enemyLV401MaxX++;
		}
		else if (enemyLV401MaxX >= 100 && enemyLV401MaxX < 200) {
			enemyLV401FrameY = 11;
			enemyLV401PosX = 4.5;
			enemyLV401MaxX++;
		}
		else {
			enemyLV401MaxX = 0;
			enemyLV401PosX = 0;
			enemyLV401FrameY = 9;
		}
		sf::Vector2f enemyLV401Position = enemyLV401.getPosition();

		//**********enemy02 animation**********//

		enemyLV402.move(0.0f, enemyLV402PosY);
		enemyLV402.setTextureRect(sf::IntRect(enemyLV402SizeX* enemyLV402FrameX, enemyLV402SizeY* enemyLV402FrameY, enemyLV402SizeX, enemyLV402SizeY));
		enemyLV402FrameX++;
		if (enemyLV402FrameX >= 9) {
			enemyLV402FrameX = 0;
		}

		//Check Enemy 02 Position//

		if (enemyLV402MaxY < 80) {
			enemyLV402PosY = -4.5;
			enemyLV402MaxY++;
		}
		else if (enemyLV402MaxY >= 80 && enemyLV402MaxY < 160) {
			enemyLV402FrameY = 10;
			enemyLV402PosY = 4.5;
			enemyLV402MaxY++;
		}
		else {
			enemyLV402MaxY = 0;
			enemyLV402PosY = 0;
			enemyLV402FrameY = 8;
		}
		sf::Vector2f enemyLV402Position = enemyLV402.getPosition();

		//**********enemy03 animation**********//

		enemyLV403.move(0.0f, enemyLV403PosY);
		enemyLV403.setTextureRect(sf::IntRect(enemyLV403SizeX * enemyLV403FrameX, enemyLV403SizeY * enemyLV403FrameY, enemyLV403SizeX, enemyLV403SizeY));
		enemyLV403FrameX++;
		if (enemyLV403FrameX >= 9) {
			enemyLV403FrameX = 0;
		}

		//Check Enemy 03 Position//

		if (enemyLV403MaxY < 100) {
			enemyLV403PosY = -4.5;
			enemyLV403MaxY++;
		}
		else if (enemyLV403MaxY >= 100 && enemyLV403MaxY < 200) {
			enemyLV403FrameY = 10;
			enemyLV403PosY = 4.5;
			enemyLV403MaxY++;
		}
		else {
			enemyLV403MaxY = 0;
			enemyLV403PosY = 0;
			enemyLV403FrameY = 8;
		}
		sf::Vector2f enemyLV403Position = enemyLV403.getPosition();

		//**********enemy04 animation**********//

		enemyLV404.move(0.0f, enemyLV404PosY);
		enemyLV404.setTextureRect(sf::IntRect(enemyLV404SizeX* enemyLV404FrameX, enemyLV404SizeY* enemyLV404FrameY, enemyLV404SizeX, enemyLV404SizeY));
		enemyLV404FrameX++;
		if (enemyLV404FrameX >= 9) {
			enemyLV404FrameX = 0;
		}

		//Check Enemy 04 Position//

		if (enemyLV404MaxY < 100) {
			enemyLV404PosY = 4.5;
			enemyLV404MaxY++;
		}
		else if (enemyLV404MaxY >= 100 && enemyLV404MaxY < 200) {
			enemyLV404FrameY = 8;
			enemyLV404PosY = -4.5;
			enemyLV404MaxY++;
		}
		else {
			enemyLV404MaxY = 0;
			enemyLV404PosY = 0;
			enemyLV404FrameY = 10;
		}
		sf::Vector2f enemyLV404Position = enemyLV404.getPosition();



		

		/***********************************************************************************************************

		------------------------------------------------------------------------------------------------------------

		-----------------------------------------> > Render Zone < <------------------------------------------------
		
		------------------------------------------------------------------------------------------------------------
		
		***********************************************************************************************************/




		window.clear();
		window.draw(background);
		window.draw(walltop);
		
		//Render:Heart//

		if (heart1Check == true) {
			window.draw(heart1);
		}
		if (heart2Check == true) {
			window.draw(heart2);
		}
		if (heart3Check == true) {
			window.draw(heart3);
		}

		//Render:LEVEL 1//

		if (n == 1) {
			window.draw(wall5);
			if (DoorLV1Check == false) {
				window.draw(KeyLV1);
				window.draw(DoorLV1);
			}
			window.draw(wall4);
			window.draw(wall1);
			window.draw(wall2);
			window.draw(player);
			if (enemy1Life > 0) {
				window.draw(enemy01);
			}
			if (enemy2Life > 0) {
				window.draw(enemy02);
			}
			window.draw(DemocracLV1);
			
			if (playerPosition.y < 300&&playerPosition.y > 200) {
				if (enemy1Life > 0) {
					window.draw(enemy01);
				}
				window.draw(player);
				window.draw(wall1);
				window.draw(wall2);
				if (enemy2Life > 0) {
					window.draw(enemy02);
				}
			}
			if (!playerPosition.y < 300 && !playerPosition.y > 200) {
				if (enemy1Life > 0) {
					window.draw(enemy01);
				}
				window.draw(player);
				window.draw(wall1);
				window.draw(wall2);
				if (enemy2Life > 0) {
					window.draw(enemy02);
				}
			}
			if (enemy02Position.y < playerPosition.y) {
				if (enemy2Life > 0) {
					window.draw(enemy02);
				}
				window.draw(player);
			}
			if (!enemy02Position.y < !playerPosition.y) {
				window.draw(player);
				if (enemy2Life > 0) {
					window.draw(enemy02);
				}
			}
			
			window.draw(wall3);
			
		}

		//RENDER:LEVEL 2//

		else if (n == 2) {
			window.draw(GateLV2);
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
			if (enemyLV203Position.y < playerPosition.y) {
				window.draw(enemyLV203);
				window.draw(player);
			}
			else {
				window.draw(player);
				window.draw(enemyLV203);
			}
			window.draw(wallLV204);
			if (DoorLV2Check == false) {
				window.draw(KeyLV2);
				window.draw(DoorLV2);
			}
			window.draw(DemocracLV2);
		}

		//RENDER:LEVEL3//
		
		else if (n == 4) {
			window.draw(wallLV302);
			window.draw(wallLV303);
			window.draw(enemyLV301);
			if (enemyLV302Position.y < playerPosition.y) {
				window.draw(enemyLV302);
				window.draw(player);
			}
			if( enemyLV302Position.y > playerPosition.y) {
				window.draw(player);
				window.draw(enemyLV302);
			}
			if (playerPosition.y < 250 && playerPosition.y >= 200) {
				window.draw(enemyLV301);
				if (enemyLV302Position.y < playerPosition.y) {
					window.draw(enemyLV302);
					window.draw(player);
					window.draw(wallLV303);
				}
				if (enemyLV302Position.y > playerPosition.y) {
					window.draw(player);
					window.draw(enemyLV302);
					window.draw(wallLV303);
				}
			}
			if (playerPosition.y < 200) {
				window.draw(player);
				if (enemyLV302Position.y < playerPosition.y) {
					window.draw(enemyLV302);
					window.draw(player);
					window.draw(wallLV303);
				}
				if (enemyLV302Position.y > playerPosition.y) {
					window.draw(player);
					window.draw(enemyLV302);
					window.draw(wallLV303);
				}
				window.draw(enemyLV301);
			}
			window.draw(DemocracLV3);
			window.draw(wallLV301);
		
		}

		//RENDER:LEVEL4//

		else if (n == 5) {
			window.draw(enemyLV402);
			window.draw(wallLV402);
			window.draw(wallLV401);
			window.draw(enemyLV401);
			if (playerPosition.y < 350) {
				if (playerPosition.y < enemyLV401Position.y) {
					window.draw(player);
					window.draw(enemyLV401);
				}
				if (!(playerPosition.y < enemyLV401Position.y)) {
					window.draw(enemyLV401);
					window.draw(player);

				}
				if (playerPosition.y < enemyLV402Position.y) {
					window.draw(player);
					window.draw(enemyLV402);
				}
				if (!(playerPosition.y < enemyLV402Position.y)) {
					window.draw(enemyLV402);
					window.draw(player);
				}

				window.draw(wallLV401);  

			}
			if (!(playerPosition.y < 350)) {
				window.draw(wallLV401);
				if (playerPosition.y < enemyLV401Position.y) {
					window.draw(player);
					window.draw(enemyLV401);
				}
				if (!(playerPosition.y < enemyLV401Position.y)) {
					window.draw(enemyLV401);
					window.draw(player);

				}
			}
			window.draw(GateLV4);
		

		}
		else if (n == 6) {
			window.draw(enemyLV403);
			window.draw(enemyLV404);
			window.draw(player);
			window.draw(DemocracLV4);
		}

		//Render::Bullet//

		if (bull1out == true) {
			window.draw(bullet1);
		}
		if (bull2out == true) {
			window.draw(bullet2);
		}
		if (bull3out == true) {
			window.draw(bullet3);
		}
		window.draw(timerClock);
		window.draw(time);
		window.draw(unit);
		window.display();
	}
	/*----------------------------------------------------------------------------------------------------------

	--------------------------------------------- Loop END -----------------------------------------------------

	----------------------------------------------------------------------------------------------------------*/
}
