#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SIZE 1000

int ** A;
int ** B;
int ** C;

void multiply() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
		usleep(10);
	}
}

void printMatrix(int ** matrix) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
    int i, j;
    
    A = (int**)malloc(sizeof(int*)*SIZE);
	B = (int**)malloc(sizeof(int*)*SIZE);
	C = (int**)malloc(sizeof(int*)*SIZE);
	for (i = 0; i < SIZE; i++) {
		A[i] = (int*)malloc(sizeof(int)*SIZE);
		B[i] = (int*)malloc(sizeof(int)*SIZE);
		C[i] = (int*)malloc(sizeof(int)*SIZE);
	}
    
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			A[i][j] = 0;
			B[i][j] = 0;
			C[i][j] = 0;
		}
	}

    i = 0;
    j = 0;
    FILE *f = fopen("A", "r");
    int temp = 0, temp2 = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
		fscanf(f, "%d", &temp);
        	A[i][j] = temp;
        }
    }
    fclose(f);
    
	FILE *g = fopen("B", "r");
    for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
        	fscanf(g, "%d", &temp2);
        	B[i][j] = temp2;
        }
    }
    fclose(g);
    
    multiply();
    printMatrix(C);   
}
