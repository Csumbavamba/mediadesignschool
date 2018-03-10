#pragma once

#include "Vector2.h"

class Matrix3
{
private:
	float matrix[3][3];
public:
	Matrix3();
	~Matrix3();

	float GetElement(int matrixRow, int matrixColumn) const;
	void SetElement(int matrixRow, int matrixColumn, float newValue);
	
	static Matrix3& CreateIdentityMatrix(Matrix3& identityMatrix);
	static Matrix3& CreateZeroMatrix(Matrix3& zeroMatrix);

	static bool isEqual(const Matrix3& matrixA, const Matrix3& matrixB);
	static Matrix3& AddMatricies(const Matrix3& matrixA, const Matrix3& matrixB);
	static Matrix3& SubtractMatricies(const Matrix3& matrixA, const Matrix3& matrixB);

	static Matrix3& MultiplyByScalar(float scalarNumber, const Matrix3& matrix);
	static Matrix3& MultiplyByMatrix(const Matrix3& matrixA, const Matrix3& matrixB);

	static Matrix3& TransposeMatrix(const Matrix3& matrix);
	static float CalculateDeterminant(const Matrix3& matrix);
	static bool GetInverse(const Matrix3& matrix, Matrix3& inverseMatrix);
	static float CalculateCofactor(const Matrix3& matrix, int matrixRow, int matrixColumn);
	static int Clamp(int position);

	// 2D transforms
	static void TranslateVector2(int translateX, int translateY, Vector2& vertex);
	static void ScaleVector2(int scale, Vector2& vertex);
	static void SkewVector2(int scaleX, int scaleY, Vector2& vertex);
	static void Rotate2D(int degrees, Vector2& vertex);


	static bool TestHarness();


};

