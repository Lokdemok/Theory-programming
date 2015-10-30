#include"head.h"

int main()
{

	Image imag1; imag1.loadFromFile("images/fon3X3.png");
	Texture texture1; texture1.loadFromImage(imag1);
	Sprite size3x3Sprite;
	size3x3Sprite.setTexture(texture1); size3x3Sprite.setPosition(0, 0);

	Texture fonImage; fonImage.loadFromFile("images/фон.png");
	Sprite fonImageSprite; fonImageSprite.setTexture(fonImage); fonImageSprite.setPosition(0, 0);
	RenderWindow window(VideoMode(400, 400), "tic-tac-toe");

	Font font; font.loadFromFile("fonts/8427182.ttf");

	game mygame("images/XO.png");
	ifstream fin;
	int  temp;
	fin.close(); fin.open("settings/количество игроков.txt");
	fin >> temp;
	if (temp == 1)mygame.onePlayer = true;
	else if (temp == 2)mygame.onePlayer = false;
	interF inter(font, mygame);
	Clock clock;



	while (window.isOpen())// главный цикл программы
	{



		Event event;
		while (window.pollEvent(event))// если нажали закрыть ,закрывается окно
		{
			if (event.type == Event::Closed)window.close();

		}
		window.clear(Color::White);//очистка экрана белым цветом
		window.draw(fonImageSprite);
		inter.Draw(mygame, window, clock, size3x3Sprite);// рисует поля/тексты/обрабатывает клик мыши
		window.display();//все выводит на экран

	}
	return 0;

}
