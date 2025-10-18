

#include <stdio.h>
#include <omp.h>
// 1. omp_set_num_threads
void fn_omp_set_num_threads() {
    omp_set_num_threads(2);
#pragma omp parallel
    {
        printf("Thread %d of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
    }
}

// 2. omp_get_num_threads
void fn_omp_get_num_threads() {
#pragma omp parallel
    {
        printf("Thread %d of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
    }
}

// 3. omp_get_max_threads
void fn_omp_get_max_threads() {
    printf("Max threads: %d\n", omp_get_max_threads());
}

// 4. omp_get_thread_num
void fn_omp_get_thread_num() {
#pragma omp parallel
    {
        printf("Thread ID: %d\n", omp_get_thread_num());
    }
}

// 5. omp_get_num_procs
void fn_omp_get_num_procs() {
    printf("Number of processors: %d\n", omp_get_num_procs());
}

// 6. omp_in_parallel
void fn_omp_in_parallel() {
    printf("Outside parallel region: %d\n", omp_in_parallel());
#pragma omp parallel
    {
        printf("Inside parallel region: %d (thread %d)\n", omp_in_parallel(), omp_get_thread_num());
    }
}

// 7. omp_set_dynamic
void fn_omp_set_dynamic() {
    omp_set_dynamic(1);
    printf("Set dynamic threads to %d\n", omp_get_dynamic());
    omp_set_dynamic(0);
}

// 8. omp_get_dynamic
void fn_omp_get_dynamic() {
    printf("Dynamic threads setting: %d\n", omp_get_dynamic());
}

// 9. omp_get_cancellation
void fn_omp_get_cancellation() {
    printf("Cancellation setting: %d\n", omp_get_cancellation());
}

// 10. omp_set_nested
void fn_omp_set_nested() {
    omp_set_nested(1);
    printf("Set nested parallelism to %d\n", omp_get_nested());
    omp_set_nested(0);
}

// 11. omp_get_nested
void fn_omp_get_nested() {
    printf("Nested parallelism setting: %d\n", omp_get_nested());
}

// 12. omp_set_schedule
void fn_omp_set_schedule() {
    omp_set_schedule(omp_sched_dynamic, 2);
    omp_sched_t kind;
    int chunk_size;
    omp_get_schedule(&kind, &chunk_size);
    printf("Schedule kind: %d, chunk size: %d\n", kind, chunk_size);
}

// 13. omp_get_schedule
void fn_omp_get_schedule() {
    omp_sched_t kind;
    int chunk_size;
    omp_get_schedule(&kind, &chunk_size);
    printf("Schedule kind: %d, chunk size: %d\n", kind, chunk_size);
}

// 14. omp_get_thread_limit
void fn_omp_get_thread_limit() {
    printf("Thread limit: %d\n", omp_get_thread_limit());
}

// 15. omp_set_max_active_levels
void fn_omp_set_max_active_levels() {
    omp_set_max_active_levels(2);
    printf("Set max active levels to %d\n", omp_get_max_active_levels());
}

// 16. omp_get_max_active_levels
void fn_omp_get_max_active_levels() {
    printf("Max active levels: %d\n", omp_get_max_active_levels());
}

// 17. omp_get_level
void fn_omp_get_level() {
    omp_set_nested(1);
    printf("Outer level: %d\n", omp_get_level());
#pragma omp parallel num_threads(2)
    {
        printf("Inner level (thread %d): %d\n", omp_get_thread_num(), omp_get_level());
#pragma omp parallel num_threads(2)
        {
            printf("Innermost level (thread %d): %d\n", omp_get_thread_num(), omp_get_level());
        }
    }
    omp_set_nested(0);
}

// 18. omp_get_ancestor_thread_num
void fn_omp_get_ancestor_thread_num() {
    omp_set_nested(1);
    printf("Outer level thread ID: %d\n", omp_get_thread_num());
#pragma omp parallel num_threads(2)
    {
        printf("Inner level (thread %d), ancestor ID: %d\n", omp_get_thread_num(), omp_get_ancestor_thread_num(1));
    }
    omp_set_nested(0);
}

// 19. omp_get_team_size
void fn_omp_get_team_size() {
#pragma omp parallel num_threads(3)
    {
        printf("Thread %d of team size %d\n", omp_get_thread_num(), omp_get_team_size(omp_get_level()));
    }
}

// 20. omp_get_active_level
void fn_omp_get_active_level() {
    omp_set_nested(1);
    printf("Outside parallel: %d\n", omp_get_active_level());
#pragma omp parallel
    {
        printf("Inside outer parallel: %d\n", omp_get_active_level());
#pragma omp parallel
        {
            printf("Inside nested parallel: %d\n", omp_get_active_level());
        }
    }
    omp_set_nested(0);
}

// 21. omp_in_final
void fn_omp_in_final() {
    printf("Outside finalizer: %d\n", omp_in_final());
#pragma omp parallel
#pragma omp single nowait
    {
#pragma omp task final(1)
        {
            printf("Inside finalizer task: %d\n", omp_in_final());
        }
    }
}

// 22. omp_get_proc_bind
void fn_omp_get_proc_bind() {
    printf("Processor binding policy: %d\n", omp_get_proc_bind());
}

// 23. omp_set_default_device
void fn_omp_set_default_device() {
    printf("Current default device ID: %d\n", omp_get_default_device());
    omp_set_default_device(0);
    printf("New default device ID: %d\n", omp_get_default_device());
}

// 24. omp_get_default_device
void fn_omp_get_default_device() {
    printf("Default device ID: %d\n", omp_get_default_device());
}

// 25. omp_get_num_devices
void fn_omp_get_num_devices() {
    printf("Number of devices: %d\n", omp_get_num_devices());
}

// 26. omp_get_num_teams
void fn_omp_get_num_teams() {
#pragma omp teams num_teams(2)
    {
#pragma omp parallel
        {
            printf("Thread %d in team %d of %d teams\n", omp_get_thread_num(), omp_get_team_num(), omp_get_num_teams());
        }
    }
}

// 27. omp_get_team_num
void fn_omp_get_team_num() {
#pragma omp teams num_teams(2)
    {
        printf("Team ID: %d\n", omp_get_team_num());
    }
}
