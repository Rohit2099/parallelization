#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>

#define MAX_THREADS 4

typedef struct {
    int startX, n;
	double *A, *B, *C;
}Args;

pthread_t tid[MAX_THREADS];

void* worker(void * args){
    Args * arg = args;
    int i, j, k;
    int endX = arg->startX + arg->n / MAX_THREADS;
    for(i = arg->startX; i < endX; ++i){
        for(j = 0; j < arg->n; ++j){
			double dot  = 0;
			for (k = 0; k < arg->n; k++) {
				dot += arg->A[i*arg->n+k]*arg->B[k*arg->n+j];
			} 
			arg->C[i*arg->n+j ] = dot;
        }
    }
    free(arg);
    pthread_exit(0);
}

void matmul_par(double *A, double *B, double *C,int n) {
    int i = 0;
    int xCounter = 0;
    int yCounter = 0;
    int threadCounter = 0;

    for(; i < MAX_THREADS; ++i){
        Args * args = malloc(sizeof(* args));
        args->startX = xCounter;
        args->A = A;
        args->B = B;
        args->C = C;
        args->n = n;

        xCounter += n/MAX_THREADS;
        pthread_create(&tid[threadCounter++], 0, worker, args);
    }

    int j = 0;
    for(; j < MAX_THREADS; ++j){
        pthread_join(tid[j], NULL);
    }
}

int main(int argc, char** argv) {
	int i, n;
	double *A, *B, *C, dtime;

	n = 128;

    if(argc == 2){
        n = atoi(argv[1]);
    }

	A = (double*)malloc(sizeof(double) * n * n);
	B = (double*)malloc(sizeof(double) * n * n);
	C = (double*)malloc(sizeof(double) * n * n);

	for(i = 0; i < n * n; i++){
        A[i] = rand() / RAND_MAX;
        B[i] = rand() / RAND_MAX;
    }

	dtime = omp_get_wtime();
	matmul_par(A, B, C, n);
	dtime = omp_get_wtime() - dtime;
	printf("%0.9f seconds\n", dtime);
    
    FILE *fptr;

    fptr = fopen("time.txt", "w");
    fprintf(fptr, "%0.9f", dtime);
    fclose(fptr);
    return 0;
}