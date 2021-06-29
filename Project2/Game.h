#include"Figure.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>

#pragma once
using namespace sf;
using namespace std;
class Game
{
public:
	Game();

	int** map;
	Figure *fig;

	void CreateMap(RenderWindow& win);//Функция создания карты Тетриса

	bool Collide();//Проверка для создания новой фигуры, котторая будет падать

	void FillMap();//Заполнение массива карты массивом фигуры

	void Merge();//Удаление из массива карты массива фигуры

	bool Check(int i);//Функция проверки для ходов  вправо, влево, поворот, вниз

	void Flip();//Поворот фигуры

	void MoveDown();//Ход вниз

	void MoveRight();//Ход вправо

	void MoveLeft();//Ход влево

	void Draw(RenderWindow& win);//Отрисовка заполненной карты

	void Restart();//Рестар игры

	~Game();//Деструктор
};

