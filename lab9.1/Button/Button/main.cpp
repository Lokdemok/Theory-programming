#include <SFML/Graphics.hpp>
using namespace sf;
const int X = 50;
const int Y = 50;
ContextSettings settings;


bool isOn(int mouseX, int mouseY)
{
	if (((mouseX < 3 * X) && (mouseX > X))
		&& ((mouseY < 3 * Y) && (mouseY > Y)))
		return true;
	else
		return false;
}

int main()
{   
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(4 * X, 4 * Y), "Button", Style::Default, settings);
	CircleShape shape(50.f);
	shape.setFillColor(Color::White);
	// set a 10-pixel wide orange outline
	shape.setOutlineThickness(5);
	shape.setOutlineColor(Color(250, 150, 100));
	shape.setPosition(float(X), float(Y));
	Texture markTexture;
	markTexture.loadFromFile("images/galochka.png");
	markTexture.setSmooth(true);
	Sprite markSprite;
	markSprite.setTexture(markTexture);
	markSprite.scale(sf::Vector2f(0.3f, 0.3f));
	markSprite.setPosition(X * 1.5, Y * 1.5);
	bool mark = false;

	
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if ((isOn(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) && (mark == false))
			{
				shape.setFillColor(Color::Cyan);
				shape.setOutlineColor(Color::Magenta);

				if (event.type == Event::MouseButtonReleased)
				{
					shape.setFillColor(Color::Yellow);
					shape.setOutlineColor(Color(250, 150, 100));
					mark = true;

				}
			}
			else if (mark == false)
			{
				shape.setFillColor(Color::White);
				shape.setOutlineColor(Color(250, 150, 100));
			}
		}

		window.clear();
		window.draw(shape);
		if (mark)
			window.draw(markSprite);
		window.display();
	}

	return 0;
}