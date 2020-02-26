#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Input.h"

#include "LinguisticVariable.h"

#include <iostream>

#define WIDTH 640
#define HEIGHT 480

using namespace std;

class Application
{
public:

	Application(sf::RenderWindow* window);
	~Application();

private:

	sf::RenderWindow* window;

	Input input;

	void run();
	void processEvents();
	void handleInput();
	void update(float deltaTime);
	void render();

	LinguisticVariable *distance, *size, *threat;

	LinguisticVariable *position, *force;

	float AND(float a, float b);
	float OR(float a, float b);
	float NOT(float a);
};

