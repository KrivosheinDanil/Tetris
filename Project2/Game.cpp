#include "Game.h"


Game::Game() {
	map = new int* [16];
	for (int i = 0; i < 16; i++) {
		map[i] = new int[8];
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {//Создание массива для Тетриса 16х8
			map[i][j] = 0;
		}
	}


}

Game::~Game() {
	for(int i = 0; i < 16; i++) {
		delete [] map[i];
	}
	delete[] map;
}

void Game::CreateMap(RenderWindow& win) {//Функция создания карты, отрисовки линий
	for (int i = 0; i <= 16; i++) {
		for (int j = 0; j <= 8; j++) {
			RectangleShape* line = new RectangleShape(Vector2f(40 * 8, 2));
			line->setFillColor(Color::Black);
			line->move(30, 30 + i * 40);
			win.draw(*line);

		}
	}
	for (int i = 0; i <= 16; i++) {
		for (int j = 0; j <= 8; j++) {
			RectangleShape* line = new RectangleShape(Vector2f(2, 40 * 16));
			line->setFillColor(Color::Black);
			line->move(30 + j * 40, 30);
			win.draw(*line);

		}
	}

	RectangleShape* line = new RectangleShape(Vector2f(40 * 16 + 30, 30));
	line->setFillColor(Color(255, 0, 255));
	line->move(0, 0);
	win.draw(*line);
	win.clear();
}

bool Game::Collide() {//Функция проверки для создания новой фигуры
	Merge();
	for (int i = fig->y; i < fig->y + fig->Matrix_size; i++) {
		for (int j = fig->x; j < fig->x + fig->Matrix_size; j++) {
			if (fig->matrix[i - fig->y][j - fig->x] != 0) {
				if (i + 1 >= 16) {
					return true;
				}
				if (map[i + 1][j] != 0) {
					return true;
				}
			}

		}
	}
	return false;
}

void Game::FillMap() {//Функция заполнения массива карты массивом Фигуры
	for (int i = fig->y; i < fig->y + fig->Matrix_size; i++) {
		for (int j = fig->x; j < fig->x + fig->Matrix_size; j++) {
			if (fig->matrix[i - fig->y][j - fig->x] != 0) {
				map[i][j] = fig->matrix[i - fig->y][j - fig->x];
			}
		}
	}
}

void Game::Merge() {//Функция очистики массива карты от массива фигуры
	for (int i = fig->y; i < fig->y + fig->Matrix_size; i++) {
		for (int j = fig->x; j < fig->x + fig->Matrix_size; j++) {
			if (fig->matrix[i - fig->y][j - fig->x] != 0) {
				map[i][j] = 0;
			}
		}
	}

}

bool Game::Check(int i) {//Функция проверки возможности перемещения для фигуры
	if (i == 2) {
		Merge();

		int** temp = new int* [fig->Matrix_size];
		for (int i = 0; i < fig->Matrix_size; i++) {
			temp[i] = new int[fig->Matrix_size];
		}


		for (int i = 0; i < fig->Matrix_size; i++) {
			for (int j = i; j < fig->Matrix_size; j++) {
				temp[i][j] = fig->matrix[j][i];
			}
		}




		for (int i = fig->y; i < fig->y + fig->Matrix_size; i++) {
			for (int j = fig->x; j < fig->x + fig->Matrix_size; j++) {
				if (temp[i - fig->y][j - fig->x] != 0) {

					if (map[i][j] != 0) {
						return false;
					}
				}
			}
		}
	}
	if (i == 1) {
		Merge();

		int temp_y = fig->y;
		int temp_x = fig->x + 1;
		for (int i = temp_y; i < temp_y + fig->Matrix_size; i++) {
			for (int j = temp_x; j < temp_x + fig->Matrix_size; j++) {
				if (fig->matrix[i - temp_y][j - temp_x] != 0) {
					if (map[i][j] != 0) {
						return false;
					}
				}
			}
		}

		return true;
	}
	if (i == -1) {
		Merge();
		int temp_y = fig->y;
		int temp_x = fig->x - 1;
		for (int i = temp_y; i < temp_y + fig->Matrix_size; i++) {
			for (int j = temp_x; j < temp_x + fig->Matrix_size; j++) {
				if (fig->matrix[i - temp_y][j - temp_x] != 0) {
					if (map[i][j] != 0) {
						return false;
					}
				}
			}
		}

		return true;
	}
	if (i == 0) {
		Merge();

		int temp_y = fig->y + 1;
		int temp_x = fig->x;
		for (int i = temp_y; i < temp_y + fig->Matrix_size; i++) {
			for (int j = temp_x; j < temp_x + fig->Matrix_size; j++) {
				if (fig->matrix[i - temp_y][j - temp_x] != 0) {
					if (map[i][j] != 0) {
						return false;
					}
				}
			}
		}

		return true;
	}
}


void Game::Flip() {//Функция переворачивания фигуры
	Merge();
	if (Check(2)) {
		for (int i = 0; i < fig->Matrix_size; i++) {
			for (int j = i; j < fig->Matrix_size; j++) {
				int temp = fig->matrix[i][j];
				fig->matrix[i][j] = fig->matrix[j][i];
				fig->matrix[j][i] = temp;
			}
		}
	}

}

void Game:: MoveDown() {//Функция опускания фигуры
	if (Check(0) && fig->y + 1 < 16) {
		fig->y++;
	}
}

void Game::MoveRight() {//Функция хода фигуры вправо
	if (Check(1)) {
		fig->x++;
	}
}

void Game::MoveLeft() {//Функция хода фигуры влево
	if (Check(-1)) {
		fig->x--;
	}
}

void Game::Draw(RenderWindow& win) {//Функция заполнения карты фигурами
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {

			if (map[i][j] == 0) {
				RectangleShape rect(Vector2f(39, 39));
				rect.setFillColor(Color::White);
				rect.move(31 + j * 40, 31 + i * 40);
				win.draw(rect);
			}
			if (map[i][j] == 1) {
				RectangleShape rect(Vector2f(39, 39));
				rect.setFillColor(Color::Yellow);
				rect.move(31 + j * 40, 31 + i * 40);
				win.draw(rect);
			}
			if (map[i][j] == 2) {
				RectangleShape rect(Vector2f(39, 39));
				rect.setFillColor(Color::Red);
				rect.move(31 + j * 40, 31 + i * 40);
				win.draw(rect);
			}
			if (map[i][j] == 3) {
				RectangleShape rect(Vector2f(39, 39));
				rect.setFillColor(Color::Blue);
				rect.move(31 + j * 40, 31 + i * 40);
				win.draw(rect);
			}
			if (map[i][j] == 4) {
				RectangleShape rect(Vector2f(39, 39));
				rect.setFillColor(Color::Magenta);
				rect.move(31 + j * 40, 31 + i * 40);
				win.draw(rect);
			}
			if (map[i][j] == 5) {
				RectangleShape rect(Vector2f(39, 39));
				rect.setFillColor(Color::Cyan);
				rect.move(31 + j * 40, 31 + i * 40);
				win.draw(rect);
			}
			if (map[i][j] == 6) {
				RectangleShape rect(Vector2f(39, 39));
				rect.setFillColor(Color::Magenta);
				rect.move(31 + j * 40, 31 + i * 40);
				win.draw(rect);
			}
			if (map[i][j] == 7) {
				RectangleShape rect(Vector2f(39, 39));
				rect.setFillColor(Color::Cyan);
				rect.move(31 + j * 40, 31 + i * 40);
				win.draw(rect);
			}
		}
	}
}

void Game::Restart()
{
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = 0;
		}
	}
}
