#include "Figure.h"

Figure::Figure() {
	x = 0;
	y = 0;
	Matrix_size = 0;
	number = 0;
	matrix = nullptr;
}

Figure::Figure(int x_, int y_, int number_) {//Конструктор фигур, которые вид которых генерируется в зависимости от переданного значения
	this->x = x_;
	this->y = y_;
	this->number = number_;
	switch (this->number)
	{
	case 1:

		Matrix_size = 3;
		matrix = new int* [Matrix_size];
		for (int i = 0; i < Matrix_size; i++) {
			matrix[i] = new int[Matrix_size];
		}
		for (int i = 0; i < Matrix_size; i++) {
			for (int j = 0; j < Matrix_size; j++) {
				matrix[i][j] = 0;
			}
		}

		matrix[0][1] = number;
		matrix[1][1] = number;
		matrix[1][2] = number;
		matrix[2][2] = number;
		break;

	case 2:

		Matrix_size = 2;
		matrix = new int* [Matrix_size];
		for (int i = 0; i < Matrix_size; i++) {
			matrix[i] = new int[Matrix_size];
		}
		for (int i = 0; i < Matrix_size; i++) {
			for (int j = 0; j < Matrix_size; j++) {
				matrix[i][j] = 0;
			}
		}

		matrix[0][0] = number;
		matrix[0][1] = number;
		matrix[1][0] = number;
		matrix[1][1] = number;
		break;

	case 3:

		Matrix_size = 3;
		matrix = new int* [Matrix_size];
		for (int i = 0; i < Matrix_size; i++) {
			matrix[i] = new int[Matrix_size];
		}
		for (int i = 0; i < Matrix_size; i++) {
			for (int j = 0; j < Matrix_size; j++) {
				matrix[i][j] = 0;
			}
		}
		matrix[0][0] = number;
		matrix[1][0] = number;
		matrix[2][0] = number;
		matrix[2][1] = number;
		break;

	case 4:

		Matrix_size = 3;
		matrix = new int* [Matrix_size];
		for (int i = 0; i < Matrix_size; i++) {
			matrix[i] = new int[Matrix_size];
		}
		for (int i = 0; i < Matrix_size; i++) {
			for (int j = 0; j < Matrix_size; j++) {
				matrix[i][j] = 0;
			}
		}
		matrix[0][1] = number;
		matrix[1][1] = number;
		matrix[2][1] = number;
		matrix[2][0] = number;
		break;
	case 5:

		Matrix_size = 4;
		matrix = new int* [Matrix_size];
		for (int i = 0; i < Matrix_size; i++) {
			matrix[i] = new int[Matrix_size];
		}
		for (int i = 0; i < Matrix_size; i++) {
			for (int j = 0; j < Matrix_size; j++) {
				matrix[i][j] = 0;
			}
		}
		matrix[0][0] = number;
		matrix[1][0] = number;
		matrix[2][0] = number;
		matrix[3][0] = number;
		break;
	case 6:

		Matrix_size = 3;
		matrix = new int* [Matrix_size];
		for (int i = 0; i < Matrix_size; i++) {
			matrix[i] = new int[Matrix_size];
		}
		for (int i = 0; i < Matrix_size; i++) {
			for (int j = 0; j < Matrix_size; j++) {
				matrix[i][j] = 0;
			}
		}
		matrix[0][0] = number;
		matrix[0][1] = number;
		matrix[0][2] = number;
		matrix[1][1] = number;
		break;

	case 7:

		Matrix_size = 3;
		matrix = new int* [Matrix_size];
		for (int i = 0; i < Matrix_size; i++) {
			matrix[i] = new int[Matrix_size];
		}
		for (int i = 0; i < Matrix_size; i++) {
			for (int j = 0; j < Matrix_size; j++) {
				matrix[i][j] = 0;
			}
		}
		matrix[0][1] = number;
		matrix[1][1] = number;
		matrix[1][0] = number;
		matrix[2][0] = number;
		break;
	}


}

Figure::~Figure() {
	for (int i = 0; i < Matrix_size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}