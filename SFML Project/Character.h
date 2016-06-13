#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BoundingBox.h"

class Character :
	public BoundingBox
{
protected:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;
	sf::Vector2f spriteSize = { 100, 80 };

	float mSpeed = 160.0f;
	sf::Vector2f direction;

	// Animation variables
	sf::Vector2f mCurrentKeyFrame;
	sf::Vector2f mKeyFrameSize;
	int mSpriteSheetWidth;
	float mAnimationSpeed;
	float mKeyFrameDuration;

	//Gravity logic
	float mGravity = 9.82f;
	float fallSpeed = 1.0f;
	bool collisionLeft, collisionRight, collisionUp, collisionDown;

	//Death
	bool aboutToDie = false;
	bool isDead = false;
	float deathTimer = 0;

public:
	Character();

	sf::Sprite getSprite() const;

	float getSpeed() const;

	void collisionLogic();

	bool getCollisionLeft() const;
	bool getCollisionRight() const;
	bool getCollisionUp() const;
	bool getCollisionDown() const;

	void setCollisionLeft(const bool left);
	void setCollisionRight(const bool right);
	void setCollisionUp(const bool up);
	void setCollisionDown(const bool down);

	void setfallSpeed(const float fallSpeed);
	float getfallSpeed() const;

	void directionAnimation();

	void setCollisionDeath(const bool dead);

	bool getAboutToDie() const;
	void setAboutToDie(const bool aboutToDie);

	bool getIsDead() const;
	void setIsDead(const bool dead);

};
