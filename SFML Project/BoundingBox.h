#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class BoundingBox
{
protected:
	//boundingbox variables
	sf::RectangleShape bbox, bboxLeft, bboxRight, weaponBox;
	float posDiffrenceY;
	float posDiffrenceX;
	sf::Vector2f bboxposition;
	sf::Vector2f bboxsize;
	sf::Vector2f bboxLeftpos, bboxRightPos;
	sf::Vector2f sidebboxsize;

public:
	BoundingBox();
	
	void boundingBox(sf::Vector2f position, sf::Vector2f size, float posDiffrenceY, float posDiffrenceX);

	sf::RectangleShape getBoundingBox() const;
	sf::RectangleShape getBboxLeft() const;
	sf::RectangleShape getBboxRight() const;
	sf::RectangleShape getWeaponBox() const;
};

