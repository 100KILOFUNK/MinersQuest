#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML Project");

	Game game;
	sf::Clock gameTime;


	while (window.isOpen())
	{
		window.clear();
		game.Update(gameTime.restart().asSeconds(), window);
		window.setView(game.getView());

		window.draw(game);
		window.setView(game.getHUD());
		window.draw(game.getUI());

		//window.draw(game.getUI());
		window.display();

	}

	return 0;


}
