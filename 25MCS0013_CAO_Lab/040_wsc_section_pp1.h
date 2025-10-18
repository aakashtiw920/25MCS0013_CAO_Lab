#include"stdio.h"
#include"040_calculator_functions_pp1.h"
#include<omp.h>

void fn_wsc_sections_pp1_srl()
{
	int a = 5, b = 3,sum=0,difference=0;
	double start_time, end_time;
	start_time = omp_get_wtime();
	sum=fn_calculator_add(a, b);
	printf("Addition :%d +%d=%d thread id=%d\n", a, b, sum,omp_get_thread_num());
	difference = fn_calculator_subtract(a, b);
	printf("Subtraction :%d - %d=%d thread id=%d\n", a, b, difference,omp_get_thread_num());
	end_time = omp_get_wtime();
	printf("Serial execution time %f seconds\n", end_time - start_time);
}
void fn_wsc_sections_pp1_prl()
{
	int a = 5, b = 3, sum = 0, difference = 0;
	double start_time, end_time;

	start_time = omp_get_wtime();

#pragma omp parallel sections
	{
#pragma omp section
		{
			sum = fn_calculator_add(a, b);
			printf("Addition :%d +%d=%d thread id=%d\n", a, b, sum, omp_get_thread_num());
		}
#pragma omp section
		{

			difference = fn_calculator_subtract(a, b);
			printf("Subtraction :%d - %d=%d thread id=%d\n", a, b, difference, omp_get_thread_num());
		}
	}
	end_time = omp_get_wtime();
	printf("Parallel execution time %f seconds\n", end_time - start_time);

	
}

