#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
class Menu: public sf::Drawable{

private:
  sf::Texture Tbg;
  sf::Sprite Sbg;

  Player menuP;

public:

  Menu();

  //overloaded draw function
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};
