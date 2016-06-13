#include "Map.h"
#include <iostream>
using namespace std;

Map::Map() : mGround(sf::Vector2f(-500, 500))
{
	//boxes
	mBox[0] = new Box(sf::Vector2f(-10, 450));
	mBox[1] = new Box(sf::Vector2f(-20, 450 - 63));
	mBox[2] = new Box(sf::Vector2f(500, 450));
	mBox[3] = new Box(sf::Vector2f(800, 450));
	mBox[4] = new Box(sf::Vector2f(1100, 450));

	for(int i = 0; i < 5; i++)
		parts[i] = 0;

}

/*Map::Map(string level){
	std::ifstream lvl("../Resources/Levels/" + level);
}*/

void Map::test(){
	std::ifstream lvl("../Resources/Levels/level1.mql");
	std::string line;
	std::string part = "part";
	int counter = 0;
	if (lvl.is_open()){
	    while ( getline (lvl,line, ' ') )
	    {
				std::size_t found = line.find(part);
  			if (found!=std::string::npos && counter < 5){
					char tmp;
					lvl.get(tmp);
					parts[counter] = (int) tmp - 48;

					counter++;
				}


	    }
	    lvl.close();
	}else cout << "unable to open";


	for(int i = 0; i < 5; i++)
		cout << "part " << i << ": " << parts[i] << endl;

}

Map::~Map(){
	for(int i = 0; i < 5; i++)
		delete mBox[i];
}

sf::RectangleShape Map::getGroundBoundingBox() const {
	return this->mGround.getBoundingBox();
}

sf::RectangleShape Map::getBoxBoundingBox(int i) const {
	return this->mBox[i]->getBoundingBox();
}

sf::RectangleShape Map::getBoxRightBbox(int i) const {
	return this->mBox[i]->getBboxRight();
}

sf::RectangleShape Map::getBoxLeftBbox(int i) const {
	return this->mBox[i]->getBboxLeft();
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	for(int i = 0; i < 5; i++)
		target.draw(*mBox[i], states);
	target.draw(mGround, states);
}
