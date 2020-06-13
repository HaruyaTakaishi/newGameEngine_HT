#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

class Engine
{
	private:

		bool bIsQuit;

		Engine();
		//singleton: required to prevent the reference from being copied or moved or assigned
		Engine(Engine& copy);   //hides copy contructor
		Engine(Engine&& other);   //hide move constructor
		Engine& operator= (Engine& copy); //hide assignment operator

		~Engine();

		void Update();

public:
	sf::RenderWindow * window;

	static Engine& GetInstance();

	void Start(sf::RenderWindow* win)

};

