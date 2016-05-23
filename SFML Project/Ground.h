#pragma once
#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

class Ground :
	public sf::Drawable, public BoundingBox
{
private:
	sf::Texture groundTexture;
	sf::Sprite groundSprite;
	sf::Vector2f spriteSize;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Ground(sf::Vector2f position);
};

