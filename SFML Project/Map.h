#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ground.h"
#include "Box.h"
class Map :
	public sf::Drawable
{
private:
	//i wanna do my own filetype which hold information for each level. all we have to do is to read the file and the game draws the map accordingly
	Ground mGround;
	Box *mBox[5];

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	Map();
	~Map();

	sf::RectangleShape getGroundBoundingBox() const;
	sf::RectangleShape getBoxBoundingBox(int i) const;
	sf::RectangleShape getBoxRightBbox(int i) const;
	sf::RectangleShape getBoxLeftBbox(int i) const;
};
