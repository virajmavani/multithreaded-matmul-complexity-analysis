#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include<unistd.h>
#include <semaphore.h> 


#define SIZE 1000
#define MAX_THREAD 5


int ** A;
int ** B;
int ** C;
int step_i = 0;

sem_t mutex;

void* multi(void* arg) 
{ 
    sem_wait(&mutex);
	int core = step_i++; 
	sem_post(&mutex);
	
    for (int i = core * SIZE/MAX_THREAD; i < (core + 1) * (SIZE/MAX_THREAD); i++) {  
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
	sem_init(&mutex, 0, 1); 
 	A = (int **) malloc(sizeof(int*)*SIZE);
	B = (int **) malloc(sizeof(int*)*SIZE);
	C = (int **) malloc(sizeof(int*)*SIZE);
	
	for (int i = 0; i < SIZE; i++) {
	    A[i] = (int *)malloc(sizeof(int)*SIZE);
		B[i] = (int *)malloc(sizeof(int)*SIZE);
		C[i] = (int *)malloc(sizeof(int)*SIZE);
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
	
	pthread_t threads[MAX_THREAD]; 

	step_i = 0;

	// Creating five threads, each evaluating its own part 
    for (i = 0; i < MAX_THREAD; i++) { 
        int* p; 
	    pthread_create(&threads[i], NULL, multi, (void*)(p)); 
    } 
  
	// joining and waiting for all threads to complete 
	for (i = 0; i < MAX_THREAD; i++)  
        	pthread_join(threads[i], NULL);     
  
	// Displaying the result matrix 
	printMatrix(C); 

	return 0;
}
