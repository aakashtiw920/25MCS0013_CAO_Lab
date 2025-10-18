#include "stdio.h"
#include "omp.h"
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
	return (end - start); // return serial execution time
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
	return (end - start); // return parallel execution time
}

void fn_display_result(int sq[]) {
	printf("\nSquared Result:\n");
	for (int i = 0; i < N; i++) {
		printf("squared[%d] = %d\n", i, sq[i]);
	}
}

int fn_num_square() {
	int a[N], sq[N];
	fn_initialize_arr(a);

	// Serial Execution
	double et_srl = fn_compute_square_srl(a, sq);

	// Parallel Execution
	double et_prl = fn_compute_square_prl(a, sq);

	// Speedup and Efficiency
	double speedup = et_srl / et_prl;
	int num_threads = omp_get_max_threads();
	double efficiency = speedup / num_threads;

	fn_display_result(sq);

	printf("\n--- Performance Analysis ---\n");
	printf("Serial Time     : %.6f seconds\n", et_srl);
	printf("Parallel Time   : %.6f seconds\n", et_prl);
	printf("Speedup         : %.4f\n", speedup);
	printf("Efficiency      : %.4f\n", efficiency);

	return 0;
}
#pragma once
