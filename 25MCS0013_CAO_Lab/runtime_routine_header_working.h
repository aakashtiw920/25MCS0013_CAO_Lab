

#include <stdio.h>
#include <omp.h>

// 1. Number of threads in the current team
void fn_rter_omp_get_num_threads() {
#pragma omp parallel
    {
        printf("Thread %d of %d in team\n", omp_get_thread_num(), omp_get_num_threads());
    }
}

// 2. Thread ID
void fn_rter_omp_get_thread_num() {
#pragma omp parallel
    {
        printf("Thread ID: %d\n", omp_get_thread_num());
    }
}

// 3. Max number of threads
void fn_rter_omp_get_max_threads() {
    int max_threads = omp_get_max_threads();
    printf("Maximum number of threads the program can use: %d\n", max_threads);
}

// 4. Number of processors
void fn_rter_omp_get_num_procs() {
    int procs = omp_get_num_procs();
    printf("Number of available processors: %d\n", procs);
}

// 5. Check if we are inside a parallel region
void fn_rter_omp_in_parallel() {
    if (omp_in_parallel()) {
        printf("Currently inside a parallel region (outside check)\n");
    }
    else {
        printf("Currently outside a parallel region\n");
    }

#pragma omp parallel
    {
        if (omp_in_parallel()) {
            printf("Thread %d: Inside a parallel region\n", omp_get_thread_num());
        }
    }
}

// 6. Measure time taken by a dummy loop
void fn_rter_omp_get_wtime() {
    double start = omp_get_wtime();
    for (volatile long i = 0; i < 1e7; ++i); // Simulated workload
    double end = omp_get_wtime();
    printf("Time taken (using omp_get_wtime): %.6f seconds\n", end - start);
}

// 7. Basic Parallel Construct
void fn_rter_parallel_construct() {
#pragma omp parallel
    {
        printf("Thread %d says: Hello from parallel construct!\n", omp_get_thread_num());
    }
}

// 8. Parallel For Construct
void fn_rter_parallel_for_construct() {
    omp_set_num_threads(4); // You can customize this
#pragma omp parallel for
    for (int i = 0; i < 8; i++) {
        printf("Iteration %d handled by thread %d\n", i, omp_get_thread_num());
    }
}
