#include "sqare_matrix.c"

void AddTestFloat1()
{
	Matrix a = createMatrix(FLOAT, 2);
	((float**)a.values)[0][0] = 1.0;
	((float**)a.values)[0][1] = 2.0;
	((float**)a.values)[1][0] = 3.0;
	((float**)a.values)[1][1] = 4.0;
	
	Matrix b = createMatrix(FLOAT, 2);
	((float**)b.values)[0][0] = 1.0;
	((float**)b.values)[0][1] = 3.0;
	((float**)b.values)[1][0] = 5.0;
	((float**)b.values)[1][1] = 7.0;
	
	Matrix ans = createMatrix(FLOAT, 2);
	((float**)ans.values)[0][0] = 2.0;
	((float**)ans.values)[0][1] = 5.0;
	((float**)ans.values)[1][0] = 8.0;
	((float**)ans.values)[1][1] = 11.0;
	
	Matrix r = add(a,b);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A+B Float Test1: Good!");
	}
	else {
		printf("A+B Float Test1: Not good");
	}
	return 0;
}

void AddTestFloat2()
{
	Matrix a = createMatrix(FLOAT, 2);
	((float**)a.values)[0][0] = 1.38;
	((float**)a.values)[0][1] = 2.73;
	((float**)a.values)[1][0] = 3.14;
	((float**)a.values)[1][1] = 4.95;
	
	Matrix b = createMatrix(FLOAT, 2);
	((float**)b.values)[0][0] = 1.02;
	((float**)b.values)[0][1] = 3.07;
	((float**)b.values)[1][0] = 5.06;
	((float**)b.values)[1][1] = 7.05;
	
	Matrix ans = createMatrix(FLOAT, 2);
	((float**)ans.values)[0][0] = 2.4;
	((float**)ans.values)[0][1] = 5.8;
	((float**)ans.values)[1][0] = 8.2;
	((float**)ans.values)[1][1] = 12.0;
	
	Matrix r = add(a,b);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A+B Float Test2: Good!");
	}
	else {
		printf("A+B Float Test2: Not good");
	}
	return 0;
}

void AddTestComplex1()
{
	Matrix a = createMatrix(COMPLEX, 2);
	((complex**)a.values)[0][0] = 1.0+0.1*I;
	((complex**)a.values)[0][1] = 2.0+0.2*I;
	((complex**)a.values)[1][0] = 3.0+0.3*I;
	((complex**)a.values)[1][1] = 4.0+0.4*I;
	
	Matrix b = createMatrix(COMPLEX, 2);
	((complex**)b.values)[0][0] = 1.0+0.1*I;
	((complex**)b.values)[0][1] = 3.0+0.3*I;
	((complex**)b.values)[1][0] = 5.0+0.5*I;
	((complex**)b.values)[1][1] = 7.0+0.7*I;
	
	Matrix ans = createMatrix(COMPLEX, 2);
	((complex**)ans.values)[0][0] = 2.0+0.2*I;
	((complex**)ans.values)[0][1] = 5.0+0.5*I;
	((complex**)ans.values)[1][0] = 8.0+0.8*I;
	((complex**)ans.values)[1][1] = 11.0+1.1*I;
	
	Matrix r = add(a,b);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A+B Complex Test1: Good!");
	}
	else {
		printf("A+B Complex Test1: Not good");
	}
	return 0;
}

void AddTestComplex2()
{
	Matrix a = createMatrix(COMPLEX, 2);
	((complex**)a.values)[0][0] = 1.3+8.3*I;
	((complex**)a.values)[0][1] = 2.7+3.7*I;
	((complex**)a.values)[1][0] = 3.1+4.1*I;
	((complex**)a.values)[1][1] = 4.9+5.9*I;
	
	Matrix b = createMatrix(COMPLEX, 2);
	((complex**)b.values)[0][0] = 1.2+0.9*I;
	((complex**)b.values)[0][1] = 3.7+1.8*I;
	((complex**)b.values)[1][0] = 5.6+2.7*I;
	((complex**)b.values)[1][1] = 7.5+3.6*I;
	
	Matrix ans = createMatrix(COMPLEX, 2);
	((complex**)ans.values)[0][0] = 2.5+9.2*I;
	((complex**)ans.values)[0][1] = 6.4+5.5*I;
	((complex**)ans.values)[1][0] = 8.7+6.8*I;
	((complex**)ans.values)[1][1] = 12.4+9.5*I;
	
	Matrix r = add(a,b);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A+B Complex Test2: Good!");
	}
	else {
		printf("A+B Complex Test2: Not good");
	}
	return 0;
}

