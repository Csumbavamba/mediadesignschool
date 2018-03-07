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


	int wait;
	std::cin >> wait;

	return 0;
}