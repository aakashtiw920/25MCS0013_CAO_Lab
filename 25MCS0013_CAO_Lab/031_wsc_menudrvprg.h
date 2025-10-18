#include <stdio.h>
#include <omp.h>
#define N 12

void fn_initialize_arr(int a[]) {
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
}

double fn_compute_square_srl(int a[], int sq[]) {
    double start = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        sq[i] = a[i] * a[i];
        printf("Serial: Square of a[%d] : %d^2 = %d\n", i, a[i], sq[i]);
    }
    double end = omp_get_wtime();
    return end - start;
}

double fn_compute_square_prl(int a[], int sq[]) {
    double start = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        sq[i] = a[i] * a[i];
        printf("Parallel (Thread %d): Square of a[%d] = %d^2 = %d\n",
            omp_get_thread_num(), i, a[i], sq[i]);
    }
    double end = omp_get_wtime();
    return end - start;
}

void fn_display_result(int sq[]) {
    printf("\nSquared Result:\n");
    for (int i = 0; i < N; i++) {
        printf("squared[%d] = %d\n", i, sq[i]);
    }
}

void fn_run_serial() {
    int a[N], sq[N];
    fn_initialize_arr(a);
    double time = fn_compute_square_srl(a, sq);
    fn_display_result(sq);
    printf("Serial Execution Time: %.6f seconds\n", time);
}

void fn_run_parallel() {
    int a[N], sq[N];
    fn_initialize_arr(a);
    double time = fn_compute_square_prl(a, sq);
    fn_display_result(sq);
    printf("Parallel Execution Time: %.6f seconds\n", time);
}

void fn_run_performance_analysis() {
    int a[N], sq[N];
    fn_initialize_arr(a);

    double t_serial = fn_compute_square_srl(a, sq);
    double t_parallel = fn_compute_square_prl(a, sq);

    fn_display_result(sq);

    double speedup = t_serial / t_parallel;
    int threads = omp_get_max_threads();
    double efficiency = speedup / threads;

    printf("\n--- Performance Analysis ---\n");
    printf("Serial Time     : %.6f seconds\n", t_serial);
    printf("Parallel Time   : %.6f seconds\n", t_parallel);
    printf("Speedup         : %.4f\n", speedup);
    printf("Efficiency      : %.4f\n", efficiency);
}
