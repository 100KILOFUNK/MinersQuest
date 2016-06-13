#include "Ground.h"
#include <iostream>

Ground::Ground(sf::Vector2f position) : BoundingBox()
{
	spriteSize = { 2500, 800 };
	boundingBox(position, spriteSize, 0, 17);

	groundTexture.loadFromFile("../Resources/ground1.png");
	groundTexture.setRepeated(true);

	groundSprite.setPosition(position);
	groundSprite.setTexture(groundTexture);
	groundSprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));
}

void Ground::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(groundSprite, states);
	target.draw(bbox, states);
}
