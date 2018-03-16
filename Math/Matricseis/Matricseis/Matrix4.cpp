#include <math.h>

#include "Vector3.h"
#include "Matrix4.h"

#define PI 3.14159265

Matrix4::Matrix4()
{
}


Matrix4::~Matrix4()
{
}

float Matrix4::GetElement(int matrixRow, int matrixColumn) const
{
	return matrix[matrixRow][matrixColumn];
}

void Matrix4::SetElement(int matrixRow, int matrixColumn, float newValue)
{
	matrix[matrixRow][matrixColumn] = newValue;
}

Matrix4 & Matrix4::CreateIdentityMatrix(Matrix4 & identityMatrix)
{
	/*
	1 0 0 0
	0 1 0 0
	0 0 1 0
	0 0 0 1
	*/

	// Set elements of the matrix either 1 or 0
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			if (row == column)
			{
				identityMatrix.SetElement(row, column, 1);
			}
			else
			{
				identityMatrix.SetElement(row, column, 0);
			}
		}
	}

	return identityMatrix;
}

void Matrix4::TranslateVector3(int translateX, int translateY, int translateZ, Vector3 & vertex)
{
	/*
	1 0 0 0						1 0 0 translateX
	0 1 0 0				-->		0 1 0 translateY
	0 0 1 0						0 0 1 translateZ
	0 0 0 1 - NOT USED			0 0 0 1

	*/



	Matrix4 translatedMatrix = CreateIdentityMatrix(translatedMatrix);

	translatedMatrix.SetElement(0, 3, translateX);
	translatedMatrix.SetElement(1, 3, translateY);
	translatedMatrix.SetElement(2, 3, translateZ);

	// Do the translation
	vertex.SetX(translatedMatrix.GetElement(0, 3) + vertex.GetX());
	vertex.SetY(translatedMatrix.GetElement(1, 3) + vertex.GetY());
	vertex.SetZ(translatedMatrix.GetElement(2, 3) + vertex.GetZ());

	return;
}

void Matrix4::ScaleVector3(int scale, Vector3 & vertex)
{
	SkewVector3(scale, scale, scale, vertex);

	return;
}

void Matrix4::SkewVector3(int scaleX, int scaleY, int scaleZ, Vector3 & vertex)
{
	// Prepare for scaling
	/*
	1 0 0 0						scaleX	0		0		0
	0 1 0 0				-->		0		scaleY	0		0
	0 0 1 0 					0		0		scaleZ	0
	0 0 0 1 - NOT USED			0		0		0		1

	*/

	Matrix4 scaledMatrix = CreateIdentityMatrix(scaledMatrix);

	scaledMatrix.SetElement(0, 0, scaleX);
	scaledMatrix.SetElement(1, 1, scaleY);
	scaledMatrix.SetElement(2, 2, scaleZ);

	// Do the scaling
	vertex.SetX(vertex.GetX() * scaledMatrix.GetElement(0, 0));
	vertex.SetY(vertex.GetY() * scaledMatrix.GetElement(1, 1));
	vertex.SetZ(vertex.GetZ() * scaledMatrix.GetElement(2, 2));

	return;
}

void Matrix4::RotateAroundZ(int degrees, Vector3 & vertex)
{

	/*
		cos		-sin		 0
		sin		cos		 0 
		 0		 0		 1
	*/

	// TODO make function that works

	int tempX = vertex.GetX();
	int tempY = vertex.GetY();



	// TODO fix functions
	vertex.SetX(tempX * cos(degrees * PI / 180) - tempY * sin(degrees * PI / 180));
	vertex.SetY(tempX * sin(degrees * PI / 180) + tempY * cos(degrees * PI / 180));
}

void Matrix4::RotateAroundY(int degrees, Vector3 & vertex)
{
	/*
	cos		0		sin
	0		1		0
	-sin		0	cos
	*/

	int tempX = vertex.GetX();
	int tempZ = vertex.GetZ();

	vertex.SetX(tempX * cos(degrees * PI / 180) + tempZ * sin(degrees * PI / 180));
	vertex.SetZ(tempZ * cos(degrees * PI / 180) - tempX * sin(degrees * PI / 180));
}

void Matrix4::RotateAroundX(int degrees, Vector3 & vertex)
{

	/*
		1		0		0
		0		cos		-sin	
		0		sin		cos	
	*/

	int tempY = vertex.GetY();
	int tempZ = vertex.GetZ();

	vertex.SetY(tempY * cos(degrees * PI / 180) - tempZ * sin(degrees * PI / 180));
	vertex.SetZ(tempY * sin(degrees * PI / 180) + tempZ * cos(degrees * PI / 180));
}
