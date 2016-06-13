#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <iostream>

class Player :
	public sf::Drawable, public Character
{
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;

	sf::Vector2f position;


	int life = 3;
	// Jump variables
	bool mIsJumping = false;
	float mJumpSpeed = 0.0f;

	int pts = 0;

	// Attacking variables
	bool isAttacking = false;
	bool beginAttack = true;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	Player(sf::Vector2f position);
	void Update(float dt, float gameTime);

	void setLife(int i);
	int getLife() const;
	void setPts(int pts);
	int getPts() const;
	void idleAnimation(float dt);
	void attackAnimation(float dt);
	void directionHandler(float dt);
	void setfallSpeed(const float fallSpeed);
	float getfallSpeed() const;

	void control(float dt, float gameTime);


};
