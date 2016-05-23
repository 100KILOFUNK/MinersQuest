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
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				window.close();
			}

			if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::P) {

                    if(game.getPause()){
												game.setPause(false);
										}else{
												game.setPause(true);
										}
                }
								else if(event.key.code == sf::Keyboard::Return)
										game.setStart(true);

      }
		}
		//sf::View view(sf::FloatRect(game.getPlayerPosX() - 550, game.getPlayerPosY() - 400, 1200, 600));


		window.clear();
		game.Update(gameTime.restart().asSeconds());
		window.setView(game.getView());

		window.draw(game);
		window.setView(game.getHUD());
		window.draw(game.getUI());

		//window.draw(game.getUI());
		window.display();

	}

	return 0;


}
