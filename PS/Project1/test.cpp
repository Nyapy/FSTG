#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


float a = 1.3e+10;
double b= 1.3e+10;

int main() {

	printf("float: %d byte, double: %d\n", sizeof(float), sizeof(double));
	printf("float: %f,\n double: %lf", a, b);
	return 0;
}