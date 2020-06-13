#include <SFML\Graphics.hpp>
#include "Engine.h"


int main(int argc, char args[])
{
	Engine& gameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	gameEngine.Start(&window);  // & means address, so of window, pass window reference to engine and start
	

	return 0; // not mandatory
}
