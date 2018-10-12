#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000

int ** A;

void printMatrix(int ** matrix) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", matrix[i][j]);
		}
	}
}

int main() {
	int i, j;
	A = (int**)malloc(sizeof(int*)*SIZE);
	for (i = 0; i < SIZE; i++) {
		A[i] = (int*)malloc(sizeof(int)*SIZE);
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			A[i][j] = rand() % 2000 + 1;
		}
	}
	printMatrix(A);
}
