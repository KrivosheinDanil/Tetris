#include <iostream>
#include "Game.h"


#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
#include<ctime>
#include<cstdlib>

using namespace sf;
int main()
{
    srand(time(NULL));
    RenderWindow *window = new RenderWindow(sf::VideoMode(640, 700), "Tetris", sf::Style::Titlebar | sf::Style::Close);
    window->clear(Color::White);

    // ###############Создание и визуализация заднего фона и некоторых фото################## 

    Image image1;
    image1.loadFromFile("Score.png");
    Texture Score;
    Score.loadFromImage(image1); //Задний фон программы
    Sprite sprite1;
    sprite1.setTexture(Score);
    sprite1.setPosition(100 + 40 * 8, 31);
    window->draw(sprite1);

    Image image3;
    image3.loadFromFile("GameOver.png");
    Texture gameover;
    gameover.loadFromImage(image3); //Для конца игры
    Sprite sprite3;
    sprite3.setTexture(gameover);
    sprite3.setPosition(0,0);
    

    Image image;
    image.loadFromFile("Back.jpg");
    Texture textur;
    textur.loadFromImage(image); // Score
    Sprite sprite;
    sprite.setTexture(textur);
    window->draw(sprite);

    Image image2;
    image2.loadFromFile("Score1.png");
    Texture Score2;
    Score2.loadFromImage(image2); // под Score
    Sprite sprite2;
    sprite2.setTexture(Score2);
    sprite2.setPosition(100 + 40 * 8, 31+60);
    window->draw(sprite2);

    Font font;
    font.loadFromFile("ScoreFont.ttf");
    Text txt;
    txt.setFont(font);
    txt.setPosition(140 + 40 * 8, 31 + 70); // Текст кол-ва очков
    txt.setString("0");
    txt.setCharacterSize(24);
    txt.setFillColor(Color::Red);
    txt.setStyle(sf::Text::Bold);

    // ###############Создание и визуализация заднего фона ################## 

    Event ev;
    Game tetris;
    int score_value=0;
    bool start = true;

    bool restart = true;


    tetris.CreateMap(*window);

    window->display();
    window->clear();
    window->setFramerateLimit(60);
    
   

    sf::Time elapsed_time;
    sf::Clock r;
    sf::Time delta_time = sf::milliseconds(1000);
   
    while (window->isOpen()) {
        if (restart) {
            tetris.fig = new Figure(3, 0, rand() % 7 + 1);
            tetris.FillMap();
            tetris.Draw(*window);
            restart = false;
        }
            tetris.FillMap();
            tetris.Draw(*window);
            window->display();
       
        if (!tetris.Collide()) {
            elapsed_time += r.restart();
            if (elapsed_time >= delta_time) {
                tetris.Merge();
                tetris.Draw(*window);
                window->display();
                tetris.MoveDown();
                tetris.FillMap();
                tetris.Draw(*window);
                window->display();
                
                elapsed_time -= delta_time;
            }
        }
        if (tetris.Collide()) {
            if (start) {
                tetris.FillMap();
                tetris.Draw(*window);
                window->display();
            }
            for (int i = 0; i < 8; i++) {
                if (tetris.map[0][i] != 0) {
                    RenderWindow gameover(sf::VideoMode(250, 140), "Game Over", sf::Style::Titlebar | sf::Style::Close);
                    while (gameover.isOpen()) {
                        gameover.display();
                        gameover.clear();
                        start = false;
                        while (gameover.pollEvent(ev)) {
                            switch (ev.type)
                            {
                            case sf::Event::Closed:
                                gameover.close();
                                tetris.Restart();
                                tetris.Draw(*window);
                                restart = true;
                                start = true;
                                score_value = 0;
                                break;
                            }
                        }
                        gameover.draw(sprite3);
                    }
                }
            }
            if (start) {
                int temp = (rand() % 7) + 1;
                tetris.fig = new Figure(3, 0, temp);
                score_value++;
                char s[10];
                _itoa_s(score_value * 40, s, 10);
                txt.setString(s);
            }
        }
        while (window->pollEvent(ev)) {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Space) {
                    tetris.Merge();
                    tetris.Draw(*window);
                    window->display();
                    
                    tetris.Flip();
                    tetris.FillMap();
                    tetris.Draw(*window);
                    window->display();
                   
                    break;
                }
                if (ev.key.code == sf::Keyboard::D) {
                    tetris.Merge();
                    tetris.Draw(*window);
                    window->display();
                    
                    tetris.MoveRight();
                    tetris.FillMap();
                    tetris.Draw(*window);
                    window->display();
                    
                    break;
                }
                if (ev.key.code == sf::Keyboard::A) {
                    tetris.Merge();
                    tetris.Draw(*window);
                    window->display();
                    
                    tetris.MoveLeft();
                    tetris.FillMap();
                    tetris.Draw(*window);
                    window->display();
                    
                   
                    break;
                }
                if (ev.key.code == sf::Keyboard::S) {
                    tetris.Merge();
                    tetris.Draw(*window);
                    window->display();
                    
                    tetris.MoveDown();
                    tetris.FillMap();
                    tetris.Draw(*window);
                    window->display();
                    
                    break;
                }
            }
        }
        window->draw(sprite);
        window->draw(sprite1);
        window->draw(sprite2);
        window->draw(txt);
        

    }

    return 0;
}