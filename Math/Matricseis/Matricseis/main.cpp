#include <iostream>
#include "Matrix3.h"
#include "Vector2.h"

#define PI 3.14159265

void DisplayMatrix(Matrix3 * matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix->GetElement(i, j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}
void GenerateMatrix(Matrix3 * matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix->SetElement(i, j, (i + j));
		}
	}
	matrix->SetElement(0, 0, 1);
}


int main()
{
	
	Matrix3 testMatrix, secondMatrix;

	GenerateMatrix(&testMatrix);
	GenerateMatrix(&secondMatrix);

	// DisplayMatrix(&testMatrix);
	// DisplayMatrix(&secondMatrix);
	
	// Testing Equal
	/*if (Matrix::isEqual(testMatrix, secondMatrix))
	{
		std::cout << "They are equal!";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "They are not equal!";
		std::cout << std::endl;
	}
	*/

	// Testing matrix functionalities (add, subtract, multiply, transpose
	/*
	Matrix3 addedMatricies = Matrix3::AddMatricies(testMatrix, secondMatrix);

	DisplayMatrix(&addedMatricies);

	Matrix3 subtractedMatrix = Matrix3::SubtractMatricies(testMatrix, secondMatrix);
	DisplayMatrix(&subtractedMatrix);

	testMatrix = Matrix3::MultiplyByScalar(3, testMatrix);
	DisplayMatrix(&testMatrix);

	testMatrix = Matrix3::MultiplyByMatrix(testMatrix, secondMatrix);
	DisplayMatrix(&testMatrix);

	secondMatrix = Matrix3::TransposeMatrix(secondMatrix);
	DisplayMatrix(&testMatrix);
	*/

	//Testing Clamp
	/*
	int row = 4;
	int column = 3;

	Matrix::Clamp(row, column);

	std::cout << row << " " << column;
	*/

	// Testing new inverse
	/*
	Matrix3 inverseMatrix;

	if (Matrix3::GetInverse(testMatrix, inverseMatrix))
	{
		std::cout << "The inverse matrix elements are: " << std::endl;
		DisplayMatrix(&inverseMatrix);
	}
	else
	{
		std::cout << "Inverse is not possible " << std::endl;
	}
	*/

	/*
	Matrix CofactorMatrix;

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			CofactorMatrix.SetElement(row, column, Matrix::CalculateCofactor(testMatrix, row, column));
		}
	}

	float determinant = Matrix::CalculateDeterminant(testMatrix);
	
	std::cout << determinant << std::endl;

	Matrix transposeMatrix = Matrix::TransposeMatrix(CofactorMatrix);



	DisplayMatrix(&transposeMatrix);
	
	*/

	Vector2 rotationVector(1, 0);
	Matrix3::Rotate2D(90, rotationVector);

	rotationVector.DisplayVector2();

	system("pause");

	// Testing vector (Translate, Scale, Skew)
	/*
	Vector2 testVertex(1, 1);
	Matrix3::TranslateVector2(2, 4, testVertex);

	testVertex.DisplayVector2();

	system("pause");

	Vector2 skewTest(3, 5);

	Matrix3::ScaleVector2(2, testVertex);
	testVertex.DisplayVector2();

	std::cout << std::endl;

	Matrix3::SkewVector2(2, 3, skewTest);
	skewTest.DisplayVector2();

	system("pause");
	*/

	return 0;
}