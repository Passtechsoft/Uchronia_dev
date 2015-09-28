#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include "../General/general.h"
#include "../Graphics/WindowEntity.h"
class NtsaWindow;

///Cette classe ressemble en tout points à VisualEffect mis à part un construxteur légèrement différent
class SpaceLaser : public VisualEffect
{
public:
	SpaceLaser(){};
	SpaceLaser(float x, float y, float height, sf::Time cycleDuration, sf::Time duration=sf::seconds(0));
};

///Classiquement, une entité représente un élément du niveau qui peut se mouvoir (un ennemi, où même un simple astéroide de passage) \n
///mais également intéragir avec les autres entités via les collisions
class Entity : public WindowEntity
{
public:
	enum Direction{Up, Down, Front, Back, Nope};

	Entity();
	Entity(std::string name, unsigned int priority, std::string textureID="");
	void stabilize();
	void stopMoving();
	void stopAcceleration();
	void moveSomewere(Direction direction);

protected:
	//The following accelerations change all the time
	float m_speedUpDown=0;
	float m_speedFront=0;

	unsigned int m_lifePoints=100;

	void setSpeedUpDown(int speed=3);
	void setSpeedFront(int speed=4);

	Direction m_directionAcceleration=Direction::Nope;///Direction de l'accélération
};

class Player : public Entity
{
public:
    Player();
    Player(std::string name, unsigned int priority, std::string textureID="");
    Player(std::string name, unsigned int priority, unsigned int width, int positionY, std::string textureID="");
    void actualiser(NtsaWindow* window);
    void fire();

private:
	Timer m_timer;
	sf::Thread* m_laserThread=nullptr;
	SpaceLaser m_laser;

    unsigned int m_energy=10000;

    float m_acceleration=1.2;///L'accélération de base
    float m_stepMultiplicator=1.2;///Acceleration de l'accélération
};

#endif // ENTITY_H_INCLUDED
