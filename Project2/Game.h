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

	void CreateMap(RenderWindow& win);//������� �������� ����� �������

	bool Collide();//�������� ��� �������� ����� ������, �������� ����� ������

	void FillMap();//���������� ������� ����� �������� ������

	void Merge();//�������� �� ������� ����� ������� ������

	bool Check(int i);//������� �������� ��� �����  ������, �����, �������, ����

	void Flip();//������� ������

	void MoveDown();//��� ����

	void MoveRight();//��� ������

	void MoveLeft();//��� �����

	void Draw(RenderWindow& win);//��������� ����������� �����

	void Restart();//������ ����

	~Game();//����������
};

