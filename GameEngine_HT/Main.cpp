#include <SFML\Graphics.hpp>
#include "Engine.h"


int main(int argc, char args[])
{
	Engine& gameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	//create world for attaching entities and system to
	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* ent;

	//add system to engine
	gameEngine.AddSystem(new RenderingSystem());

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			ent = gameEngine.world->create();

			//assign
			ent->assign<Transform>(i * 25, j * 32);
			ent->assign<Sprite>("../Debug/image/herosheet.png");

			std::cout << ent->getEntityId() << "is Entity ID" << std::endl;
		}
	}

	gameEngine.Start(&window);  // & means address, so of window, pass window reference to engine and start
	

	return 0; // not mandatory
}