void MultiplyTestFloat1()
{
	Matrix a = createMatrix(FLOAT, 2);
	((float**)a.values)[0][0] = 1.0;
	((float**)a.values)[0][1] = 2.0;
	((float**)a.values)[1][0] = 3.0;
	((float**)a.values)[1][1] = 4.0;
	
	Matrix b = createMatrix(FLOAT, 2);
	((float**)b.values)[0][0] = 1.0;
	((float**)b.values)[0][1] = 3.0;
	((float**)b.values)[1][0] = 5.0;
	((float**)b.values)[1][1] = 7.0;
	
	Matrix ans = createMatrix(FLOAT, 2);
	((float**)ans.values)[0][0] = 11.0;
	((float**)ans.values)[0][1] = 17.0;
	((float**)ans.values)[1][0] = 23.0;
	((float**)ans.values)[1][1] = 37.0;
	
	Matrix r = multiply(a,b);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A*B Float Test1: Good!");
	}
	else {
		printf("A*B Float Test1: Not good");
	}
	return 0;
}

void MultiplyTestFloat2()
{
	Matrix a = createMatrix(FLOAT, 2);
	((float**)a.values)[0][0] = 1.38;
	((float**)a.values)[0][1] = 2.73;
	((float**)a.values)[1][0] = 3.14;
	((float**)a.values)[1][1] = 4.95;
	
	Matrix b = createMatrix(FLOAT, 2);
	((float**)b.values)[0][0] = 1.02;
	((float**)b.values)[0][1] = 3.07;
	((float**)b.values)[1][0] = 5.06;
	((float**)b.values)[1][1] = 7.05;
	
	Matrix ans = createMatrix(FLOAT, 2);
	((float**)ans.values)[0][0] = 15.221399;
	((float**)ans.values)[0][1] = 23.483101;
	((float**)ans.values)[1][0] = 28.249800;
	((float**)ans.values)[1][1] = 44.537300;
	
	Matrix r = multiply(a,b);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A*B Float Test2: Good!");
	}
	else {
		printf("A*B Float Test2: Not good");
	}
	return 0;
}

void MultiplyTestComplex1()
{
	Matrix a = createMatrix(COMPLEX, 2);
	((complex**)a.values)[0][0] = 1+1*I;
	((complex**)a.values)[0][1] = 2+2*I;
	((complex**)a.values)[1][0] = 3+3*I;
	((complex**)a.values)[1][1] = 4+4*I;
	
	Matrix b = createMatrix(COMPLEX, 2);
	((complex**)b.values)[0][0] = 1+1*I;
	((complex**)b.values)[0][1] = 3+3*I;
	((complex**)b.values)[1][0] = 5+5*I;
	((complex**)b.values)[1][1] = 7+7*I;
	
	Matrix ans = createMatrix(COMPLEX, 2);
	((complex**)ans.values)[0][0] = 0+22*I;
	((complex**)ans.values)[0][1] = 0+34*I;
	((complex**)ans.values)[1][0] = 0+46*I;
	((complex**)ans.values)[1][1] = 0+74*I;
	
	Matrix r = multiply(a,b);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A*B Complex Test1: Good!");
	}
	else {
		printf("A*B Complex Test1: Not good");
	}
	return 0;
}

void MultiplyTestComplex2()
{
	Matrix a = createMatrix(COMPLEX, 2);
	((complex**)a.values)[0][0] = 1+4*I;
	((complex**)a.values)[0][1] = 2+3*I;
	((complex**)a.values)[1][0] = 3+2*I;
	((complex**)a.values)[1][1] = 4+1*I;
	
	Matrix b = createMatrix(COMPLEX, 2);
	((complex**)b.values)[0][0] = 1+7*I;
	((complex**)b.values)[0][1] = 3+5*I;
	((complex**)b.values)[1][0] = 5+3*I;
	((complex**)b.values)[1][1] = 7+1*I;
	
	Matrix ans = createMatrix(COMPLEX, 2);
	((complex**)ans.values)[0][0] = -26+32*I;
	((complex**)ans.values)[0][1] = -6+40*I;
	((complex**)ans.values)[1][0] = 6+40*I;
	((complex**)ans.values)[1][1] = 26+32*I;
	
	Matrix r = multiply(a,b);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A*B Complex Test2: Good!");
	}
	else {
		printf("A*B Complex Test2: Not good");
	}
	return 0;
}

