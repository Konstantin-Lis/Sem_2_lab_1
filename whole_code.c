#include <stdlib.h>
#include <stdio.h>

#include <complex.h>

#undef complex
typedef float _Complex complex;

typedef enum {FLOAT, COMPLEX} Eltype;

typedef struct {
	Eltype eltype;
	int size;

	void **values;
} Matrix;



Matrix createMatrix(Eltype eltype, int size){
	Matrix matrix;

	matrix.eltype = eltype;
	matrix.size = size;

	int typesize;
	switch(eltype){
		case FLOAT:
			typesize = sizeof(float);
			break;
		case COMPLEX:
			typesize = sizeof(complex);
			break;
		default:
			break;
	}
	matrix.values = calloc(size, sizeof(void*));

	int i;
	for(i = 0; i < size; i++) matrix.values[i] = calloc(size, typesize);

	return matrix;
}


void destroyMatrix(Matrix matrix){
	if(matrix.size == 0) return;

	int i;
	for(i = 0; i < matrix.size; i++) free(matrix.values[i]);
	free(matrix.values);

	matrix.size = 0;
}


Matrix add(Matrix m1, Matrix m2){
	if (m1.eltype != m2.eltype || m1.size != m2.size) exit(1);

	int size = m1.size;
	Matrix result = createMatrix(m1.eltype, size);

	int i;
	int j;
	for(i = 0; i < size; i++) for(j = 0; j < size; j++){
		if(m1.eltype == FLOAT)
			((float**)result.values)[i][j] = ((float**)m1.values)[i][j] + ((float**)m2.values)[i][j];
		else if(m1.eltype == COMPLEX){
			((complex**)result.values)[i][j] = ((complex**)m1.values)[i][j] + ((complex**)m2.values)[i][j];
		}
	}

	return result;
}


Matrix scalMultiply(Matrix m, float num){
	int size = m.size;
	Matrix result = createMatrix(m.eltype, size);

	int i, j;
	for(i = 0; i < size; i++) for(j = 0; j < size; j++){
		if(m.eltype == FLOAT)
			((float**)result.values)[i][j] = ((float**)m.values)[i][j] * num;
		else if(m.eltype == COMPLEX)
			((complex**)result.values)[i][j] = ((complex**)m.values)[i][j] * num;
	}

	return result;
}



Matrix multiply(Matrix m1, Matrix m2){
	if (m1.eltype != m2.eltype || m1.size != m2.size) exit(1);

	int size = m1.size;
	Matrix result = createMatrix(m1.eltype, size);

	int i, j;
	for(i = 0; i < size; i++) for(j = 0; j < size; j++){
		if(m1.eltype == FLOAT){
			float sum = 0;
			int k;
			for(k = 0; k < size; k++){
				sum += ((float**)m1.values)[i][k] * ((float**)m2.values)[k][j];
			}

			((float**)result.values)[i][j] = sum;
		}
		else if(m1.eltype == COMPLEX){
			complex sum = 0;
			int k;
			for(k = 0; k < size; k++){
				sum += ((complex**)m1.values)[i][k] * ((complex**)m2.values)[k][j];
			}

			((complex**)result.values)[i][j] = sum;
		}
	}

	return result;
}





void printAnsMatrix(Matrix matrix){
	printf("%s\n", "answer:");
	if(matrix.eltype == FLOAT){
		int i, j;
		for(i = 0; i < matrix.size; i++){ for(j = 0; j < matrix.size; j++){
			printf("%f ", ((float**)matrix.values)[i][j]);
		}
		printf("\n");
	}
}
	else if(matrix.eltype == COMPLEX){
	
		int i, j;
		for(i = 0; i < matrix.size; i++){ for(j = 0; j < matrix.size; j++){
			printf("%g%+gi ", creal(((complex**)matrix.values)[i][j]), cimag(((complex**)matrix.values)[i][j]));
		}
		printf("\n");
	}
}
	printf("\n");
}


Matrix scanMatrix(){
	Matrix matrix;
	printf("%s\n", "type of matrix:\n1. float\n2. complex\n");

	int type;
	scanf("%d", &type); printf("\n");

	printf("%s\n", "size of matrix:");

	int size;
	scanf("%d", &size); printf("\n");

	Eltype eltype;
	if		(type == 1) eltype = FLOAT;
	else if	(type == 2) eltype = COMPLEX;

	matrix = createMatrix(eltype, size);

	if(eltype == FLOAT){
		printf("%s\n", "elements of matrix:");

		int i, j;
		for(i = 0; i < size; i++) for(j = 0; j < size; j++){
			scanf("%f", &(((float**)matrix.values)[i][j]));
		}
		printf("\n");
	}

	else if(eltype == COMPLEX){
		printf("%s\n", "real parts of elements of matrix:");
		int i, j;
		for(i = 0; i < size; i++) for(j = 0; j < size; j++){
			float real;
			scanf("%f", &real);

			((complex**)matrix.values)[i][j] += real;
		}
		printf("\n");

		printf("%s\n", "imaginary parts of elements of matrix:");
		
		for(i = 0; i < size; i++) for(j = 0; j < size; j++){
			float imag;
			scanf("%f", &imag);

			((complex**)matrix.values)[i][j] += imag * I;
		}
		printf("\n");
	}
	return matrix;
}


void interface(){
	Matrix a; a.size = 0;
	Matrix b; b.size = 0;
	float n;

	while(1){
		printf("%s\n",
			"1. set matrix A\n"
			"2. set matrix B\n"
			"3. set number n\n"
			"4. get A+B\n"
			"5. get A*B\n"
			"6. get n*A\n"
			"7. exit\n"
		);

		Matrix r; r.size = 0;

		int choice;
		scanf("%d", &choice); printf("\n");
		switch(choice){
			case 1:
				destroyMatrix(a);
				a = scanMatrix();
				break;
			case 2:
				destroyMatrix(b);
				b = scanMatrix();
				break;
			case 3:
				printf("%s\n", "number n:");
				scanf("%f", &n); printf("\n");
				break;
			case 4:
				r = add(a, b);
				printAnsMatrix(r);
				break;
			case 5:
				r = multiply(a, b);
				printAnsMatrix(r);
				break;
			case 6:
				r = scalMultiply(a, n);
				printAnsMatrix(r);
				break;
			case 7:
				return;
			default:
				exit(1);
				break;
		}

		destroyMatrix(r);

	}
}


int main(int argc, char **argv){
	interface();

	return 0;
}
