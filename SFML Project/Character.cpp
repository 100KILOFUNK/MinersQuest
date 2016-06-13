#include "Character.h"


Character::Character() : BoundingBox()
{


	mTexture.loadFromFile("../Resources/Dwarf.png");
	mTexture.setRepeated(false);

	mSpriteSheet.setPosition(0 ,0);
	mSpriteSheet.setTexture(mTexture);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));


	// Initialise animation variables.
	mCurrentKeyFrame = sf::Vector2f(0, 0);
	mKeyFrameSize = sf::Vector2f(100, 80);
	mSpriteSheetWidth = 16;
	mAnimationSpeed = 0.15f;
	mKeyFrameDuration = 0.0f;

	collisionLeft = false;
	collisionRight = false;
	collisionUp = false;
	collisionDown = false;
}

sf::Sprite Character::getSprite() const {
	return this->mSpriteSheet;
}

float Character::getSpeed() const {
	return this->mSpeed;
}

bool Character::getCollisionLeft() const {
	return this->collisionLeft;
}
bool Character::getCollisionRight() const {
	return this->collisionRight;
}
bool Character::getCollisionUp() const {
	return this->collisionUp;
}
bool Character::getCollisionDown() const {
	return this->collisionDown;
}

void Character::collisionLogic() {
	if (!collisionDown && fallSpeed == 0.0f)
	{
		fallSpeed = 0.0f; //whats the point of this if statement?
	}
	if (!collisionDown)
	{
		if (fallSpeed < mGravity)
		{
			fallSpeed = fallSpeed + 0.05f;
		}
	}
	if (collisionDown)
	{
		fallSpeed = 0.0f;
	}
}

void Character::setCollisionLeft(const bool left) {
	this->collisionLeft = left;
}

void Character::setCollisionRight(const bool right) {
	this->collisionRight = right;
}

void Character::setCollisionUp(const bool up) {
	this->collisionUp = up;
}

void Character::setCollisionDown(const bool down) {
	this->collisionDown= down;
}

void Character::setfallSpeed(const float fallSpeed) {
	this->fallSpeed = fallSpeed;
}

float Character::getfallSpeed() const {
	return this->fallSpeed;
}

void Character::setCollisionDeath(const bool dead) {
	this->death = dead;
}

void Character::directionAnimation() {
	if (mCurrentKeyFrame.x < 3 || mCurrentKeyFrame.x > 8) {
		mCurrentKeyFrame.x = 3;
	}
}
