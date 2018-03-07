#include "Matrix.h"



Matrix::Matrix()
{
}


Matrix::~Matrix()
{
}

float Matrix::GetElement(int matrixRow, int matrixColumn) const
{
	return matrix[matrixRow][matrixColumn];
}

void Matrix::SetElement(int matrixRow, int matrixColumn, float newValue) 
{
	matrix[matrixRow][matrixColumn] = newValue;
}



Matrix & Matrix::CreateIdentityMatrix(Matrix& identityMatrix)
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

Matrix & Matrix::CreateZeroMatrix(Matrix& zeroMatrix)
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

bool Matrix::isEqual(const Matrix & matrixA, const Matrix & matrixB)
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

Matrix &Matrix::AddMatricies(const Matrix & matrixA, const Matrix & matrixB)
{
	Matrix addedMatrix;
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

Matrix &Matrix::SubtractMatricies(const Matrix & matrixA, const Matrix & matrixB)
{
	Matrix subtractedMatrix;
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

Matrix & Matrix::MultiplyByScalar(float scalarNumber, const Matrix & matrix)
{
	// TODO: insert return statement here
	Matrix multipliedMatrix;

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



Matrix & Matrix::MultiplyByMatrix(const Matrix & matrixA, const Matrix & matrixB)
{
	// TODO: insert return statement here

	/*
		|a b|	|e	f|	=	|ae + bg	af + bh|	A	[0][0]	[0][1]			B	[0][0]	[0][1]		NEW		|A[0][0] * B[0][0] + A[0][1] * B[1][0]	A[0][0] * B[0][1] + A[0][1] * B[1][1]|
		|c d|	|g	h|		|ce + dg	cf + dh|		[1][0]	[1][1]				[1][0]	[1][1]				|A[1][0] * B[0][0] + A[1][1] * B[1][0]	A[1][0] * B[0][1] + A[1][1] * B[1][1]|
	*/
	Matrix multipliedMatrix;
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

Matrix & Matrix::TransposeMatrix(const Matrix& matrix)
{
	// TODO: insert return statement here
	/*
		a b c		a e h
		e f g	->	b f i
		h i j		c g j
	*/
	Matrix transposedMatrix;
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

float Matrix::CalculateDeterminant(const Matrix& matrix)
{
	float determinant;

	determinant =	(matrix.GetElement(0, 0) * ((matrix.GetElement(1, 1) * matrix.GetElement(2, 2)) - (matrix.GetElement(2, 2) * matrix.GetElement(3, 2))))
				-	(matrix.GetElement(0, 1) * ((matrix.GetElement(1, 0) * matrix.GetElement(3, 3)) - (matrix.GetElement(2, 2) * matrix.GetElement(0, 2))))
				+	(matrix.GetElement(0, 2) * ((matrix.GetElement(1, 0) * matrix.GetElement(2, 1)) - (matrix.GetElement(1, 1) * matrix.GetElement(2, 0))));

	return determinant;
}

bool Matrix::GetInverse(const Matrix & matrix, Matrix& inverseMatrix)
{
	/*
		|1|	 2	 3
		 4	(5)	(6)
		 7	(8)	(9)

		 if (row == 0 && column == 1)
		 GetElement (1,0 2,2 1,2 2,0)	
	*/

	if (matrix.CalculateDeterminant(matrix) != 0)
	{
		Matrix CofactorMatrix;

		// calculate the cofactor values of the matrix
		CofactorMatrix.SetElement(0, 0,		(matrix.GetElement(1, 1) * matrix.GetElement(2, 2)) - (matrix.GetElement(1, 2) * matrix.GetElement(2, 1)));
		CofactorMatrix.SetElement(0, 1,	(-1*(matrix.GetElement(1, 0) * matrix.GetElement(2, 2)) - (matrix.GetElement(2, 0) * matrix.GetElement(1, 2))));
		CofactorMatrix.SetElement(0, 2,		(matrix.GetElement(1, 0) * matrix.GetElement(2, 1)) - (matrix.GetElement(2, 0) * matrix.GetElement(1, 1)));
		CofactorMatrix.SetElement(1, 0, (-1*(matrix.GetElement(0, 1) * matrix.GetElement(2, 2)) - (matrix.GetElement(0, 2) * matrix.GetElement(2, 1))));
		CofactorMatrix.SetElement(1, 1,		(matrix.GetElement(0, 0) * matrix.GetElement(2, 2)) - (matrix.GetElement(0, 2) * matrix.GetElement(2, 0)));
		CofactorMatrix.SetElement(1, 2, (-1*(matrix.GetElement(0, 0) * matrix.GetElement(2, 1)) - (matrix.GetElement(0, 1) * matrix.GetElement(2, 0))));
		CofactorMatrix.SetElement(2, 0,		(matrix.GetElement(0, 1) * matrix.GetElement(1, 2)) - (matrix.GetElement(1, 1) * matrix.GetElement(0, 2)));
		CofactorMatrix.SetElement(2, 1, (-1*(matrix.GetElement(0, 0) * matrix.GetElement(1, 2)) - (matrix.GetElement(1, 0) * matrix.GetElement(1, 2))));
		CofactorMatrix.SetElement(2, 2,		(matrix.GetElement(0, 0) * matrix.GetElement(1, 1)) - (matrix.GetElement(1, 0) * matrix.GetElement(0, 1)));

		Matrix transposedMatrix = TransposeMatrix(CofactorMatrix);
		float determinant = CalculateDeterminant(matrix);

		// calculate each element of the inverse matrix
		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				inverseMatrix.SetElement(row, column, (transposedMatrix.GetElement(row, column) / determinant));
			}
		}

		return true;
	}
	return false;

}




bool Matrix::TestHarness()
{
	return false;
}
