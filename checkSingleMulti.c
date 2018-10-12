#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000
#define TRUE 1
#define FALSE 0

int ** C_single;
int ** C_multi;
int flag;

void printMatrix(int ** matrix) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%d ", matrix[i][j]);
		}
	}
}

int main() {
	int i, j;
	C_single = (int**)malloc(sizeof(int*)*SIZE);
    C_multi = (int**)malloc(sizeof(int*)*SIZE);
	for (i = 0; i < SIZE; i++) {
		C_single[i] = (int*)malloc(sizeof(int)*SIZE);
        C_multi[i] = (int*)malloc(sizeof(int)*SIZE);
	}

    for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			C_single[i][j] = 0;
            C_multi[i][j] = 0;
		}
	}

    FILE *f = fopen("C_singleThread", "r");
    int temp = 0, temp2 = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
		fscanf(f, "%d", &temp);
        	C_single[i][j] = temp;
        }
    }
    fclose(f);
    
	FILE *g = fopen("C_multiThread", "r");
    for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
        	fscanf(g, "%d", &temp2);
        	C_multi[i][j] = temp2;
        }
    }
    fclose(g);

    flag = TRUE;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (C_single[i][j] != C_multi[i][j]) {
                printf("Matrices do not MATCH!\n");
                flag = FALSE;
                break;
            }
		}
	}
    if (flag) {
        printf("Matrices MATCHED!\n");
    }
}
