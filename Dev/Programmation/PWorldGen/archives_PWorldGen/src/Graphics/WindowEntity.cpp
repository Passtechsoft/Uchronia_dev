#include "WindowEntity.h"

/*     ***************************      *\
            Class WindowEntity
\*     ***************************      */

WindowEntity::WindowEntity()
{
	affInDebug(":7:: constructor", DEBUG);
}

WindowEntity::WindowEntity(std::string name, unsigned int priority, std::string textureID)
	: m_name(name), m_priority(priority)
{
	INFO(std::endl<<std::endl<<":7:: Création d'un WindowEntity le biennommé \""<<name<<" =====================");
	if(textureID!="")
		addTexture(textureID);
}

///\todo Interpréter les strings comme des entiers pour priority
void WindowEntity::loadFromInstructions(std::string instructionString)
{
	std::string word=getWord(0, instructionString);
	unsigned int c=1;
	for(;!word.empty(); c++)
	{
		switch(c)
		{
			case 1:
				m_name=word;
				break;
			case 2:
				m_priority=PRIORITY_CENTER;//  <----------  ICI
				break;
			case 3:
				addTexture(word);
				break;
			case 4:
				WARNING("Il y a trop de paramètres pour "<<m_name<<", veuillez corriger ce genre de bug suspects S.V.P.");
				break;
			default:
				break;
		}
		word=getWord(c, instructionString);
	}
}
///\note Check 1
void WindowEntity::setZone(float newPosX, float newPosY, float newWidth, float newHeight)
{
    m_posX=newPosX;
    m_posY=newPosY;
    if(newWidth)
        m_width=newWidth;
    if(newHeight)
        m_height=newHeight;

    m_actualSprite->setPosition(newPosX, newPosY);
    //Le petit calcul qui redimentionne le sprite aux m_width et m_height désirés
    m_actualSprite->setScale(sf::Vector2f(m_width/m_actualSprite->getLocalBounds().width, m_height/m_actualSprite->getLocalBounds().height));
}


///\note check 1
void WindowEntity::actuateSprite()
{
    affInDebug(":3:: Actualisation du sprite "<<m_name<<"_sprite", DEBUG);

    //Ce pointeur contient l'adresse du sprite, voir SpriteList::AddSprite pour plus d'info sur ce qu'il en retourne
    sf::Sprite* sprite = SpriteList::getGeneralSpriteList()->AddSprite(sf::Sprite(), m_name+"_sprite", m_priority);

    //Si le sprite n'existe pas, cela signifie qu'il faut égalemnt l'ajouter dans le tableau de sprites
    if(m_actualSprite == nullptr)
    	m_sprites.push_back(sprite);
    m_actualSprite=sprite;//actuateSprite manipule uniquement le sprite a défaut

    if(m_actualTexture != nullptr)
        sprite->setTexture(*m_actualTexture, true);
    else
        affInDebug("Rappele toi le segfault. Pas bon les sprites sans textures, pas bon...", ERROR);
    setZone(m_posX, m_posY, m_width, m_height);
}

void WindowEntity::addTexture(std::string textureID)
{
    affInDebug(":2:: Ajout de la texture \""<<textureID<<"\" dans "<<m_name<<".", INFO);
    sf::Texture* text=TextureList::getGeneralTextureList()->getTexture(textureID);
    if(text!=nullptr){//Si la texture existe bien
        m_textures.push_back(text);
        if(!m_actualTexture)
        	m_actualTexture=text;
        actuateSprite();
    }
    else
        WARNING(":2:: La texture \""<<textureID<<"\" n'est pas dans la generalTextureList");
}

void WindowEntity::setActuals(int sprite, int texture)
{
	//Deux tests pour éviter les segfaults:
	if(sprite < -1){
		sprite = 0;
		WARNING(":6:: l'id de sprite donné n'est pas valide, cette entrée invalide selectionnera le sprite par défaut: 0");
	}
	if(texture < -1){
		texture = 0;
		WARNING(":6:: l'id de texture donné n'est pas valide, cette entrée invalide selectionnera la texture par défaut: 0");
	}

	if(texture == -1)
		m_actualTexture=m_textures[0];//On séléctionne la texture par défaut
	else
		m_actualTexture=m_textures[texture];

	if(sprite == -1)
		m_actualSprite=0;//Cela créera un nouveau sprite
	else if(sprite != -1 && texture == -1 && sprite<=m_textures.size()){
		m_actualSprite=m_sprites[sprite];
		m_actualTexture=m_textures[sprite];
	}
	else
		m_actualSprite=m_sprites[sprite];
}

/*     ***************************      *\
            Class VisualEffect
\*     ***************************      */

VisualEffect::VisualEffect(float x, float y, float width, float height, sf::Time cycleDuration, sf::Time duration)
{
	m_posX=x;
	m_posY=y;
	m_width=width;
	m_height=height;
	m_cycleDuration=cycleDuration;
	if(duration.asSeconds() != 0)
		m_duration=duration;
	else
		ERROR("VisualEffect::start Cette fonction n'a pas encore été implémentée");
}

///Cette fonction est lancée dans le thread \a m_thread à l'appel de l'effet, pour plus de modularité, \n
///elle ne fais rien en elle même mais appelle la fonction
void VisualEffect::operator()()
{
	m_sprites[0]->setPosition(m_posX, m_posY);
	m_timer.restart();
	m_active=true;

	for(unsigned int m_cycleFlag=0; m_active; m_cycleFlag++)
	{
		if(m_cycleFlag > m_sprites.size()-1)
			m_cycleFlag=0;
		if(m_timer.getElapsedTime() > m_cycleDuration || m_remote == VisualEffect::Remote::Stop)
			m_active=false;

		updateAction(m_cycleFlag);//On actualise l'action
		sf::sleep(m_cycleDuration);//On attend le temps d'un cycle
	}

	for(unsigned int c=0; c!=m_sprites.size(); c++)
		m_sprites[c]->setPosition(INT_IMPROBABLE/4, m_posY);//On replace les sprites à shaille
}
