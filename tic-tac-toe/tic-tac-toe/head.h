#pragma once;
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
using namespace std;
using namespace sf;

class game
{
protected:
	Sprite sp9[9];
	char pole[3][3] = { { '0','0','0' },{ '0', '0', '0' },{ '0', '0', '0' } };


private:

	Image image;
	Texture texture;
	Sprite sprite;


	void check(int i, float n)
	{
		sp9[i].setTextureRect(IntRect(110 * n, 100, 89, 94));
	}
public:
	bool step = true;
	bool onePlayer = false;
	Clock compStepClock;
	game(String imag)
	{
		image.loadFromFile(imag);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		int x = 60; int y = 60; int x1 = 1; int y1 = 1;

		///////////

		x = 50; y = 50;
		x1 = 0; y1 = 0;
		for (int i = 0; i < 9; i++)
		{
			sp9[i].setTexture(texture); sp9[i].setTextureRect(IntRect(130, 240, 89, 94)); sp9[i].setPosition(x + x1, y + y1);
			x1 += 100;
			if (x1>260)
			{
				x1 = 0;
				y1 += 100;
			}

		}
		pole[3][3] = { { '0','0','0' }, { '0', '0', '0' }, { '0', '0', '0' } };



	}
	game()
	{

	}
	void reset()
	{
		pole[3][3] = { { 0,0,0 },{ 0, 0, 0 },{ 0, 0, 0 } };
		step = true;

		for (int i = 0; i < 9; i++)
		{

			sp9[i].setTextureRect(IntRect(130, 240, 89, 94));

		}

	}
	void computerStep()
	{
		Sleep(300);
		int v = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				if (pole[i][j] = "1") v += 1;
		}
		if (v == 1)//первый ход
		{
			while (true)
			{
				if (pole[1][1] != "1"&&"2") { pole[1][1] = "2"; check(4, 2); }
				else
				{
					pole[0][0] = "2"; check(0, 2);
				}
				break;
			}
		}
		/**/
		else //остальные ходы
		{
			int crest;
			int crest;
			int nul;
			int nul;
			for (int i = 1; i < 3; i++) {
				//по горизонтали
				for (int j = 0; j < 3; j++) {
					crest = 0;
					nul = 0;
					for (int k = 0; k < 3; k++) {
						if pole[j][k] = '1'
							crest++;
						if pole[j][k] = '2'
							nul++;
					}
					if (((nul = 2) && (crest = 0) && (i = 1)) || ((nul = 0) && (crest = 2) && (i = 2))) {
						for (int k = 0; k < 3; k++) {
							if pole[j][k] = '0' {
								pole[j][k] = '2';
								check(j * 3 + k + 1, 2);
								step = true;
								return;
							}
						}
					}
				}
				//вертикаль
				for (int k = 0; k < 3; k++) {
					crest = 0;
					nul = 0;
					for (int j = 0; j < 3; j++) {
						if pole[j][k] = '1'
							crest++;
						if pole[j][k] = '2'
							nul++;
					}
					if (((nul = 2) && (crest = 0) && (i = 1)) || ((nul = 0) && (crest = 2) && (i = 2))) {
						for (int k = 0; k < 3; k++) {
							if pole[j][k] = '0' {
								pole[j][k] = '2';
								check(j * 3 + k + 1, 2);
								step = true;
								return;
							}
						}
					}
				}
				//диагональ
				crest = 0;
				nul = 0;
				for (int k = 0; k < 3; k++) {
					if pole[k][k] = '1'
						crest++;
					if pole[k][k] = '2'
						nul++;
				}
				if (((nul = 2) && (crest = 0) && (i = 1)) || ((nul = 0) && (crest = 2) && (i = 2))) {
					for (int k = 0; k < 3; k++) {
						if pole[k][k] = '0' {
							pole[k][k] = '2';
							check(k * 3 + k + 1, 2);
							step = true;
							return;
						}
					}
				}
				crest = 0;
				nul = 0;
				for (int k = 0; k < 3; k++) {
					if pole[2 - k][k] = '1'
						crest++;
					if pole[2 - k][k] = '2'
						nul++;
				}
				if (((nul = 2) && (crest = 0) && (i = 1)) || ((nul = 0) && (crest = 2) && (i = 2))) {
					for (int k = 0; k < 3; k++) {
						if pole[2 - k][k] = '0' {
							pole[2 - k][k] = '2';
							check((2 - k) * 3 + k + 1, 2);
							step = true;
							return;
						}
					}
				}
			}
			//другие случаи
			int pos;
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if pole[j][k] = '2'
						pos = j * 3 + k + 1;
					if (1 <= pos) && (pos <= 3) {
						for (int l = 0; l < 3; l++) {
							if pole[0][pos - 1] = '0' {
								pole[0][pos - 1] = '2';
								step = true;
								return;
							}
						}
					}
					if (4 <= pos) && (pos <= 6) {
						for (int l = 0; l < 3; l++) {
							if pole[1][pos - 4] = '0' {
								pole[1][pos - 4] = '2';
								step = true;
								return;
							}
						}
					}
					if (7 <= pos) && (pos <= 9) {
						for (int l = 0; l < 3; l++) {
							if pole[2][pos - 7] = '0' {
								pole[2][pos - 7] = '2';
								step = true;
								return;
							}
						}
					}
				}
			}
		}
	}
																										
	void mouseClik(RenderWindow &window, Clock &clock)
	{
		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		if (onePlayer)
		{

			if (!step)
			{
				computerStep();
				step = true;
				return;
			}

			else if (step)
			{


				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (compStepClock.getElapsedTime().asMilliseconds() > 500)
					{

						compStepClock.restart();


						for (int i = 0; i < 9; i++)
						{

							if (sp9[i].getGlobalBounds().contains(pos.x, pos.y) && pole[i/3][i - (i/3)*3-1] != "x"&& pole[i / 3][i - (i / 3) * 3 - 1] != "0")
							{
								check(i, 1);
								step = false;
								pole[i / 3][i - (i / 3) * 3 - 1] = "x";
								return;
							}
						}

					}
				}


			}




		}


		else if (Mouse::isButtonPressed(Mouse::Left) && !onePlayer)
		{

			if (clock.getElapsedTime().asMilliseconds() > 500) {
				clock.restart();

					for (int i = 0; i < 9; i++)
					{
						if (sp9[i].getGlobalBounds().contains(pos.x, pos.y) && pole[i / 3][i - (i / 3) * 3 - 1] != "x"&& pole[i / 3][i - (i / 3) * 3 - 1] != "0")
						{
							if (step)
							{
								check(i, 1);
								step = false;
								pole[i / 3][i - (i / 3) * 3 - 1] = "x";
								return;
							}
							else if (!step)
							{
								check(i, 2);
								step = true;
								pole[i / 3][i - (i / 3) * 3 - 1] = "0";
								return;
							}
						}
					}

			}

		}
	}

	int winner()
	{
		char win;
		for (i = 1; i < 3; y++) {
			for (y = 0; y < 3; y++) {//Проверка по горизонтали
				flag = true;
				for (x = 0; x < 3; x++) {
					if (i = 1; pole[y][x] != '1') {
						flag = false;
					}
					if (i = 2; pole[y][x] != '2') {
						flag = false;
					}
				}
				if (flag && (i = 1)) {
					return 1;
				}
				if (flag && (i = 2)) {
					return 2;
				}
			}
			for (x = 0; x < 3; x++) {//Проверка по вертикали
				flag = true;
				for (y = 0; y < 3; y++) {
					if (i = 1; pole[y][x] != '1') {
						flag = false;
					}
					if (i = 2; pole[y][x] != '2') {
						flag = false;
					}
				}
				if (flag && (i = 1)) {
					return 1;
				}
				if (flag && (i = 2)) {
					return 2;
				}
			}


		}
		//Проверка по даигоналям
		{
			flag = true;
			if (pole[0][0] != '1' || pole[1][1] != '1' || pole[2][2] != '1') && (pole[2][0] != '1' || pole[1][1] != '1' || pole[0][2] != '1') {
				flag = false;
			}
			if (flag && (i = 1)) {
				return 1;
			}
			if (pole[0][0] != '2' || pole[1][1] != '2' || pole[2][2] != '2') && (pole[2][0] != '2' || pole[1][1] != '2' || pole[0][2] != '2') {
				flag = false;
			}
			if (flag && (i = 2)) {
				return 2;
			}
			int c = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++) {
					if (pole[i][j] = "0") {
						c++;
					}
				}

			}
			if (c == 0)return 0;
			return 3;

		}
	};


	void drawSprite(RenderWindow &w)
	{
		for (int i = 0; i < 9; i++)
		{
			w.draw(sp9[i]);
		}
	}

};
class interF//интерфейс/меню
{

