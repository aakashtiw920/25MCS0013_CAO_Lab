#include"stdio.h"
#include"omp.h"

void fn_ret_tid_helloworld_srl()
{
	printf("Hello world serial printed by thread ID:%d\n",omp_get_thread_num());

}

void fn_ret_tid_helloworld_prl()
{
#pragma omp parallel
	printf("Hello world parallel printed by thread ID: %d\n", omp_get_thread_num());
}