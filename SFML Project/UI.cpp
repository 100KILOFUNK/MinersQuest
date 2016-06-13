#include "UI.h"
#include <sstream>


UI::UI(){

  start = false;
	pause = false;
	end = false;

  HUDview.reset(sf::FloatRect(0, 0, 1200, 600));

  if (!font.loadFromFile("../Resources/arial.ttf"))
  {
    std::cout << "Erro loading font.png";
  }
  pts.setFont(font);
  pts.setCharacterSize(50); // in pixels, not points!
  pts.setColor(sf::Color::White);
  pts.setString("0");
  staticPts.setFont(font);
  staticPts.setCharacterSize(50); // in pixels, not points!
  staticPts.setColor(sf::Color::White);
  staticPts.setString("Score: ");

  staticPts.setPosition(950, 10);
  pts.setPosition(1100, 10);


  if(!startScreenT.loadFromFile("../Resources/start.png")){
		std::cout << "Erro loading start.png";
	}
	startScreenS.setTexture(startScreenT);
	startScreenS.setTextureRect(sf::IntRect(1, 3, 1200, 600));
	//startScreenS.setPosition(mPlayer.getBoundingBox().getPosition().x - 550, mPlayer.getBoundingBox().getPosition().y - 400);

	if(!pauseScreenT.loadFromFile("../Resources/paused.png")){
		std::cout << "Erro loading paus.png";
	}
	pauseScreenS.setTexture(pauseScreenT);
	pauseScreenS.setTextureRect(sf::IntRect(1, 3, 1200, 600));

  if(!heart.loadFromFile("../Resources/heart.png")){
		std::cout << "Erro loading paus.png";
	}
  int x = 5;
  int y = 10;
  for(int i = 0; i < 3; i++){
    heartSprites[i] = new sf::Sprite(heart);
    heartSprites[i]->setPosition(0 + x, y);
    x+=30;
  }


}

UI::UI(float x, float y){

  start = false;
	pause = false;
	end = false;

  y = 25;
  x = -422.5;


  if (!font.loadFromFile("../Resources/arial.ttf"))
  {
    std::cout << "Erro loading font.png";
  }
  pts.setFont(font);
  pts.setCharacterSize(24); // in pixels, not points!
  pts.setColor(sf::Color::White);
  pts.setString("0");
  staticPts.setFont(font);
  staticPts.setCharacterSize(24); // in pixels, not points!
  staticPts.setColor(sf::Color::White);
  staticPts.setString("Score: ");

  //staticPts.setPosition(300, 10);
  //pts.setPosition(350, 10);

  if(!startScreenT.loadFromFile("../Resources/start.png")){
		std::cout << "Erro loading start.png";
	}
	startScreenS.setTexture(startScreenT);
	startScreenS.setTextureRect(sf::IntRect(0, 0, 1200, 800));
	startScreenS.setPosition(x, y);

	if(!pauseScreenT.loadFromFile("../Resources/paused.png")){
		std::cout << "Erro loading paus.png";
	}
	pauseScreenS.setTexture(pauseScreenT);
	pauseScreenS.setTextureRect(sf::IntRect(0, 0, 1200, 800));
  pauseScreenS.setPosition(x, y);

  if(!heart.loadFromFile("../Resources/heart.png")){
    std::cout << "Erro loading paus.png";
  }

  //x += 600;
  //y += 300;
  for(int i = 0; i < 3; i++){
    heartSprites[i] = new sf::Sprite(heart);
    heartSprites[i]->setPosition(x+5, y+5);
    //x -= 30;

  }






}

UI::~UI(){

}

void UI::update(float dt, sf::RenderWindow& app){

  sf::Event event;
  while(app.pollEvent(event)){

    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
      app.close();
    }

    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::P)
          if(getPause())
            setPause(false);
          else
            setPause(true);

    }

    if(event.key.code == sf::Keyboard::Return)
      setStart(true);

    if(event.key.code == sf::Keyboard::F){

      sf::VideoMode mode(1920, 1080);
      sf::ContextSettings test;
      app.create(mode, "Miner's Quest", sf::Style::Fullscreen, test);
    }

  }

}


void UI::setLife(int life){
  this->nrOfSprites = life;
}

sf::View UI::getHUDView(){
  return HUDview;
}
void UI::moveUI(sf::Vector2f camera){

  for(int i = 0; i < nrOfSprites; i++)
    heartSprites[i]->move(camera.x - 422.5, camera.y + 25);
}


void UI::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
  if(start && !pause){
      for(int i = 0; i < nrOfSprites; i++)
        target.draw(*heartSprites[i]);

      target.draw(staticPts);
      target.draw(pts);
  }
	//states
	if(!start || pause) target.draw(menu);
  if(!start) target.draw(startScreenS);

  //if(end)     draw the deadthscreen
}

void UI::setPts(int i){
  std::stringstream type;
	type << i;
  this->pts.setString(type.str());
}
void UI::setPause(bool state){
	pause = state;
}

bool UI::getPause() const{
	return pause;
}

void UI::setStart(bool state){
	start = state;
}

bool UI::getStart() const{
	return start;
}

void UI::setEnd(bool state){
	end = state;
}

bool UI::getEnd() const{
	return end;
}

sf::Sprite UI::getPauseScreen(){
  return this->pauseScreenS;
}

void UI::setPauseScreenPos(float x, float y){
  pauseScreenS.setPosition(x, y);
}
