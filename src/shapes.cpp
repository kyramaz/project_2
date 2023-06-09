#include <SFML/Graphics.hpp>
#include <iostream>
#include <shapes.hpp>
using namespace std;

namespace sh {
	int get_random_number(int min, int max)
	{
		int num = min + rand() % (max - min + 1);
		return num;
	}
	void FIX(sf::CircleShape& circle, int& radius, int& x, int& y)
	{
		if (circle.getPosition().x < 0)
		{
			circle.setPosition(0, circle.getPosition().y);
		}
		if (circle.getPosition().x > x - (radius * 2))
		{
			circle.setPosition(x - (radius * 2), circle.getPosition().y);
		}
		if (circle.getPosition().y < 0)
		{
			circle.setPosition(circle.getPosition().x, 0);
		}
		if (circle.getPosition().y > y - (2 * radius))
		{
			circle.setPosition(circle.getPosition().x, y - (radius * 2));
		}
	}

	Circles::Circles()
	{

	}

	Circles::~Circles()
	{

	}

	void Circles::fix()
	{
		if (m_circle.getPosition().x < 0)
		{
			m_circle.setPosition(0, m_circle.getPosition().y);
		}
		if (m_circle.getPosition().x > win_x - (m_radius * 2))
		{
			m_circle.setPosition(win_x - (m_radius * 2), m_circle.getPosition().y);
		}
		if (m_circle.getPosition().y < 0)
		{
			m_circle.setPosition(m_circle.getPosition().x, 0);
		}
		if (m_circle.getPosition().y > win_y - (2 * m_radius))
		{
			m_circle.setPosition(m_circle.getPosition().x, win_y - (m_radius * 2));
		}
	}

	void Circles::set_circle(sf::CircleShape &circle)
	{
		m_circle = circle;
	}
	void Circles::set_radius(int size)
	{
		m_radius = size;
		m_circle.setRadius(size);
	}
	void Circles::set_color(sf::Color(color))
	{
		m_circle.setFillColor(color);
	}

	void Circles::change_position()
	{
		m_x = get_random_number(0, win_x);
		m_y = get_random_number(0, win_y);
		m_circle.setPosition(m_x, m_y);
	}

	int Circles::get_pos_x()
	{
		return m_circle.getPosition().x;
	}
	int Circles::get_pos_y()
	{
		return m_circle.getPosition().y;
	}

	int Circles::get_radius()
	{
		return m_circle.getRadius();
	}


	Traps::Traps()
	{

	}
	Traps::~Traps()
	{

	}

	void Traps::set_circle(sf::CircleShape &circle)
	{
		m_circle = circle;
	}
	void Traps::set_radius(int size)
	{
		m_radius = size;
		m_circle.setRadius(size);
	}
	void Traps::set_color(sf::Color(color))
	{
		m_circle.setFillColor(color);
	}
	void Traps::set_pos(int x, int y)
	{
		m_circle.setPosition(x, y);
	}
	int Traps::get_pos_x()
	{
		return m_circle.getPosition().x;
	}
	int Traps::get_pos_y()
	{
		return m_circle.getPosition().y;
	}
	void Traps::move(int x, int y)
	{
		m_circle.move(x, y);
	}
	void Traps::change_position()
	{
		m_x = get_random_number(0, win_x);
		m_y = get_random_number(0, win_y);
		m_circle.setPosition(m_x, m_y);
	}
}