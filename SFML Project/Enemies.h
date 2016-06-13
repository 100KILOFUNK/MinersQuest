#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <random>
#include <time.h>

class Enemies :
	public sf::Drawable, public Character
{
private:
	sf::Texture mTexture;
	sf::Sprite mSpriteSheet;

	sf::Vector2f direction;
	sf::Vector2f position;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Enemies(sf::Vector2f position);

	void Update(float dt, float gameTime, int offset);

	void behaviour(float dt, float gameTime, int offset);

};
