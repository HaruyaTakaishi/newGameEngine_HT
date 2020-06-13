#include "Engine.h"


Engine::Engine()
{

}



Engine::~Engine()
{

}

Engine& Engine::GetInstance()
{
	static Engine _instance;

	return _instance;
}

void Engine::Start(sf::RenderWindow* win)
{
	bIsQuit = false;
	window = win;  // in java this.window = win, use -> for c++

	// run the program as long as the window is open
	while (window->isOpen() == true)
	{
		Update();
	}
}

void Engine::Update()
{
	sf::Event _event;

	while (window->pollEvent(_event))
	{
		// "close requested" event, close window
		if (_event.type == sf::Event::Closed)
		{
			std::cout << "Closing now..." << std::endl;
			window->close();
		}

	}
}