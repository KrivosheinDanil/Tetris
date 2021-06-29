#pragma once
class Figure
{
public:
	int x;
	int y;
	int Matrix_size;
	int number;
	int** matrix;

	Figure();//Конструктор по-умолчанию

	Figure(int x_, int y_, int number_);//Конструктор инициализирующий

	~Figure();//Деструктор фигуры
private:

};

