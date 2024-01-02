
typedef struct matrix {
	double* mat;
	int r;
	int c;
} matrix;

matrix* mat_con(double* arr, int r, int c);
double mat_at(matrix* mat, int i, int j);
matrix* mat_mul(matrix* a, matrix* b);
matrix* mat_inv(matrix* mat);
