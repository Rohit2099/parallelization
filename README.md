## Performance Comparison of Pthread and OpenMP

## Objective:

The objective of this assignment is to compare the performance of different parallelization techniques by measuring the time taken to execute a matrix multiplication operation at various input sizes. The comparison focuses on **Pthread**, **OpenMP**, and a sequential (non-parallelized) version of the program.

---

## Results:

C programs were implemented using **OpenMP** and **Pthreads** for parallelization. A **sequential** version was also created to serve as a benchmark. The number of threads for parallelization was set to **four**. The OpenMP routine `omp_get_wtime()` was used to record the elapsed wall clock time in seconds for each execution.

---

## Observations:

-   The performance comparison showed gains when parallelizing the algorithm, although no significant difference was observed for smaller input sizes.
-   For smaller matrices, the **sequential version** outperforms both parallelization techniques due to the overhead involved in creating and managing threads.
-   From a matrix size of **128x128** and larger, the parallelization techniques begin to outperform the sequential version, achieving at least **4.33 milliseconds** of improvement.
-   **OpenMP** outperforms **Pthreads** for larger workloads (matrices sized **512x512** and above), indicating that OpenMP may handle higher workloads more efficiently.
-   Further optimization of the Pthreads implementation, such as using global arrays and size information, could improve performance.

---

## Contributions:

The programs using **OpenMP** and **Pthreads** were developed and executed on machines with different configurations:

-   **4 cores (8 hardware threads)**.
-   **2 cores (4 hardware threads)**.
    <br>
    The results from both setups were consistent, and the performance analysis and report were prepared collaboratively.

---

## Execution Instructions:

To run the programs, use the following commands in a Linux terminal. Replace `n` with the desired matrix size for multiplication (default is `n = 128`, for a 128x128 matrix multiplication).

### Sequential Execution:

```bash
$ gcc sequential.c -fopenmp -o sequential
$ ./sequential n
```
