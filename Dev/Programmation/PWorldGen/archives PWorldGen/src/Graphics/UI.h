#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "../General/general.h"
#include "../Graphics/WindowEntity.h"

///The Button class is a simple UI element that does exactly what it mean
class Button : public WindowEntity
{
public:
	Button(){};

    Button(std::string name, unsigned int priority, std::string texture="");

    Button(std::string name, unsigned int priority, float x, float y, float l, float h, std::string texture="");

    bool isPressed(sf::RenderWindow* currentWindow);

	void setAction(std::string action){m_action=action;};
	std::string getAction(){return m_action;};

private:
	std::string m_action;
    bool m_pressed=false;
};

#endif // BUTTON_H_INCLUDED
