#pragma once
#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

class Box :
	public sf::Drawable, public BoundingBox
{
private:
	sf::Texture platformTexture;
	sf::Sprite platformSprite;
	sf::Vector2f spriteSize;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Box(sf::Vector2f position);

	sf::RectangleShape getBoundingBox() const;
};

