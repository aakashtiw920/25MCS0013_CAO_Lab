#include"stdio.h"
#include"omp.h"
#define N 12
void fn_initialize_arr(int a[]) {
	for (int i = 0; i < N; i++) {
		a[i] = i + 1;
	}
}
void fn_compute_square_srl(int a[], int sq[]) {
	for (int i = 0; i < N; i++) {
		sq[i] = a[i] * a[i];
		printf("Squrare of a[%d] : a[%d]^2 = %d\n", i, a[i], sq[i]);
	}
}
void fn_compute_square_prl(int a[], int sq[]) {
#pragma omp parallel for
	for (int i = 0; i < N; i++) {
		sq[i] = a[i] * a[i];
		printf("Squrare of a[%d] : a[%d]^2 = %d using parallel construct\n", i, a[i],
			sq[i]);
	}
}
void fn_display_result(int sq[]) {
	printf("Squared result : \n");
	for (int i = 0; i < N; i++) {
		printf("squared[%d] = %d \n", i, sq[i]);
	}
}
int fn_num_square()
{
	int a[N], sq[N];
	fn_initialize_arr(a);
	fn_compute_square_srl(a, sq);
	fn_compute_square_prl(a, sq);
	fn_display_result(sq);
	return 0;
}