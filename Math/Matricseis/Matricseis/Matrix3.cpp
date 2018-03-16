#include <math.h>
#include <iostream>

#include "Matrix3.h"
#include "Vector2.h"

#define PI 3.14159265


Matrix3::Matrix3()
{
}


Matrix3::~Matrix3()
{
}

float Matrix3::GetElement(int matrixRow, int matrixColumn) const
{
	return matrix[matrixRow][matrixColumn];
}

void Matrix3::SetElement(int matrixRow, int matrixColumn, float newValue) 
{
	matrix[matrixRow][matrixColumn] = newValue;
}



Matrix3 & Matrix3::CreateIdentityMatrix(Matrix3& identityMatrix)
{
	/*
		1 0 0
		0 1 0
		0 0 1
	*/

	// Set elements of the matrix either 1 or 0
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
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

Matrix3 & Matrix3::CreateZeroMatrix(Matrix3& zeroMatrix)
{
	/*
	0 0 0
	0 0 0
	0 0 0
	*/

	// Set elements of the matrix to 0
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			zeroMatrix.SetElement(row, column, 0);
		}
	}

	return zeroMatrix;

}

bool Matrix3::isEqual(const Matrix3 & matrixA, const Matrix3 & matrixB)
{
	// check every corresponding element of matrixA and matrixB
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			// if any of them are not equal, return false
			if (matrixA.GetElement(row, column) != matrixB.GetElement(row, column))
			{
				return false;
			}
			
		}
	}
	return true;
}

Matrix3 &Matrix3::AddMatricies(const Matrix3 & matrixA, const Matrix3 & matrixB)
{
	Matrix3 addedMatrix;
	int addedValue;

	// Iterate through the elements of the new matrix
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			addedValue = matrixA.GetElement(row, column) + matrixB.GetElement(row, column);

			// Add corresponding matrixA element to corresponding matrixB element
			addedMatrix.SetElement(row, column, addedValue);
		}
	}

	return addedMatrix;

}

Matrix3 &Matrix3::SubtractMatricies(const Matrix3 & matrixA, const Matrix3 & matrixB)
{
	Matrix3 subtractedMatrix;
	int subtractedValue;

	// Iterate through the elements of the new matrix
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			subtractedValue = matrixA.GetElement(row, column) - matrixB.GetElement(row, column);

			// Subtract corresponding matrixA element to corresponding matrixB element
			subtractedMatrix.SetElement(row, column, subtractedValue);
		}
	}

	return subtractedMatrix;
}

Matrix3 & Matrix3::MultiplyByScalar(float scalarNumber, const Matrix3 & matrix)
{
	// TODO: insert return statement here
	Matrix3 multipliedMatrix;

	// Iterate through the elements of the new matrix
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			// multiply elements with the scalar number
			multipliedMatrix.SetElement(row, column, (scalarNumber * matrix.GetElement(row, column)));
		}
	}
	return multipliedMatrix;
}



Matrix3 & Matrix3::MultiplyByMatrix(const Matrix3 & matrixA, const Matrix3 & matrixB)
{
	// TODO: insert return statement here

	/*
		|a b|	|e	f|	=	|ae + bg	af + bh|	A	[0][0]	[0][1]			B	[0][0]	[0][1]		NEW		|A[0][0] * B[0][0] + A[0][1] * B[1][0]	A[0][0] * B[0][1] + A[0][1] * B[1][1]|
		|c d|	|g	h|		|ce + dg	cf + dh|		[1][0]	[1][1]				[1][0]	[1][1]				|A[1][0] * B[0][0] + A[1][1] * B[1][0]	A[1][0] * B[0][1] + A[1][1] * B[1][1]|
	*/
	Matrix3 multipliedMatrix;
	int multipliedElementValue;

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			// calculate the multiplied matrix Value
			multipliedElementValue	= (matrixA.GetElement(row, 0) * matrixB.GetElement(0, column))
									+ (matrixA.GetElement(row, 1) * matrixB.GetElement(1, column))
									+ (matrixA.GetElement(row, 2) * matrixB.GetElement(2, column));

			multipliedMatrix.SetElement(row, column, multipliedElementValue);
		}
	}

	return multipliedMatrix;

}

Matrix3 & Matrix3::TransposeMatrix(const Matrix3& matrix)
{
	// TODO: insert return statement here
	/*
		a b c		a e h
		e f g	->	b f i
		h i j		c g j
	*/
	Matrix3 transposedMatrix;
	int transposedValue;

	// Iterate through the elements of the new matrix
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			transposedValue = matrix.GetElement(column, row);

			transposedMatrix.SetElement(row, column, transposedValue);
		}
	}

	return transposedMatrix;

}

