#ifndef UI_H_DEFINED
#define UI_H_DEFINED

#include "../Graphics/ntsa.h"

void affIntro(sf::RenderWindow *window, std::vector<std::string> imagesFiles);

class MainUI {
	public:
		// Our button click handler.
		void OnButtonClick();

		void Run(uint width, uint height);

	private:
		// Create an SFGUI. This is required before doing anything with SFGUI.
		sfg::SFGUI m_sfgui;

		// Create the label pointer here to reach it from OnButtonClick().
		sfg::Label::Ptr m_label, m_label2;
};


#endif // UI_H_DEFINED
