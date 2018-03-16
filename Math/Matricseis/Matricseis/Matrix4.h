#pragma once

#include "Vector3.h"

class Matrix4
{
private:
	float matrix[4][4];
public:
	Matrix4();
	~Matrix4();

	float GetElement(int matrixRow, int matrixColumn) const;
	void SetElement(int matrixRow, int matrixColumn, float newValue);
	static Matrix4& CreateIdentityMatrix(Matrix4& identityMatrix);

	static void TranslateVector3(int translateX, int translateY, int translateZ, Vector3& vertex);
	static void ScaleVector3(int scale, Vector3& vertex);
	static void SkewVector3(int scaleX, int scaleY, int scaleZ, Vector3& vertex);
	static void RotateAroundZ(int degrees, Vector3& vertex);
	static void RotateAroundY(int degrees, Vector3& vertex);
	static void RotateAroundX(int degrees, Vector3& vertex);
};

