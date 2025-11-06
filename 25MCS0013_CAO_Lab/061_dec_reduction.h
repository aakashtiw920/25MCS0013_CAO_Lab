#include <stdio.h>
#include <omp.h>
// Function to demonstrate reduction clause
void fn_dec_reduction() {
    int n = 10;
    int arr[10];
    int sum = 0;
    // Initialize array
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // array elements 1 to 10
    }
    // Parallel summation using reduction clause
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of array elements = %d\n", sum);
}
