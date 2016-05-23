#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemies.h"
#include "Map.h"
#include "UI.h"
#include <iostream>

class Game :
	public sf::Drawable
{
private:
	Player mPlayer;
	Enemies *mEnemies[2];
	Map mMap;
	UI *ui;
	int nrOfEnemies = 2;

	float bottom, left, right, top;
	float temp = mPlayer.getfallSpeed();



	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;


	sf::View view;
	float playerPosViewX;
	float playerPosViewY;
public:
	Game();
	~Game();

	void CollisionCheck(Character *obj);
	bool collidesWithGround(Character *obj);
	bool collideLeft(Character *obj, int index);
	bool collideRight(Character *obj, int index);
	bool collideBottom(Character *obj, int index);
	void enemyCollision();
	void Update(float dt);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	float getPlayerPosX() const;
	float getPlayerPosY() const;

	UI getUI();

	sf::View getHUD();
	sf::View getView();
	void moveView();


	void setPause(bool state);
	bool getPause() const;
	void setStart(bool state);
	bool getStart() const;
	void removeEnemy(int index);


};
