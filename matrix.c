#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
matrix* mat_con(double* arr, int r, int c)
{
	int i,j;
	matrix* mat;
	if (r <= 0 || c <= 0)
	{
		printf("Error, attempt to construct a matrix with nonpositive size %d and %d\n", r, c);
		return NULL;
	}
	mat = malloc(sizeof(matrix));
	mat->r = r;
	mat->c = c;
	mat->mat = malloc(r * c * sizeof(double));
	memcpy(mat->mat, arr, r * c * sizeof(double));
	return mat;
}

// If error checking isn't important this could be turned into a macro
double mat_at(matrix* mat, int i, int j)
{
	if (i < 0 || j < 0 || i >= mat->r || j >= mat->c)
	{
		printf("Error, indices: %d and %d are out of matrix bounds %d and %d \n", i, j, mat->r, mat->c);
		return 0;
	}
	return mat->mat[i * mat->c + j];
}

matrix* mat_mul(matrix* a, matrix* b)
{
	matrix* mat;
	int i,j,k;
	if (a->c != b->r)
	{
		printf("Error, attempt to multiply matrices of incompatible sizes %d and %d\n", a->c, b->r);
		return NULL;
	}
	mat = malloc(sizeof(matrix));
	mat->r = a->r;
	mat->c = b->c;
	mat->mat = malloc(mat->r * mat->c * sizeof(double));
	for (i = 0; i < a->r; i++)
	{
		for (j = 0; j < b->c; j++)
		{
			for (k = 0; k < a->c; k++)
			{
				mat->mat[i * mat->c + j] += mat_at(a, i, k)*mat_at(b, k, j);
			}
		}
	}
	return mat;
}
