#include "entity.h"
#include "ntsa.h"

#define PLAYER_STEP_MS 20
#define PLAYER_LIMIT_SPEED 100

Entity::Entity() : WindowEntity()
{}

Entity::Entity(std::string name, unsigned int priority, std::string textureID)
	: WindowEntity(name, priority, textureID)
{}

void Entity::stabilize()
{
	m_speedUpDown=0;
}

void Entity::stopAcceleration()
{
	m_directionAcceleration=Direction::Nope;
}

void Entity::stopMoving()
{
	m_speedUpDown=0;
	m_speedFront=0;
}

void Entity::moveSomewere(Direction direction)
{
    if(direction==Direction::Up)
    	m_directionAcceleration=Direction::Up;
    else if(direction==Direction::Down)
    	m_directionAcceleration=Direction::Down;
}

/*     ***************************      *\
            Class Player
\*     ***************************      */

Player::Player() : Entity()
{
	m_posY=200;
	m_timer.restart();
	m_laser=SpaceLaser(m_posY, m_posX, m_height, sf::milliseconds(200), sf::seconds(2));
}

Player::Player(std::string name, unsigned int priority, std::string textureID)
	: Entity(name, priority, textureID)
{
	m_posY=200;
	m_timer.restart();
	m_laser=SpaceLaser(m_posY+m_width, m_posX, m_height, sf::milliseconds(200), sf::seconds(2));
}

Player::Player(std::string name, unsigned int priority, unsigned int width, int positionY, std::string textureID)
	: Entity(name, priority, textureID)
{
	setZone(400, positionY, width, width);
	m_timer.restart();
	//m_laser=SpaceLaser(m_posX, m_posY, m_m_height, sf::milliseconds(200), sf::seconds(2));
}

void Player::actualiser(NtsaWindow* currentWindow)
{
	m_timer.start();
	int mstime=m_timer.getElapsedTime().asMilliseconds();

	while(mstime >= PLAYER_STEP_MS)
	{
		if(m_directionAcceleration==Direction::Up)
			m_speedUpDown-=m_acceleration;
		else if(m_directionAcceleration==Direction::Down)
			m_speedUpDown+=m_acceleration;

		if((m_directionAcceleration==Direction::Up && m_speedUpDown>0) || (m_directionAcceleration==Direction::Down && m_speedUpDown<0))
			m_speedUpDown*=1/((m_stepMultiplicator-1)*2+1);
		else if(m_directionAcceleration != Direction::Nope)
			m_speedUpDown*=m_stepMultiplicator;

		if(m_speedUpDown > PLAYER_LIMIT_SPEED)
			m_speedUpDown = PLAYER_LIMIT_SPEED;

		m_posX+=m_speedUpDown;

		if(m_posX<0){
			m_posX=0;
			m_speedUpDown*=-((float)RAND(-9, 4)/10+1);
		}
		else
		{
			int posLimit=currentWindow->getSize(NtsaWindow::PosNames::Y)-m_height;
			if(m_posX>posLimit){
				m_posX=posLimit;
				m_speedUpDown*=-((float)RAND(-9, 4)/10+1);
			}
		}
		mstime-=200;
		setPosition(m_posY, m_posX);
		if(mstime < PLAYER_STEP_MS)//Si on a fini de faire le compte
			m_timer.restart();
	}
}

//\todo implémenter le multitir
void Player::fire()
{
	/*if(m_laserThread!=nullptr)
	{
		m_laserThread->wait();
		delete m_laserThread;
	}
	m_laserThread = new sf::Thread(m_laser);
	m_laserThread->launch();*/
}

/*     ***************************      *\
            Class SpaceLaser
\*     ***************************      */

SpaceLaser::SpaceLaser(float x, float y, float m_height, sf::Time cycleDuration, sf::Time duration)
	: VisualEffect(x, y, m_sprites[0]->getLocalBounds().width * (m_height/m_sprites[0]->getLocalBounds().height), m_height, cycleDuration, duration)
{}
