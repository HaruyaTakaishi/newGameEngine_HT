#pragma once
#include "ECS.h"
#include <SFML\Graphics.hpp>

struct Transform
{
public: // assumes public anyway
	ECS_DECLARE_TYPE;

	float X, Y, Rotation;

	Transform(float x, float y)
	{
		X = x; // this->X = x, java, not mandatory
		Y = y;

		Rotation = 0.0f;
	}
};
ECS_DEFINE_TYPE(Transform);

struct Sprite
{
public:
	ECS_DECLARE_TYPE;

	sf::Sprite sprite;
	std::string texture;

	int width, height;

	Sprite(std::string name)
	{
		texture = name;
	}
};
ECS_DEFINE_TYPE(Sprite);
