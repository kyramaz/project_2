#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace sh
{
	int get_random_number(int min, int max);

	void FIX(sf::CircleShape& circle, int& radius, int& x, int& y);

	class Circles
	{
	private:
		int m_radius;
		int m_x;
		int m_y;
		int win_x = 1280;
		int win_y = 720;

	public:
		sf::CircleShape m_circle;
		Circles();
		~Circles();
		void fix();

		void set_circle(sf::CircleShape &circle);
		void set_radius(int size);
		void set_color(sf::Color(color));

		void change_position();

		int get_pos_x();
		int get_pos_y();

		int get_radius();

	};

	class Traps
	{
	private:
		int m_radius{};
		int m_x{};
		int m_y{};
		int win_x = 1280;
		int win_y = 720;

	public:
		sf::CircleShape m_circle;
		Traps();
		~Traps();

		void set_circle(sf::CircleShape &circle);
		void set_radius(int size);
		void set_color(sf::Color(color));
		void set_pos(int x, int y);
		int get_pos_x();
		int get_pos_y();
		void move(int x, int y);
		void change_position();
	};
}