	Text NewGameText;
	Text WinText; Text okText;
	Text SizeText; Text SizeText1;
	Text fonText;
	Text menuText;
	Text onePlayerText;
	Texture backgroundImage1;
	Texture backgroundImage2;
	Texture backgroundImage3;
	Texture backgroundImage4;
	Texture backgroundImage5;
	Texture backgroundImage6;
	Texture backgroundImage7;

	Sprite fonSprite;

	Clock nextFonClock;

	int isFon = 1;
public:
	interF(Font &f, game &mygame)
	{
		ifstream fin;
		fin.open("settings/фоновый рисунок.txt");
		int temp;
		fin >> temp;
		isFon = temp;
		NewGameText.setString("И г р а т ь"); NewGameText.setFont(f); NewGameText.setCharacterSize(20); NewGameText.setPosition(100, 150);
		NewGameText.setColor(Color::White);

		SizeText.setString(""); SizeText.setFont(f); SizeText.setCharacterSize(15); SizeText.setPosition(100, 240);
		SizeText.setColor(Color::White);

		WinText.setString(""); WinText.setFont(f); WinText.setCharacterSize(15); WinText.setPosition(5, 11);
		WinText.setColor(Color::Black);


		okText.setString("ОК"); okText.setFont(f); okText.setCharacterSize(15); okText.setPosition(300, 11);
		okText.setColor(Color::Red);

		menuText.setString("выйти в меню"); menuText.setFont(f); menuText.setCharacterSize(12); menuText.setPosition(10, 360);
		menuText.setColor(Color::Black);


		if (!mygame.onePlayer)onePlayerText.setString("два игрока");
		else if (mygame.onePlayer)onePlayerText.setString("один игрок");
		onePlayerText.setFont(f); onePlayerText.setCharacterSize(15); onePlayerText.setPosition(100, 200);
		onePlayerText.setColor(Color::White);

		fonText.setString("изменить фон"); fonText.setFont(f); fonText.setCharacterSize(12); fonText.setPosition(200, 360);
		fonText.setColor(Color::Black);

		backgroundImage1.loadFromFile("images/фон1.png");
		backgroundImage2.loadFromFile("images/фон2.png");
		backgroundImage3.loadFromFile("images/фон3.png");
		backgroundImage4.loadFromFile("images/фон4.png");
		backgroundImage5.loadFromFile("images/фон5.png");
		backgroundImage6.loadFromFile("images/фон6.png");
		backgroundImage7.loadFromFile("images/фон7.png");

		fonSprite.setPosition(0, 0);


	}
	bool mainMenu = true;
	bool winner = false;

