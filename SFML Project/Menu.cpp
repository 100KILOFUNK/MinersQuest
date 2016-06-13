#include "Menu.h"

Menu::Menu(): menuP(sf::Vector2f (100, 400)){
  if(!Tbg.loadFromFile("../Resources/menubg.png")){
    std::cout << "Erro loading menubg.png";
  }
  Sbg.setTexture(Tbg);
  Sbg.setTextureRect(sf::IntRect(1, 3, 1200, 600));

  menuP.setfallSpeed(0.0);



}


void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(Sbg);
  //target.draw(menuP, states);
}
