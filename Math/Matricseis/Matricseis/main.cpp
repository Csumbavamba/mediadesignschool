#include "Matrix.h"
#include <iostream>


void DisplayMatrix(Matrix * matrix)
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


int main()
{
	
	Matrix testMatrix, secondMatrix;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			testMatrix.SetElement(i, j, (i+j));
			secondMatrix.SetElement(i, j, (2* i + j));
		}
	}
	testMatrix.SetElement(0, 0, 1);
	secondMatrix.SetElement(0, 0, 1);

	DisplayMatrix(&testMatrix);
	DisplayMatrix(&secondMatrix);
	

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

	// Matrix addedMatricies = Matrix::AddMatricies(testMatrix, secondMatrix);

	// DisplayMatrix(&addedMatricies);

	// Matrix subtractedMatrix = Matrix::SubtractMatricies(testMatrix, secondMatrix);
	// DisplayMatrix(&subtractedMatrix);

	// testMatrix = Matrix::MultiplyByScalar(3, testMatrix);
	// DisplayMatrix(&testMatrix);

	// testMatrix = Matrix::MultiplyByMatrix(testMatrix, secondMatrix);
	// DisplayMatrix(&testMatrix);

	// secondMatrix = Matrix::TransposeMatrix(secondMatrix);
	// DisplayMatrix(&secondMatrix);

	/*
	testMatrix = Matrix::CreateZeroMatrix(testMatrix);

	Matrix inverseMatrix;

	if (Matrix::GetInverse(testMatrix, inverseMatrix))
	{
		std::cout << "The inverse matrix elements are: " << std::endl;
		DisplayMatrix(&inverseMatrix);
	}
	else
	{
		std::cout << "Inverse is not possible " << std::endl;
	}
	*/

	// Testing Clamp
	/*
	int row = 4;
	int column = 3;

	Matrix::Clamp(row, column);

	std::cout << row << " " << column;
	*/

	// Testing new inverse
	
	Matrix inverseMatrix;

	if (Matrix::GetInverse(testMatrix, inverseMatrix))
	{
		std::cout << "The inverse matrix elements are: " << std::endl;
		DisplayMatrix(&inverseMatrix);
	}
	else
	{
		std::cout << "Inverse is not possible " << std::endl;
	}
	

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
	int wait;
	std::cin >> wait;

	return 0;
}