	Text getMainText()
	{
		return NewGameText;
	}
	Text getWinText()
	{
		return WinText;
	}
	void mouseClik(RenderWindow &window, Clock &clock, game &mygame)
	{
		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);// переводим в игровые

		if (mainMenu == true)
		{
			if (NewGameText.getGlobalBounds().contains(pos.x, pos.y))NewGameText.setCharacterSize(21);
			else NewGameText.setCharacterSize(20);


			if (SizeText.getGlobalBounds().contains(pos.x, pos.y))SizeText.setCharacterSize(16);
			else SizeText.setCharacterSize(15);

			if (onePlayerText.getGlobalBounds().contains(pos.x, pos.y))onePlayerText.setCharacterSize(16);
			else onePlayerText.setCharacterSize(15);

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (clock.getElapsedTime().asMilliseconds() > 500)
				{
					clock.restart();

					if (NewGameText.getGlobalBounds().contains(pos.x, pos.y))
					{

						mainMenu = false;
						mygame.compStepClock.restart();


					}
					else if (SizeText.getGlobalBounds().contains(pos.x, pos.y))
					{
					}
					else if (onePlayerText.getGlobalBounds().contains(pos.x, pos.y))
					{
						ofstream fout;
						fout.open("settings/количество игроков.txt");

						if (mygame.onePlayer)
						{
							onePlayerText.setString("Два игрока");
							mygame.onePlayer = false;
							fout << 2;


						}
						else if (!mygame.onePlayer)
						{
							onePlayerText.setString("Один игрок");
							mygame.onePlayer = true;
							fout << 1;
						}
						fout.close();

					}
						ofstream fout; fout.open("size.txt");
						fout << 1;
				}
			}
		}
		else if (mainMenu == false)
		{

			fonText.setColor(Color::Black);
			if (fonText.getGlobalBounds().contains(pos.x, pos.y))fonText.setColor(Color::Red);

			menuText.setColor(Color::Black);
			if (menuText.getGlobalBounds().contains(pos.x, pos.y))menuText.setColor(Color::Red);




			if (Mouse::isButtonPressed(Mouse::Left))
			{


				if (nextFonClock.getElapsedTime().asMilliseconds() > 400)
				{

					if (fonText.getGlobalBounds().contains(pos.x, pos.y))
					{
						nextFonClock.restart();
						ofstream fout;
						fout.open("settings/фоновый рисунок.txt");
						isFon += 1;
						fout << isFon;
						if (isFon > 7)isFon = 1;
					}

					else if (menuText.getGlobalBounds().contains(pos.x, pos.y))
					{
						mainMenu = true;
					}
					else if (okText.getGlobalBounds().contains(pos.x, pos.y))
					{

						mygame.reset();
						winner = false;
						bool step;
						step = true;

					}
				}


			}

		}


	}
	void Win(game &mygame, RenderWindow& window)
	{
		if (mygame.step == true)
		{
			if (mygame.onePlayer)WinText.setString("ваш ход");
			else WinText.setString("ходят Крестики");
		}
		else
		{
			if (mygame.onePlayer)WinText.setString("ходит компютер");
			else WinText.setString("ходят Нолики");
		}
		if (mygame.winner() == 1)
		{
			if (mygame.onePlayer)WinText.setString("вы победили");
			else WinText.setString("победили крестики");

			winner = true;
		}
		else if (mygame.winner() == 2)
		{
			if (mygame.onePlayer)WinText.setString("вы проиграли");
			else WinText.setString("победили нолики");


			winner = true;
		}
		else if (mygame.winner() == 0)
		{
			WinText.setString("Ничья");


			winner = true;
		}
	}

	void Draw(game &mygame, RenderWindow &window, Clock &clock, Sprite & size3x3Sprite)
	{
		if (mainMenu == true)
		{

			window.draw(NewGameText);
			window.draw(SizeText);
			window.draw(SizeText1);
			window.draw(onePlayerText);
			mouseClik(window, clock, mygame);
		}
		else if (mainMenu == false)
		{


			if (!winner)mygame.mouseClik(window, clock);
			mouseClik(window, clock, mygame);
			Win(mygame, window);
			switch (isFon)
			{
			case 1:fonSprite.setTexture(backgroundImage1);
				break;
			case 2:fonSprite.setTexture(backgroundImage2);
				break;
			case 3:fonSprite.setTexture(backgroundImage3);
				break;
			case 4:fonSprite.setTexture(backgroundImage4);
				break;
			case 5:fonSprite.setTexture(backgroundImage5);
				break;
			case 6:fonSprite.setTexture(backgroundImage6);
				break;
			case 7:fonSprite.setTexture(backgroundImage7);
				break;
			}
			window.draw(fonSprite);
			window.draw(size3x3Sprite);
			mygame.drawSprite(window);
			window.draw(WinText);
			window.draw(fonText);
			window.draw(menuText);
			if (winner)window.draw(okText);

		}



	}
};
