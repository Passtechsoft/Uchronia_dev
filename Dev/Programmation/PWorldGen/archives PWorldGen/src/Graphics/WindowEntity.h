#ifndef WINDOWENTITY_H_INCLUDED
#define WINDOWENTITY_H_INCLUDED

#include "../General/general.h"
#include "../General/rect.h"

class WindowEntity : public Rect
{
public:
    WindowEntity();
    WindowEntity(std::string name, unsigned int priority, std::string textureID="");
    void loadFromInstructions(std::string instructionString);
    void addTexture(std::string textureID);
    void hideSprite(int sprite = -1);
    void showSprite(int sprite = -1);
    void setZone(float newPosX, float newPosY, float newWidth=0, float newHeight=0);

    ///Par défaut, cette fonction crée un nouveau sprite, sinon elle sélectionne ceux demandés
    void setActuals(int sprite=-1, int texture = 0);//Si sprite ou texture == -1, alors on en crée de nouveaux
    std::string getName(){return m_name;};

protected:
	void actuateSprite();

	sf::Sprite* m_actualSprite=nullptr;
	sf::Texture* m_actualTexture=nullptr;

    std::vector<sf::Sprite*> m_sprites;
    std::vector<sf::Texture*> m_textures;

    std::string m_name="Robert Paulson";
    unsigned int m_priority=PRIORITY_CENTER;
};

///Une classe gérant effet visuel temporaire
class VisualEffect : public WindowEntity
{
public:
	VisualEffect(){};
	VisualEffect(float x, float y, float width, float height, sf::Time cycleDuration, sf::Time duration=sf::seconds(0));
	void operator()();

	enum Remote{Stop, Continue};
protected:
	void updateAction(int cycleActuel){};//Cette fonction existe uniquement pour ètre réécrite dans les classes filles

	Remote m_remote=Remote::Continue;

	Timer m_timer;//Le timer qui décompte le temps avant le fin de l'effet
	sf::Time m_duration;//La durée totale du laser
	sf::Time m_cycleDuration;///La durée d'un cycle

	bool m_active=false;
};

#endif // WINDOWENTITY_H_INCLUDED
