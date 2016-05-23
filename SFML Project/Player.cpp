#include "Player.h"
#include <iostream>

Player::Player(sf::Vector2f position) : Character()
{
	//std::cout << "Player()" << std::endl;
	boundingBox(position, spriteSize, 28, 28);

	sf::String fileName = "../Resources/Dwarf.png";
	fileName = "../Resources/Dwarf.png";

	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (mTexture.loadFromFile(fileName))
	{
		// Ha ndle error
	}
	mSpriteSheet.setTexture(mTexture);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 10, 10));
	mSpriteSheet.setPosition(position);
}

void Player::Update(float dt)
{
	//std::cout << this->bboxposition.x << " " << this->bboxposition.y << std::endl;
	position = mSpriteSheet.getPosition();
	boundingBox(position, spriteSize, 28, 28);
	collisionLogic();
	control(dt);


	// Check to start jumping
	bool isSpacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	if (isSpacePressed && !mIsJumping)
	{
		mIsJumping = true;
		collisionDown = false;
		mJumpSpeed = -3.0f;
	}

	// Update jump
	if (mIsJumping)
	{
		direction.y = mJumpSpeed;
		mJumpSpeed += mGravity * dt;
		mGravity += 5.f * fallSpeed * dt;
		// Check to see if jump is finished and if so, clean up.
		if (collisionDown)
		{
			mGravity = 9.82f;
			mIsJumping = false;
			mJumpSpeed = 0.0f;
		}else
			mIsJumping = true;
	}

	mSpriteSheet.move(direction * mSpeed * dt);

	// Update animation
	if (mKeyFrameDuration >= mAnimationSpeed)
	{
		mCurrentKeyFrame.x++;

		if (mCurrentKeyFrame.x >= mSpriteSheetWidth)
			mCurrentKeyFrame.x = 0;

		mSpriteSheet.setTextureRect(sf::IntRect(mCurrentKeyFrame.x * mKeyFrameSize.x,
			mCurrentKeyFrame.y * mKeyFrameSize.y, mKeyFrameSize.x, mKeyFrameSize.y));
		mKeyFrameDuration = 0.0f;
	}

	if (death) {


				direction.x -= 5;
			 	mSpriteSheet.move(direction * mSpeed * dt);

				setCollisionDeath(false);
	}
}

void Player::setfallSpeed(const float fallSpeed) {
	this->fallSpeed = fallSpeed;
}

float Player::getfallSpeed() const {
	return this->fallSpeed;
}

void Player::idleAnimation(float dt) {
	// Update animation
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
		!isAttacking)
	{
		mKeyFrameDuration += dt;
		if (mCurrentKeyFrame.x > 2) {
			mCurrentKeyFrame.x = 0;
		}
	}
}

void Player::attackAnimation(float dt) {
	//Attack
	bool isAttackPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::X);
	if (isAttackPressed && !isAttacking)
	{
		isAttacking = true;
	}

	if (isAttacking)
	{

		if (beginAttack) {
			mCurrentKeyFrame.x = 10;
			beginAttack = false;
		}
		if (mCurrentKeyFrame.x >= 12) {
			//h�r ska bouindboxen f�r vapen enablas
			if (mCurrentKeyFrame.y == 0)
			{
				weaponBox.move(-weaponBox.getSize().x, 0);
				direction.x = -5.f;
			}
			if (mCurrentKeyFrame.y == 1)
			{
				weaponBox.move(weaponBox.getSize().x, 0);
				direction.x = 5.f;
			}
		}
		mKeyFrameDuration += dt;
		if (mCurrentKeyFrame.x >= 13) {
			if(direction.x > 0)
					direction.x = 1;
			else
					direction.x = -1;
			isAttacking = false;
			beginAttack = true;
		}
	}
}

void Player::directionHandler(float dt) {
	// Handle input from arrow keys and update direction and animation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!collisionLeft)
		{
			direction.x = -1.0f;
		}
		mCurrentKeyFrame.y = 0;
		if (!isAttacking)
		{
			mKeyFrameDuration += dt;
			directionAnimation();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!collisionRight)
		{
			direction.x = 1.0f;
		}
		mCurrentKeyFrame.y = 1;
		if (!isAttacking)
		{
			mKeyFrameDuration += dt;
			directionAnimation();
		}
	}
}

void Player::control(float dt) {
	direction.x = 0.0f;
	direction.y = fallSpeed;

	idleAnimation(dt);
	attackAnimation(dt);
	directionHandler(dt);
}

int Player::getPts() const{
	return pts;
}

void Player::setPts(int pts){
	this->pts = pts;
}

void Player::setLife(int life){
	this->life = life;
}

int Player::getLife() const {
	return this->life;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(mSpriteSheet, states);
	//target.draw(bbox, states);
	//target.draw(bboxLeft, states);
	//target.draw(bboxRight, states);
	//target.draw(weaponBox, states);

}
