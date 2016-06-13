#pragma once
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class UI: public sf::Drawable {
  private:
    sf::Texture pauseScreenT;
  	sf::Sprite pauseScreenS;
  	sf::Texture startScreenT;
  	sf::Sprite startScreenS;
    bool start, pause, end;

    sf::Texture heart;
    sf::Sprite *heartSprites[3];
    int nrOfSprites = 3;

    Menu menu;


    sf::Font font;
    sf::Text staticPts;
    sf::Text pts;
    sf::View HUDview;

  public:
    UI();
    UI(float x, float y);
    ~UI();

    //overloaded draw function
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void setPause(bool state);
  	bool getPause() const;
  	void setStart(bool state);
  	bool getStart() const;
    void setEnd(bool state);
    bool getEnd() const;

    void setPts(int pts);
    void setLife(int i);


    sf::View getHUDView();
    void moveUI(sf::Vector2f camera);
    void update(float dt);
    sf::Sprite getPauseScreen();

    void setPauseScreenPos(float x, float y);

};
