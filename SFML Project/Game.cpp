#include "Game.h"



Game::Game() :mPlayer(sf::Vector2f (100, 400)), mMap()
{
	mEnemies[0] = new Enemies(sf::Vector2f(600, 400));
	mEnemies[1] = new Enemies(sf::Vector2f(900, 400));
	if (!backgroundTexture.loadFromFile("../Resources/background2.jpg"))
	{
		std::cout << "Error";
	}

	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1200, 800));
	backgroundSprite.setPosition(mPlayer.getBoundingBox().getPosition().x - 550, mPlayer.getBoundingBox().getPosition().y - 475);

	playerPosViewX = mPlayer.getBoundingBox().getPosition().x;
	playerPosViewY = mPlayer.getBoundingBox().getPosition().y;

	view.reset(sf::FloatRect(playerPosViewX, playerPosViewY, 1200, 600));

	ui = new UI();
	//view.getCenter().x, view.getCenter().y


}

Game::~Game() {

	for(int i = 0; i < nrOfEnemies; i++)
		delete mEnemies[i];

}

void Game::Update(float dt, sf::RenderWindow &app)
{

		ui->update(dt, app);

		float time = gameTime.getElapsedTime().asSeconds();


		if(!ui->getPause() || ui->getStart() || mPlayer.getIsDead()){
			CollisionCheck(&mPlayer);
			mPlayer.Update(dt, time);
		}


			for (int i = 0; i < nrOfEnemies; i++) {
					CollisionCheck(mEnemies[i]);
					mEnemies[i]->Update(dt, time, i);
			}
			// Make sure everything in the game is updated (if needed).



			playerPosViewX = mPlayer.getBoundingBox().getPosition().x;
			playerPosViewY = mPlayer.getBoundingBox().getPosition().y;


			moveView();

			ui->setPts(mPlayer.getPts());
			backgroundSprite.setPosition(mPlayer.getBoundingBox().getPosition().x - 550, mPlayer.getBoundingBox().getPosition().y - 475);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
	target.draw(backgroundSprite, states);
	target.draw(mPlayer, states);

	for (int i = 0; i < nrOfEnemies; i++)
	{
		//if (mEnemies[i] != nullptr)
			target.draw(*mEnemies[i], states);
	}
	target.draw(mMap, states);

	//UI
	//target.draw(*ui, states);

}

void Game::test(){
	mMap.test();
}

void Game::CollisionCheck(Character *obj) {

	//Check collision to ground
	int index = -1;

	if (collidesWithGround(obj)){ //kolla om den collidar med marken
		obj->setCollisionDown(true);
	}else{
		obj->setCollisionDown(false);
	}

	for (int i = 0; i < 5; i++)
	{
		if (collideLeft(obj, i) || collideRight(obj, i) || collideBottom(obj, i)) //hitta platformen som den collidar med, -1 om ingen
			index = i;
	}



	if (index > -1) { //om den collidar med n�t s� kommer index vara > -1

		if (collideBottom(obj, index)) //kolla s� den inte collidar ner
			obj->setCollisionDown(true);

		if (collideLeft(obj, index))    //kolla s� inte v�nster BB collidar
			obj->setCollisionLeft(true);

		if (collideRight(obj, index))   //kolla s� inte BB right collidar
			obj->setCollisionRight(true);

	}
	else {
		obj->setCollisionRight(false);
		obj->setCollisionLeft(false);
	}

	enemyCollision();

}

void Game::enemyCollision() {

	int index = -1;

	for (int i = 0; i < nrOfEnemies; i++)
	{
		if (mPlayer.getBoundingBox().getGlobalBounds().intersects(mEnemies[i]->getBoundingBox().getGlobalBounds()) ||
			mPlayer.getWeaponBox().getGlobalBounds().intersects(mEnemies[i]->getBoundingBox().getGlobalBounds())) //hitta platformen som den collidar med, -1 om ingen
			index = i;
	}

	if (index > -1)
	{
		if (mPlayer.getBoundingBox().getGlobalBounds().intersects(mEnemies[index]->getBoundingBox().getGlobalBounds()))
		{

			if (!mEnemies[index]->getAboutToDie())
			{
				mPlayer.setLife(mPlayer.getLife() - 1);
				ui->setLife(mPlayer.getLife());
				if(mPlayer.getLife() == 0) mPlayer.setAboutToDie(true);
			}
		}

		if (mPlayer.getWeaponBox().getGlobalBounds().intersects(mEnemies[index]->getBoundingBox().getGlobalBounds()))
		{
			//play the death animation for enemies
			if (!mPlayer.getAboutToDie())
			{
				//mEnemies[index]->setAboutToDie(true);
				mPlayer.setPts(mPlayer.getPts() + 50);
				removeEnemy(index);
			}


		}
	}

}

void Game::removeEnemy(int index){
	delete mEnemies[index];
	mEnemies[index] = nullptr;

	if (index != nrOfEnemies - 1)
	{
		mEnemies[index] = mEnemies[index + 1];
	}

	nrOfEnemies--;
}

UI Game::getUI(){
	return *ui;
}

sf::View Game::getHUD(){
	return ui->getHUDView();
}

void Game::moveView(){
	view.reset(sf::FloatRect(getPlayerPosX() - 550, getPlayerPosY() - 400, 1200, 600));
}

sf::View Game::getView(){
	return view;
}

void Game::setPause(bool state){
	ui->setPause(state);
}

bool Game::getPause() const{
	return ui->getPause();
}

void Game::setStart(bool state){
	ui->setStart(state);
}

bool Game::getStart() const{
	return ui->getStart();
}

bool Game::collidesWithGround(Character *obj) {
	return obj->getBoundingBox().getGlobalBounds().intersects(mMap.getGroundBoundingBox().getGlobalBounds());
}

bool Game::collideLeft(Character *obj, int index) {
	return obj->getBboxLeft().getGlobalBounds().intersects(mMap.getBoxRightBbox(index).getGlobalBounds());
}

bool Game::collideRight(Character *obj, int index) {
	return obj->getBboxRight().getGlobalBounds().intersects(mMap.getBoxLeftBbox(index).getGlobalBounds());
}

bool Game::collideBottom(Character *obj, int index) {
	return obj->getBoundingBox().getGlobalBounds().intersects(mMap.getBoxBoundingBox(index).getGlobalBounds());
}

float Game::getPlayerPosX() const {
	return this->playerPosViewX;
}
float Game::getPlayerPosY() const {
	return this->playerPosViewY;
}