void ScalMultiplyTestFloat1()
{
	Matrix a = createMatrix(FLOAT, 2);
	((float**)a.values)[0][0] = 1.0;
	((float**)a.values)[0][1] = 2.0;
	((float**)a.values)[1][0] = 3.0;
	((float**)a.values)[1][1] = 4.0;
	
	float n = 2;
	
	Matrix ans = createMatrix(FLOAT, 2);
	((float**)ans.values)[0][0] = 2.0;
	((float**)ans.values)[0][1] = 4.0;
	((float**)ans.values)[1][0] = 6.0;
	((float**)ans.values)[1][1] = 8.0;
	
	Matrix r = scalMultiply(a,n);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A*n Float Test1: Good!");
	}
	else {
		printf("A*n Float Test1: Not good");
	}
	return 0;
}

void ScalMultiplyTestFloat2()
{
	Matrix a = createMatrix(FLOAT, 2);
	((float**)a.values)[0][0] = 1.3;
	((float**)a.values)[0][1] = 2.7;
	((float**)a.values)[1][0] = 3.1;
	((float**)a.values)[1][1] = 4.9;
	
	float n = 2.5;
	
	Matrix ans = createMatrix(FLOAT, 2);
	((float**)ans.values)[0][0] = 3.25;
	((float**)ans.values)[0][1] = 6.75;
	((float**)ans.values)[1][0] = 7.75;
	((float**)ans.values)[1][1] = 12.25;
	
	Matrix r = scalMultiply(a,n);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A*n Float Test2: Good!");
	}
	else {
		printf("A*n Float Test2: Not good");
	}
	return 0;
}

void ScalMultiplyTestComplex1()
{
	Matrix a = createMatrix(COMPLEX, 2);
	((complex**)a.values)[0][0] = 1.0+0.1*I;
	((complex**)a.values)[0][1] = 2.0+0.2*I;
	((complex**)a.values)[1][0] = 3.0+0.3*I;
	((complex**)a.values)[1][1] = 4.0+0.4*I;
	
	float n = 2;
	
	Matrix ans = createMatrix(COMPLEX, 2);
	((complex**)ans.values)[0][0] = 2.0+0.2*I;
	((complex**)ans.values)[0][1] = 4.0+0.4*I;
	((complex**)ans.values)[1][0] = 6.0+0.6*I;
	((complex**)ans.values)[1][1] = 8.0+0.8*I;
	
	Matrix r = scalMultiply(a,n);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A*n Complex Test1: Good!");
	}
	else {
		printf("A*n Complex Test1: Not good");
	}
	return 0;
}

void ScalMultiplyTestComplex2()
{
	Matrix a = createMatrix(COMPLEX, 2);
	((complex**)a.values)[0][0] = 1.3+8.3*I;
	((complex**)a.values)[0][1] = 2.7+3.7*I;
	((complex**)a.values)[1][0] = 3.1+4.1*I;
	((complex**)a.values)[1][1] = 4.9+5.9*I;
	
	float n = 2.5;
	
	Matrix ans = createMatrix(COMPLEX, 2);
	((complex**)ans.values)[0][0] = 3.25+20.75*I;
	((complex**)ans.values)[0][1] = 6.75+9.25*I;
	((complex**)ans.values)[1][0] = 7.75+10.25*I;
	((complex**)ans.values)[1][1] = 12.25+14.75*I;
	
	Matrix r = scalMultiply(a,n);
	
	int i, j, k;
	k = 0;
	for (i = 0; i < 2; i++) for (j = 0; j < 2; j++){
		if (((float**)r.values)[i][j] == ((float**)ans.values)[i][j]){
			k++;
		}
	}
	if (k==4){
		printf("A*n Complex Test2: Good!");
	}
	else {
		printf("A*n Complex Test2: Not good");
	}
	return 0;
}

int main(){
	AddTestFloat1(); printf("\n");
	AddTestFloat2(); printf("\n");
	AddTestComplex1(); printf("\n");
	AddTestComplex2(); printf("\n");
	MultiplyTestFloat1(); printf("\n");
	MultiplyTestFloat2(); printf("\n");
	MultiplyTestComplex1(); printf("\n");
	MultiplyTestComplex2(); printf("\n");
	ScalMultiplyTestFloat1(); printf("\n");
	ScalMultiplyTestFloat2(); printf("\n");
	ScalMultiplyTestComplex1(); printf("\n");
	ScalMultiplyTestComplex2(); printf("\n");
	
	return 0;
}
