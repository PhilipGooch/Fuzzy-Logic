#include "Application.h"

Application::Application(sf::RenderWindow* window) :
	window(window)
{
	// Instantiating linguistic variables and adding their membership functions

	distance = new LinguisticVariable("distance");
	distance->addReverseGradeMF("close", 0, 30);
	distance->addTrapezoidMF("medium", 10, 30, 50, 70);
	distance->addGradeMF("far", 50, 70);

	size = new LinguisticVariable("size");
	size->addReverseGradeMF("tiny", 0, 10);
	size->addTrapezoidMF("small", 2.5, 10, 15, 20);
	size->addTrapezoidMF("moderate", 15, 20, 25, 30);
	size->addGradeMF("large", 25, 30);

	threat = new LinguisticVariable("threat");
	threat->addTrapezoidMF("low", 0, 5, 15, 20);
	threat->addTrapezoidMF("medium", 15, 25, 35, 40);
	threat->addTrapezoidMF("high", 35, 45, 55, 60);

	// Fuzzifying exact variables.

	float exactDistance = 10;
	float exactSize = 30;

	distance->fuzzify(exactDistance);
	size->fuzzify(exactSize);

	// Fuzzy values (between 0 and 1)

	float close = distance->membershipFunctions["close"]->fuzzified;
	float medium = distance->membershipFunctions["medium"]->fuzzified;
	float far = distance->membershipFunctions["far"]->fuzzified;

	float tiny = size->membershipFunctions["tiny"]->fuzzified;
	float small = size->membershipFunctions["small"]->fuzzified;
	float moderate = size->membershipFunctions["moderate"]->fuzzified;
	float large = size->membershipFunctions["large"]->fuzzified;


	// Rules


	float degreeLow = OR(OR(OR(OR(AND(tiny, medium), AND(tiny, far)), AND(small, medium)), AND(small, far)), AND(moderate, far));
	float degreeMedium = OR(OR(AND(tiny, close), AND(moderate, medium)), AND(large, far));
	float degreeHigh = OR(OR(OR(AND(small, close), AND(moderate, close)), AND(large, close)), AND(large, medium));

	threat->membershipFunctions["low"]->degree = degreeLow;
	threat->membershipFunctions["medium"]->degree = degreeMedium;
	threat->membershipFunctions["high"]->degree = degreeHigh;


	// De-fuzzification

	float lowThreat = 10;
	float mediumThreat = 30;
	float highThreat = 50;

	//float troops = (degreeLow * lowThreat + degreeMedium * mediumThreat + degreeHigh * highThreat) / (degreeLow + degreeMedium + degreeHigh);

	float troops = threat->defuzzify();

 	cout << troops;


	//// Instantiating linguistic variables and adding their membership functions

	//distance = new LinguisticVariable("distance");
	//distance->addReverseGradeMF("close", 0, 30);
	//distance->addTrapezoidMF("medium", 10, 30, 50, 70);
	//distance->addGradeMF("far", 50, 70);

	//size = new LinguisticVariable("size");
	//size->addReverseGradeMF("tiny", 0, 10);
	//size->addTrapezoidMF("small", 2.5, 10, 15, 20);
	//size->addTrapezoidMF("moderate", 15, 20, 25, 30);
	//size->addGradeMF("large", 25, 30);


	//// Fuzzifying exact variables.

	//float exactDistance = 25;
	//float exactSize = 8;

	//distance->fuzzify(exactDistance);
	//size->fuzzify(exactSize);

	//// Fuzzy values (between 0 and 1)

	//float close = distance->membershipFunctions["close"]->fuzzified;
	//float medium = distance->membershipFunctions["medium"]->fuzzified;
	//float far = distance->membershipFunctions["far"]->fuzzified;

	//float tiny = size->membershipFunctions["tiny"]->fuzzified;
	//float small = size->membershipFunctions["small"]->fuzzified;
	//float moderate = size->membershipFunctions["moderate"]->fuzzified;
	//float large = size->membershipFunctions["large"]->fuzzified;


	//// Rules

	//float degreeLow = OR(AND(medium, tiny), AND(medium, small));
	//float degreeMedium = AND(close, tiny);
	//float degreeHigh = AND(close, small);


	//// De-fuzzification

	//float lowThreat = 10;
	//float mediumThreat = 30;
	//float highThreat = 50;

	//float troops = (degreeLow * lowThreat + degreeMedium * mediumThreat + degreeHigh * highThreat) / (degreeLow + degreeMedium + degreeHigh);

	//cout << troops;

	//// Instantiating linguistic variables and adding their membership functions

	//position = new LinguisticVariable("position");
	//position->addReverseGradeMF("far left", -40, -30);
	//position->addTrapezoidMF("left", -40, -25, -15, 0);
	//position->addTriangleMF("none", -10, 0, 10);
	//position->addTrapezoidMF("right", 0, 15, 25, 40);
	//position->addGradeMF("far right", 30, 40);

	//force = new LinguisticVariable("force");
	//force->addReverseGradeMF("hard left", -40, -30);
	//force->addTrapezoidMF("left", -40, -25, -15, 0);
	//force->addTriangleMF("ahead", -10, 0, 10);
	//force->addTrapezoidMF("right", 0, 15, 25, 40);
	//force->addGradeMF("hard right", 30, 40);


	//// Fuzzifying exact variables.

	//float exactPosition = 35;

	//for (int i = 0; i < 100; i++)
	//{


	//	position->fuzzify(exactPosition);

	//	// Fuzzy values (between 0 and 1)

	//	float farLeft = position->membershipFunctions["far left"]->fuzzified;
	//	float left = position->membershipFunctions["left"]->fuzzified;
	//	float ahead = position->membershipFunctions["none"]->fuzzified;
	//	float right = position->membershipFunctions["right"]->fuzzified;
	//	float farRight = position->membershipFunctions["far right"]->fuzzified;

	//	// Rules

	//	float forceLeft = -1;
	//	float forceRight = 1;

	//	exactPosition += farLeft * forceRight + left * forceRight + right * forceLeft + farRight * forceLeft;


	//	// De-fuzzification

	//	cout << exactPosition << endl;
	//}

	run();
}

Application::~Application()
{
}

void Application::run()
{
	sf::Clock clock;
	while (window->isOpen())
	{
		sf::Time deltaTime = clock.restart();
		processEvents();
		handleInput();
		update(deltaTime.asMilliseconds());
		render();
	}

}

void Application::processEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::MouseMoved:
			input.setMousePosition(event.mouseMove.x, event.mouseMove.y);
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
				input.setMouseLeftDown(true);
			if (event.mouseButton.button == sf::Mouse::Right)
				input.setMouseRightDown(true);
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
				input.setMouseLeftDown(false);
			if (event.mouseButton.button == sf::Mouse::Right)
				input.setMouseRightDown(false);
			break;
		case sf::Event::KeyPressed:
			if(sf::Keyboard::Escape)
				window->close();
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}

void Application::handleInput()
{

}

void Application::update(float deltaTime)
{

}

void Application::render()
{

}

float Application::AND(float a, float b)
{
	return fmin(a, b);
}

float Application::OR(float a, float b)
{
	return fmax(a, b);
}

float Application::NOT(float a)
{
	return 1 - a;
}