float Matrix3::CalculateDeterminant(const Matrix3& matrix)
{
	float determinant;

	determinant =	matrix.GetElement(0, 0)		*	(((matrix.GetElement(1, 1) * matrix.GetElement(2, 2)) - (matrix.GetElement(1, 2) * matrix.GetElement(2, 1))))
				+	(-1* matrix.GetElement(0, 1)) *	(((matrix.GetElement(1, 0) * matrix.GetElement(2, 2)) - (matrix.GetElement(2, 0) * matrix.GetElement(1, 2))))
				+	matrix.GetElement(0, 2)		*	(((matrix.GetElement(1, 0) * matrix.GetElement(2, 1)) - (matrix.GetElement(1, 1) * matrix.GetElement(2, 0))));

	return determinant;
}

bool Matrix3::GetInverse(const Matrix3 & matrix, Matrix3 & inverseMatrix)
{
	if (matrix.CalculateDeterminant(matrix) != 0)
	{
		Matrix3 CofactorMatrix;

		// Calculate Cofactor matrix elements
		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				CofactorMatrix.SetElement(row, column, CalculateCofactor(matrix, row, column));
			}
		}
		

		TransposeMatrix(CofactorMatrix);

		float determinant = CalculateDeterminant(matrix);

		// calculate each element of the inverse matrix
		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				inverseMatrix.SetElement(row, column, (CofactorMatrix.GetElement(row, column) / determinant));
			}
		}

		return true;
	}
	return false;
}

float Matrix3::CalculateCofactor(const Matrix3 & matrix, int matrixRow, int matrixColumn)
{
	int cofactor;

	cofactor =			matrix.GetElement(Clamp(matrixRow + 1), Clamp(matrixColumn + 1)) * matrix.GetElement(Clamp(matrixRow + 2), Clamp(matrixColumn + 2))
				-		matrix.GetElement(Clamp(matrixRow + 2), Clamp(matrixColumn + 1)) * matrix.GetElement(Clamp(matrixRow + 1), Clamp(matrixColumn + 2));
	
	return cofactor;
}

int Matrix3::Clamp(int position)
{
	/*
	1:					2:								3:
		a						a									a
			b	c			b		c	(clamp)				b	c		(clamp)	(clamp)
			e	g			e		g	(clamp)				e	g		(clamp)	(clamp)

			SAME GOES VERTICALLY

	*/

	// If position goes through the end of the array, set it to the beginning
	if (position == 3)
		position = 0;
	if (position == 4)
		position = 1;

	return position;


}



// Section 2 - Linear Transformations (2D transforms)

void Matrix3::TranslateVector2(int translateX, int translateY, Vector2& vertex)
{
	/*
		1 0 0						1 0 translateX
		0 1 0				-->		0 1 translateY   
		0 0 1 - NOT USED			0 0 1

	*/



	Matrix3 translatedMatrix = CreateIdentityMatrix(translatedMatrix);

	translatedMatrix.SetElement(0, 2, translateX);
	translatedMatrix.SetElement(1, 2, translateY);

	// Do the translation
	vertex.SetX(translatedMatrix.GetElement(0, 2) + vertex.GetX());
	vertex.SetY(translatedMatrix.GetElement(1, 2) + vertex.GetY());

	return;
}

void Matrix3::ScaleVector2(int scale, Vector2 & vertex)
{
	SkewVector2(scale, scale, vertex);

	return;
}

void Matrix3::SkewVector2(int scaleX, int scaleY, Vector2 & vertex)
{
	// Prepare for scaling
	/*
	1 0 0						scaleX	0		0
	0 1 0				-->		0		scaleY	0
	0 0 1 - NOT USED			0		0		1

	*/

	Matrix3 scaledMatrix = CreateIdentityMatrix(scaledMatrix);

	scaledMatrix.SetElement(0, 0, scaleX);
	scaledMatrix.SetElement(1, 1, scaleY);

	// Do the scaling
	vertex.SetX(vertex.GetX() * scaledMatrix.GetElement(0, 0));
	vertex.SetY(vertex.GetY() * scaledMatrix.GetElement(1, 1));

	return;
}

void Matrix3::Rotate2D(int degrees, Vector2 & vertex)
{
	/*
		cos	 sin
		-sin cos
	*/

	int tempX = vertex.GetX();
	int tempY = vertex.GetY();
	
	// TODO fix functions
	vertex.SetX(tempX * cos(degrees * PI / 180) - tempY * sin(degrees * PI / 180));
	vertex.SetY(tempX * sin(degrees * PI / 180) + tempY * cos(degrees * PI / 180));

}



bool Matrix3::TestHarness()
{
	return false;
}
