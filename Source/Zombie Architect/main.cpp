#include <Windows.h>
#include <iostream>
#include "zombie_architect.h"
#include "ShaderProgram.h"

using namespace ZA_Game;

int CALLBACK WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdLine, int _nCmdShow)
{
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML Works!");
	glewInit();

	sf::Font font;
	sf::Text text;
	sf::Clock clock;

	sf::Texture texture;
	if(!texture.loadFromFile("./Images/tiles.png"))
	{
		return 0;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(100,100);

	ShaderProgram shader;
	if(!shader.initialize("./Shaders/vertex_shader.vert", "./Shaders/pixel_shader.frag"))
		return 0;

	sf::Shader sh;



	if(!sh.loadFromFile("./Shaders/vertex_shader.vert", "./Shaders/pixel_shader.frag"))
		return 0;

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
		window.clear();

		sf::Time time = clock.restart();
		sf::Event event;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			window.close();

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
			
		sf::Shader::bind(&sh);

		window.draw(sprite);

		sf::Shader::bind(NULL);


		if(sf::Mouse::getPosition(window).x < 0)
			sf::Mouse::setPosition(sf::Vector2i(0,sf::Mouse::getPosition(window).y), window);

		text.setString(std::to_string(time.asMicroseconds())+"\n");
		text.setString(std::to_string(sf::Mouse::getPosition(window).x));

		window.draw(text);
		window.display();
	}

	return 0;
}