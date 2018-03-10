#include <iostream>

#include "Vector2.h"



Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(double x, double y)
{
	this->x = x;
	this->y = y;
}


Vector2::~Vector2()
{
}

int Vector2::GetX()
{
	return x;
}

int Vector2::GetY()
{
	return y;
}

void Vector2::SetX(double value)
{
	x = value;
}

void Vector2::SetY(double value)
{
	y = value;
}

void Vector2::DisplayVector2()
{
	std::cout << "|" << x << "|" << std::endl;
	std::cout << "|" << y << "|" << std::endl;
}
