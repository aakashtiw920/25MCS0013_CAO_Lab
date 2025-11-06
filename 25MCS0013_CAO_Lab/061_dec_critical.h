#include <stdio.h>
#include <omp.h>
// Function to demonstrate critical section
void fn_dec_critical()
{
    int i, n = 10;
    int arr[10];
    int sum = 0;
    // Initialize array
    for (i = 0; i < n; i++)
        arr[i] = i + 1; // array = {1,2,3,...,10}
    // Parallel region
#pragma omp parallel for
    for (i = 0; i < n; i++) {
#pragma omp critical
        {
            sum += arr[i];
            printf("Thread %d added %d to sum\n", omp_get_thread_num(), arr[i]);
        }
    }

    printf("Final Sum = %d\n", sum);
}

