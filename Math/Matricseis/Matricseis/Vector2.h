#pragma once
class Vector2
{
private:
	double x;
	double y;
	const int z = 1;
public:
	Vector2();
	Vector2(double x, double y);
	~Vector2();

	int GetX();
	int GetY();

	void SetX(double value);
	void SetY(double value);

	void DisplayVector2();
};

