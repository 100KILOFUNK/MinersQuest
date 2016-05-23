#include "Enemies.h"



Enemies::Enemies(sf::Vector2f position) : Character()
{
	boundingBox(position, spriteSize, 28, 28);

	// Just this line is needed if you remove int playerNumber from the argument list
	sf::String fileName = "../Resources/DwarfEnemy.png";
	fileName = "../Resources/DwarfEnemy.png";

	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (mTexture.loadFromFile(fileName))
	{
		// Handle error
	}
	mSpriteSheet.setTexture(mTexture);
	mSpriteSheet.setTextureRect(sf::IntRect(0, 0, 100, 80));
	mSpriteSheet.setPosition(position);
	direction.x = 0;
}

void Enemies::Update(float dt, int offset) {

	position = mSpriteSheet.getPosition();
	boundingBox(position, spriteSize, 28, 28);
	collisionLogic();
	behaviour(dt, offset);

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
}

void Enemies::behaviour(float dt, int offset) {
	//direction.x = 0.0f;
	direction.y = fallSpeed;

	mKeyFrameDuration += dt;

	if (direction.x == 0)
	{
		srand(time(NULL) + offset);
		if (rand() % 2 > 0)
		{
			direction.x = -1.0f;
			mCurrentKeyFrame.y = 0;
		}
		else {
			direction.x = 1.0f;
			mCurrentKeyFrame.y = 1;
		}
	}

	if (collisionLeft)
	{
		direction.x = 1.0f;
		mKeyFrameDuration += dt;
		mCurrentKeyFrame.y = 1;
	}

	if (collisionRight)
	{
		direction.x = -1.0f;
		mKeyFrameDuration += dt;
		mCurrentKeyFrame.y = 0;
	}

	directionAnimation();

}

void Enemies::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(mSpriteSheet, states);
	//target.draw(bbox, states);
	//target.draw(bboxLeft, states);
	//target.draw(bboxRight, states);
}
