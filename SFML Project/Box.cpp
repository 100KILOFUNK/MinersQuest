#include "Box.h"


Box::Box(sf::Vector2f position) : BoundingBox()
{
	spriteSize = { 63, 63 };
	boundingBox(position, spriteSize, 0, 0);

	platformTexture.loadFromFile("../Resources/box.jpg");
	platformTexture.setRepeated(true);

	platformSprite.setPosition(position);
	platformSprite.setTexture(platformTexture);
	platformSprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));
}

void Box::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(platformSprite, states);
	//target.draw(bbox, states);
	//target.draw(bboxLeft, states);
	//target.draw(bboxRight, states);
}

sf::RectangleShape Box::getBoundingBox() const {
	return this->bbox;
}
