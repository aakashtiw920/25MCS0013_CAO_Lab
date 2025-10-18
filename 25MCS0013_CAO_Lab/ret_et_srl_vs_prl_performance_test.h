#include"stdio.h"
#include"omp.h"
#include"stdlib.h"

// Serial Version: Just one thread printing
void fn_ret_tid_helloworld_srl1() {
    printf("\t\t\t\t\t\t\t\t\t\tSerial: Hello World from thread 0\n");
}

// Parallel Version: Each thread prints once
void fn_ret_tid_helloworld_prl(int cores) {
    omp_set_num_threads(cores);

#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("\t\t\t\t\t\t\t\t\tParallel: Hello World from thread %d\n", tid);
    }
}