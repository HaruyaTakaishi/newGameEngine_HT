#include "RenderingSystem.h"

RenderingSystem::RenderingSystem()
{
}

RenderingSystem::~RenderingSystem()
{
}

void RenderingSystem::tick(ECS::World* world, float deltaTime)
{
	Engine::GetInstance().window->clear();
	world->each<Transform, Sprite>( // Call "each" func to one time lmbda func// pass entity, transform, and sprite byref (byval is taking a copy)
		[&](ECS::Entity* ent,
			ECS::ComponentHandle<Transform> transform,
			ECS::ComponentHandle<Sprite> sprite)
		->void
		{
		//Add texture to map
			if (textureMap.count(sprite->texture) < 1)
			{
				textureMap[sprite->texture] = loadTexture(sprite->texture);
			}

			//if there is not a texture, add it
			if (sprite->sprite.getTexture() == NULL)
			{
				sprite->sprite.setTexture(*textureMap[sprite->texture]);
				sprite->width = sprite->sprite.getGlobalBounds().width;
				sprite->height = sprite->sprite.getGlobalBounds().height;
			}

			//update and draw to the screen
			sprite->sprite.setPosition(transform->X, transform->Y);
			Engine::GetInstance().window->draw(sprite->sprite);
		}
);
	//display updates
	Engine::GetInstance().window->display();
}

sf::Texture* RenderingSystem::loadTexture(std::string Texture)
{
	sf::Texture* _tex = new sf::Texture();

	if (_tex->loadFromFile(Texture) == NULL)
	{
	std::cerr << "Unable to load image" << Texture << "./n is this image the correct directory?" << std::endl;
	std::cerr << "Error:" << std::endl;

	exit(EXIT_FAILURE);
	}

	return _tex;
}