#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "../General/general.h"
#include "../Graphics/WindowEntity.h"
#include "../Game/entity.h"

class Obstacle : public Entity
{
public:
	Obstacle(){};
	Obstacle(std::string texture, float x, float y, unsigned int width=0, unsigned int lifePoints=0, unsigned int height=0);

private:

};

///La classe level gère tout ce qui a trait au niveau: background, obstacles, ennemis, c'est \n
///elle qui gère les collisions entre objets à l'intérieur du niveau
class Level : public WindowEntity
{
public:
	Level();
    Level(std::string indexFileName, int playerPositionX, PublicRect zone);

    void update(int playerPositionX);
    void setBackground(std::string textureID);
    bool loadFromFile(std::string file);
    void addObstacle(Obstacle& obstacle);
    void eraseObstacle(std::string obstacleName);

private:
    sf::Texture m_backgroundText;
    sf::Sprite m_backgroundSprite;
    std::map<std::string, Obstacle> m_obstacles;

    std::string m_name;
    unsigned int m_levelLenght=4000;
};

#endif // LEVEL_H_INCLUDED
