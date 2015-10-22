#include "level.h"

/*     ***************************      *\
            Class Obstacle
\*     ***************************      */

Obstacle::Obstacle(std::string texture, float x, float y, unsigned int width, unsigned int lifePoints, unsigned int height)
{
	addTexture(texture);
	if(height)
		setZone(x, y, width, height);
	else if(width)
		setZone(x, y, width, width/m_actualSprite->getScale().x*m_actualSprite->getScale().y);
	else
		setZone(x, y);

	if(lifePoints)
		m_lifePoints=lifePoints;
	else
		m_lifePoints=INT_IMPROBABLE;
}

/*     ***************************      *\
            Class Obstacle
\*     ***************************      */

Level::Level()
	: WindowEntity()
{}

Level::Level(std::string indexFileName, int playerPositionX, PublicRect zone)
{
	this->loadFromFile(indexFileName);
}
///\todo retrouver la fonction getLine()
bool Level::loadFromFile(std::string file)
{
	std::ifstream levelFile(file);
	if(!levelFile)
		return false;

	//Lecture du fichier de conf:
	m_name=getFileWithSthx(levelFile, 1)[0];
	levelFile>>m_levelLenght;

	//Ici on charge les WindowEntity du niveau
	std::string instructionList;
	while(levelFile)
	{
		//getLine(ifstream, instructionList);
		if(getWord(0, instructionList) == "Obstacle:"){
			Obstacle obs;
			obs.loadFromInstructions(instructionList);
		}
	}

	return true;
}
///\todo écrire cette fonction
void Level::update(int playerPositionX)
{

}

void Level::setBackground(std::string textureID)
{
	this->addTexture(textureID);
}

void Level::addObstacle(Obstacle& obstacle)
{
	m_obstacles[obstacle.getName()]=obstacle;
}

void Level::eraseObstacle(std::string obstacleName)
{
	if(m_obstacles.find(obstacleName) == m_obstacles.end()){
		WARNING("On m'a demandé de supprimer une entitée inexistante.");
		return;
	}
	m_obstacles.erase(m_obstacles.find(obstacleName));
}
