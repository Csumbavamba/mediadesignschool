#pragma once
class Matrix
{
private:
	float matrix[3][3];
public:
	Matrix();
	~Matrix();

	float GetElement(int matrixRow, int matrixColumn) const;
	void SetElement(int matrixRow, int matrixColumn, float newValue);
	
	static Matrix& CreateIdentityMatrix(Matrix& identityMatrix);
	static Matrix& CreateZeroMatrix(Matrix& zeroMatrix);

	static bool isEqual(const Matrix& matrixA, const Matrix& matrixB);
	static Matrix& AddMatricies(const Matrix& matrixA, const Matrix& matrixB);
	static Matrix& SubtractMatricies(const Matrix& matrixA, const Matrix& matrixB);

	static Matrix& MultiplyByScalar(float scalarNumber, const Matrix& matrix);
	static Matrix& MultiplyByMatrix(const Matrix& matrixA, const Matrix& matrixB);

	static Matrix& TransposeMatrix(const Matrix& matrix);
	static float CalculateDeterminant(const Matrix& matrix);
	static bool GetInverse(const Matrix& matrix, Matrix& inverseMatrix);
	static bool TestHarness();


};

