#include "BoundingBox.h"

BoundingBox::BoundingBox()
{


	//boudingbox values
	posDiffrenceY = 0;
	bboxposition = { 0, 0 };
	bboxsize = { 0, 0 };
	sidebboxsize = { 0, 0 };

	//boudingbox
	bbox.setPosition(bboxposition);
	bbox.setSize(bboxsize);
	bbox.setFillColor(sf::Color(100, 250, 50, 150)); //visable green bbox (alpha 150 of max 225)

	////get boudingbox position
	//brPos = { bbox.getPosition().x + bbox.getSize().x, bbox.getPosition().y + bbox.getSize().y - 5};
	//blPos = { bbox.getPosition().x, bbox.getPosition().y + bbox.getSize().y - 5 };
	//trPos = { bbox.getPosition().x + bbox.getSize().x, bbox.getPosition().y - 5 };
	//tlPos = { bbox.getPosition().x, bbox.getPosition().y + 5 };
	//bcPos = { bbox.getPosition().x + (bbox.getSize().x / 2), bbox.getPosition().y + bbox.getSize().y };
	//tcPos = { bbox.getPosition().x + (bbox.getSize().x / 2), bbox.getPosition().y };

	//sideboxes
	bboxLeft.setPosition(bbox.getPosition());
	bboxLeft.setSize(sidebboxsize);
	bboxLeft.setFillColor(sf::Color(250, 250, 50, 150)); //visable green bbox (alpha 150 of max 225)
	bboxRight.setPosition(bbox.getPosition().x + bbox.getSize().x, bbox.getPosition().y);
	bboxRight.setSize(sidebboxsize);
	bboxRight.setFillColor(sf::Color(250, 100, 50, 150)); //visable green bbox (alpha 150 of max 225)

	//attack
	weaponBox.setPosition(bbox.getPosition().x + 5, bbox.getPosition().y + 5);
	weaponBox.setSize({ bboxsize.x - 10, bboxsize.y - 10 });
	weaponBox.setFillColor(sf::Color(100, 100, 250, 150)); //visable blue bbox (alpha 150 of max 225)
}

void BoundingBox::boundingBox(sf::Vector2f position, sf::Vector2f size, float posDiffrenceX, float posDiffrenceY) {
	//boudingbox values
	this->posDiffrenceY = posDiffrenceY;
	this->posDiffrenceX = posDiffrenceX;
	bboxposition = { position.x + posDiffrenceX, position.y + posDiffrenceY };
	bboxsize = { size.x - (posDiffrenceX * 2), size.y - posDiffrenceY };

	//sidebox
	bboxLeftpos = { position.x + posDiffrenceX - 3, position.y + posDiffrenceY + 4};
	bboxRightPos = { position.x + size.x - posDiffrenceX, position.y + posDiffrenceY + 4};
	sidebboxsize = { 3, size.y - posDiffrenceY - 8 };

	//boudingbox
	bbox.setPosition(bboxposition);
	bbox.setSize(bboxsize);

	//sideboxes
	bboxLeft.setPosition(bboxLeftpos);
	bboxLeft.setSize(sidebboxsize);

	bboxRight.setPosition(bboxRightPos);
	bboxRight.setSize(sidebboxsize);

	//attackBox
	weaponBox.setPosition(bbox.getPosition().x + 5, bbox.getPosition().y + 5);
	weaponBox.setSize({ bboxsize.x - 10, bboxsize.y - 10 });
}


sf::RectangleShape BoundingBox::getBoundingBox() const {
	return this->bbox;
}

sf::RectangleShape  BoundingBox::getBboxLeft() const {
	return this->bboxLeft;
}

sf::RectangleShape  BoundingBox::getBboxRight() const {
	return this->bboxRight;
}

sf::RectangleShape BoundingBox::getWeaponBox() const {
	return this->weaponBox;
}
