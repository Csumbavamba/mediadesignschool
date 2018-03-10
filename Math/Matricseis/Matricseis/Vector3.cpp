#include <iostream>

#include "Vector3.h"



Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


Vector3::~Vector3()
{
}

int Vector3::GetX()
{
	return x;
}

int Vector3::GetY()
{
	return y;
}

int Vector3::GetZ()
{
	return z;
}

void Vector3::SetX(double value)
{
	x = value;
}

void Vector3::SetY(double value)
{
	y = value;
}

void Vector3::SetZ(double value)
{
	z = value;
}

void Vector3::DisplayVector3()
{
	std::cout << "|" << x << "|" << std::endl;
	std::cout << "|" << y << "|" << std::endl;
	std::cout << "|" << z << "|" << std::endl;
}
