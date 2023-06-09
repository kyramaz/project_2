#include <shapes.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;
using namespace sh;

int main()
{
    const int x = 1280;
    const int y = 720;
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size = 20;
    int size_up = 5;
    bool FlagStop = false;
    int mas_moves[5][2];
    int mas_pos1[10][2];
    int mas_pos2[5][2];

    sf::RenderWindow window(sf::VideoMode(x, y), "Window", sf::Style::Default); // создание окна
    window.setVerticalSyncEnabled(true);

    sf::CircleShape MainCircle(size);
    MainCircle.setFillColor(sf::Color::Green);
    MainCircle.setPosition(x / 2 - size, y / 2 - size);

    sf::CircleShape circle_eat[10];
    Circles circle[10];
    for (int i = 0; i < 10; i++)
    {   
        circle[i].set_circle(circle_eat[i]);
        circle[i].set_radius(10);
        circle[i].set_color(sf::Color::Green);
        circle[i].change_position();
    }

    sf::CircleShape circle_trap[5];
    Traps trap[5];
    for (int i = 0; i < 5; i++)
    {
        trap[i].set_circle(circle_trap[i]);
        trap[i].set_radius(10);
        trap[i].set_color(sf::Color::Red);
        trap[i].change_position();
    }

    sf::Font font;
    font.loadFromFile("Media/Georgia.ttf");
    sf::Text end;
    end.setFont(font);
    end.setCharacterSize(30);
    end.setFillColor(sf::Color(0x000080FF));
    end.setStyle(sf::Text::Bold);
    end.setPosition(10, 10);
    string score = "Score:" + to_string(size);
    end.setString(score);


    for (int i = 0; i < 5; i++)             // установка ходов для каждых шипов
    {
        for (int j = 0; j < 2; j++)
        {
            mas_moves[i][j] = get_random_number(-1, 1);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        while (mas_moves[i][0] == 0 && mas_moves[i][1] == 0)
        {
            mas_moves[i][0] = get_random_number(-1, 1);
            mas_moves[i][1] = get_random_number(-1, 1);
        }
    }

    sf::Texture back;                // background texture
    back.loadFromFile("Media/book.jpg");
    sf::Sprite sprite;
    sf::Vector2u s = back.getSize();
    sprite.setTexture(back);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //FIX(MainCircle, size, x, y);

        if (MainCircle.getRadius() >= 150 && end.getFillColor() != sf::Color::Red) // условие успешного окончания
        {
            FlagStop = true;
            end.setFillColor(sf::Color::Green);
            end.setString("You won!");
            end.setPosition(x / 3 - 50, y / 2 - 100);
            end.setCharacterSize(100);
        }

        for (int i = 0; i < 10; i++)                // координаты каждого объекта
        {
            mas_pos1[i][0] = circle[i].get_pos_x();
            mas_pos1[i][1] = circle[i].get_pos_y();
        }
        for (int i = 0; i < 5; i++)
        {
            mas_pos2[i][0] = trap[i].get_pos_x();
            mas_pos2[i][1] = trap[i].get_pos_y();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        int mx = sf::Mouse::getPosition(window).x;  // движение мышкой
        int my = sf::Mouse::getPosition(window).y;
        int xx = MainCircle.getPosition().x + size;
        int yy = MainCircle.getPosition().y + size;
        if (mx != xx && my != yy)
        {
            MainCircle.move(0.04 * (mx - xx), 0.04 * (my - yy));
        }

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (MainCircle.getPosition().x >= 0))
        {MainCircle.move(-10, 0);}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (MainCircle.getPosition().x <= x - 2 * size))
        {
            MainCircle.move(10, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (MainCircle.getPosition().y >= 0))
        {
            MainCircle.move(0, -10);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (MainCircle.getPosition().y <= y - 2 * size))
        {
            MainCircle.move(0, 10);
        }*/

        if (MainCircle.getPosition().x < 0)
        {
            MainCircle.setPosition(0, MainCircle.getPosition().y);
        }
        if (MainCircle.getPosition().x > x - (size * 2))
        {
            MainCircle.setPosition(x - (size * 2), MainCircle.getPosition().y);
        }
        if (MainCircle.getPosition().y < 0)
        {
            MainCircle.setPosition(MainCircle.getPosition().x, 0);
        }
        if (MainCircle.getPosition().y > y - (2 * size))
        {
            MainCircle.setPosition(MainCircle.getPosition().x, y - (size * 2));
        }

        for (int i = 0; i < 5; i++) // движение шипов
        {
            trap[i].move(mas_moves[i][0], mas_moves[i][1]);

            if (trap[i].get_pos_x() <= 0)
            {
                if (mas_moves[i][0] == -1)
                {
                    mas_moves[i][0] = 1;
                }
            }
            if (trap[i].get_pos_x() >= x - 10 * 2)
            {
                if (mas_moves[i][0] == 1)
                {
                    mas_moves[i][0] = -1;
                }
            }
            if (trap[i].get_pos_y() <= 0)
            {
                if (mas_moves[i][1] == -1)
                {
                    mas_moves[i][1] = 1;
                }
            }
            if (trap[i].get_pos_y() >= y - 10 * 2)
            {
                if (mas_moves[i][1] == 1)
                {
                    mas_moves[i][1] = -1;
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            int x1 = MainCircle.getPosition().x;
            int y1 = MainCircle.getPosition().y;
            int x2 = mas_pos1[i][0];
            int y2 = mas_pos1[i][1];
            int r1 = size + 5;
            int r2 = 10;
            if ((sqrt(pow(x2 + r2 - x1 - r1, 2)) + sqrt(pow(y2 + r2 - y1 - r1, 2))) < r1 + r2)
            {
                size += size_up;
                if (FlagStop == false)
                {
                    string score = "Score:" + to_string(size);
                    end.setString(score);
                }
                MainCircle.setRadius(size);
                MainCircle.setPosition(x1 - size_up, y1 - size_up);
                circle[i].change_position();
            }
        }

        for (int i = 0; i < 5; i++)
        {
            int x1 = MainCircle.getPosition().x;
            int y1 = MainCircle.getPosition().y;
            int x2 = mas_pos2[i][0];
            int y2 = mas_pos2[i][1];
            int r1 = size;
            int r2 = 10;

            if (((sqrt(pow(x2 + r2 - x1 - r1, 2)) + sqrt(pow(y2 + r2 - y1 - r1, 2))) < r1 + r2) && end.getFillColor() != sf::Color::Green)
            {
                FlagStop = true;
                end.setFillColor(sf::Color::Red);
                end.setPosition(x / 3, y / 2 - 100);
                end.setCharacterSize(100);
                end.setString("You lost!");
                MainCircle.setRadius(0);
                trap[i].set_radius(0);
                trap[i].set_pos(0, 0);
            }
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        if (FlagStop == false)
        {
            window.draw(MainCircle);
            for (int i = 0; i < 10; i++)
            {
                window.draw(circle[i].m_circle);
            }
            for (int i = 0; i < 5; i++)
            {
                window.draw(trap[i].m_circle);
            }
            window.draw(end);
        }
        else
        {
            window.draw(end);
        }
        
        window.display();
    }

    return 0;
}