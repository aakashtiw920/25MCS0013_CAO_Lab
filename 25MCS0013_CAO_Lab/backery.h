#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define DECK_SIZE 52
#define HALF_DECK 26
#define SHUFFLE_SWAPS 8000

static inline unsigned xorshift32(unsigned* state) {
    unsigned x = *state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x ? x : 0x9e3779b9u;
    return *state;
}

static void print_hand(const char* label, int* hand, int n) {
    printf("%s: ", label);
    for (int i = 0; i < n; ++i)
        printf("%d ", hand[i]);
    printf("\n");
}

int main() {
    int deck[DECK_SIZE];
    int p1[HALF_DECK], p2[HALF_DECK];

    for (int i = 0; i < DECK_SIZE; ++i)
        deck[i] = i + 1;

#pragma omp parallel
    {
#pragma omp single nowait
        {
            printf(">>> Game Start! Running with %d thread(s). <<<\n", omp_get_num_threads());
        }

        unsigned seed = (unsigned)time(NULL) ^ (unsigned)(omp_get_thread_num());

#pragma omp for
        for (int k = 0; k < SHUFFLE_SWAPS; ++k) {
            int i = xorshift32(&seed) % DECK_SIZE;
            int j = xorshift32(&seed) % DECK_SIZE;
            if (i == j) continue;

#pragma omp critical
            {
                int temp = deck[i];
                deck[i] = deck[j];
                deck[j] = temp;
            }
        }

#pragma omp sections
        {
#pragma omp section
            {
                for (int i = 0; i < HALF_DECK; ++i)
                    p1[i] = deck[i];
                printf("Player 1 cards dealt by thread %d\n", omp_get_thread_num());
            }

#pragma omp section
            {
                for (int i = 0; i < HALF_DECK; ++i)
                    p2[i] = deck[i + HALF_DECK];
                printf("Player 2 cards dealt by thread %d\n", omp_get_thread_num());
            }
        }
    }

    printf("\nFinal Hands:\n");
    print_hand("Player 1", p1, HALF_DECK);
    print_hand("Player 2", p2, HALF_DECK);

    return 0;
}
bakery_minimal.cpp
#include <cstdio>
#include <cstdlib>
#include <omp.h>

static inline void do_work(int units) {
    volatile double x = 0.0;
    for (int i = 0; i < units * 50000; ++i) x += i * 1e-7;
}

static double run_static(const int* cost, int* who, int n, int threads) {
    omp_set_num_threads(threads);
    double t0 = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp for schedule(static)
        for (int i = 0; i < n; ++i) {
            do_work(cost[i]);
            who[i] = omp_get_thread_num();
        }
    }
    return omp_get_wtime() - t0;
}

static double run_dynamic(const int* cost, int* who, int n, int threads) {
    omp_set_num_threads(threads);
    double t0 = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp for schedule(dynamic)
        for (int i = 0; i < n; ++i) {
            do_work(cost[i]);
            who[i] = omp_get_thread_num();
        }
    }
    return omp_get_wtime() - t0;
}

static double run_guided(const int* cost, int* who, int n, int threads) {
    omp_set_num_threads(threads);
    double t0 = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp for schedule(guided)
        for (int i = 0; i < n; ++i) {
            do_work(cost[i]);
            who[i] = omp_get_thread_num();
        }
    }
    return omp_get_wtime() - t0;
}

static void print_assignment(const char* title, const int* who, const int* cost, int n) {
    std::printf("\n%s\n", title);
    for (int i = 0; i < n; ++i) {
        std::printf("Order %2d (cost=%2d) -> Thread %d\n", i, cost[i], who[i]);
    }
}

int main(int argc, char** argv) {
    const int N = 20;
    int threads = (argc > 1) ? std::atoi(argv[1]) : 4;

    int cost[20] = { 3,12,1,8,20,2,15,6,10,4,7,14,5,11,9,18,13,16,19,17 };
    int who_static[20], who_dynamic[20], who_guided[20];

    double t_static = run_static(cost, who_static, N, threads);
    double t_dynamic = run_dynamic(cost, who_dynamic, N, threads);
    double t_guided = run_guided(cost, who_guided, N, threads);

    print_assignment("STATIC schedule assignment:", who_static, cost, N);
    print_assignment("DYNAMIC schedule assignment:", who_dynamic, cost, N);
    print_assignment("GUIDED schedule assignment:", who_guided, cost, N);

    std::printf("\nThreads: %d\n", threads);
    std::printf("Time (static):  %.6f s\n", t_static);
    std::printf("Time (dynamic): %.6f s\n", t_dynamic);
    std::printf("Time (guided):  %.6f s\n", t_guided);

    const char* best = "static";
    double best_t = t_static;
    if (t_dynamic < best_t) { best = "dynamic"; best_t = t_dynamic; }
    if (t_guided < best_t) { best = "guided";  best_t = t_guided; }
    std::printf("\nFastest in this run: %s (%.6f s)\n", best, best_t);
    return 0;
}#pragma once
