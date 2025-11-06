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

static inline void print_hand(const char* label, int* hand, int n) {
    printf("%s: ", label);
    for (int i = 0; i < n; ++i) printf("%d ", hand[i]);
    printf("\n");
}

static inline void play_openmp_card_game(void) {
    int deck[DECK_SIZE];
    int p1[HALF_DECK], p2[HALF_DECK];

    for (int i = 0; i < DECK_SIZE; ++i) deck[i] = i + 1;

#pragma omp parallel
    {
#pragma omp single nowait
        {
            printf(">>> Game Start! Running with %d thread(s). <<<\n", omp_get_num_threads());
        }

        unsigned seed = (unsigned)time(NULL) ^ (unsigned)(omp_get_thread_num());

#pragma omp for
        for (int k = 0; k < SHUFFLE_SWAPS; ++k) {
            int i = (int)(xorshift32(&seed) % DECK_SIZE);
            int j = (int)(xorshift32(&seed) % DECK_SIZE);
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
                for (int i = 0; i < HALF_DECK; ++i) p1[i] = deck[i];
                printf("Player 1 cards dealt by thread %d\n", omp_get_thread_num());
            }
#pragma omp section
            {
                for (int i = 0; i < HALF_DECK; ++i) p2[i] = deck[i + HALF_DECK];
                printf("Player 2 cards dealt by thread %d\n", omp_get_thread_num());
            }
        }
    }

    printf("\nFinal Hands:\n");
    print_hand("Player 1", p1, HALF_DECK);
    print_hand("Player 2", p2, HALF_DECK);
}



