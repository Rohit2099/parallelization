#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void gemm(double *A, double *B, double *C, int n) 
{	
	int i, j, k;
	for (i = 0; i < n; i++) { 
		for (j = 0; j < n; j++) {
			double dot  = 0;
			for (k = 0; k < n; k++) {
				dot += A[i*n+k]*B[k*n+j];
			} 
			C[i*n+j ] = dot;
		}
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
	gemm(A, B, C, n);
	dtime = omp_get_wtime() - dtime;
	printf("%0.9f seconds\n", dtime);

    // FILE *fptr;

    // fptr = fopen("time.txt", "w");
    // fprintf(fptr, "%0.9f", dtime);
    // fclose(fptr);
    return 0;
}