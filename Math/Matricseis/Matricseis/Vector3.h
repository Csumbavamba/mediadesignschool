#pragma once
class Vector3
{
private:
	double x;
	double y;
	double z;
	const double w = 1;

public:
	Vector3();
	Vector3(double x, double y, double z);
	~Vector3();

	int GetX();
	int GetY();
	int GetZ();

	void SetX(double value);
	void SetY(double value);
	void SetZ(double value);

	void DisplayVector3();
};

