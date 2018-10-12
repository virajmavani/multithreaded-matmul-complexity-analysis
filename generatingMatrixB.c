#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000

int ** B;

void printMatrix(int ** matrix) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", matrix[i][j]);
		}
	}
}

int main() {
	int i, j;
	B = (int**)malloc(sizeof(int*)*SIZE);
	for (i = 0; i < SIZE; i++) {
		B[i] = (int*)malloc(sizeof(int)*SIZE);
	}
	srand(rand());
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			B[i][j] = rand() % 2000 + 1;
		}
	}
	printMatrix(B);
}
