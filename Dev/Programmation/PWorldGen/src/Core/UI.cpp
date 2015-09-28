#include "UI.h"

void MainUI::OnButtonClick() {
	m_label->SetText( "Hello SFGUI, pleased to meet you!" );
}

void MainUI::Run(uint width, uint height) {

	// Create SFML's window.
	NtsaWindow MainUI( sf::VideoMode( width, height ), "Pangea World Generator     v0.0.1" );
	sf::RenderWindow *render_window = MainUI.getRenderWindow();
	affIntro(render_window, std::vector<std::string>{"Datas/pangea logo.png", "Datas/thetriangle.png"});

	// Create the label.
	m_label = sfg::Label::Create( "Hello world!" );
	m_label2 = sfg::Label::Create( "mama" );

	// Create a simple button and connect the click signal.
	auto button = sfg::Button::Create( "Greet SFGUI!" );
	//button->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &MainUI::OnButtonClick, this ) );

	// Create a vertical box layouter with 5 pixels spacing and add the label
	// and button to it.
	auto box = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.0f );
	box->Pack( m_label );

	box->Pack( button, false );

	auto box2 = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 6.0f );

	box2->Pack( m_label2 );

	// Create a window and add the box layouter to it. Also set the window's title.
	auto window = sfg::Window::Create();
	window->SetTitle( "Hello world!" );
	window->Add( box );

	window->Add(box2);


	// Create a desktop and add the window to it.
	sfg::Desktop desktop;
	desktop.Add( window );

	// We're not using SFML to render anything in this program, so reset OpenGL
	// states. Otherwise we wouldn't see anything.
	render_window->resetGLStates();

	// Main loop!
	sf::Event event;
	sf::Clock clock;

	while( render_window->isOpen() ) {
		// Event processing.
		while( render_window->pollEvent( event ) ) {
			desktop.HandleEvent( event );

			// If window is about to be closed, leave program.
			if( event.type == sf::Event::Closed ) {
				render_window->close();
			}
		}

		// Update SFGUI with elapsed seconds since last call.
		desktop.Update( clock.restart().asSeconds() );

		// Rendering.
		render_window->clear();
		m_sfgui.Display( *render_window );
		render_window->display();
	}
}

void affIntro(sf::RenderWindow *window, std::vector<std::string> imagesFiles)
{
	std::vector<sf::Texture> textures;
	textures.resize(imagesFiles.size());
	std::vector<sf::Sprite> sprites;
	sprites.resize(imagesFiles.size());

	uint correctImageSize = window->getSize().x/imagesFiles.size();

	window->clear();
	if (imagesFiles.size() > 10)
		WARNING("Pourquoi tant de laine?");

	for (uint c=0; c != imagesFiles.size(); ++c){
		if(!textures[c].loadFromFile(imagesFiles[c]))
		WARNING("Image "<<imagesFiles[c]<<" introuvable.");
		sprites[c].setTexture(textures[c]);
		sprites[c].setPosition(correctImageSize*c, 0);
		sprites[c].setScale(correctImageSize/textures[c].getSize().x, 1);
		window->draw(sprites[c]);
	}
	window->display();
	sleep(2);
}
