#include <Windows.h>
#include <iostream>

#include "zombie_architect.hpp"

int CALLBACK WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdLine, int _nCmdShow)
{
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML Works!");
	sf::Font font;
	sf::Text text;
	sf::Clock clock;



	if(!font.loadFromFile("Fonts\\Times.ttf"))
	{
		return 0;
	}

	text.setFont(font);
	text.setString("Hello World.\nHow Are you?");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);

	while(window.isOpen())
	{
		sf::Time time = clock.restart();
		sf::Event event;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		if(sf::Mouse::getPosition(window).x < 0)
			sf::Mouse::setPosition(sf::Vector2i(0,sf::Mouse::getPosition(window).y), window);

		text.setString(std::to_string(time.asMicroseconds())+"\n");
		window.clear();
//		window.draw(text);
		text.setString(std::to_string(sf::Mouse::getPosition(window).x));

		window.draw(text);
		window.display();
	}

	return 0;
}