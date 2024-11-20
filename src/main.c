#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "algorithms.h"

#define NUM_EXPERIMENTS 30
#define NUM_REFERENCES 1000
#define MIN_FRAMES 10
#define MAX_FRAMES 100
#define FRAME_STEP 10

int main() {
    srand(time(NULL));

    // Arquivo para salvar os resultados
    FILE* results = fopen("resultados.csv", "w");
    if (results == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo 'resultados.csv'.\n");
        return 1;
    }
    fprintf(results, "Quadros,FIFO,Segunda_Chance,Relogio\n");

    // Para cada tamanho de quadros
    for (int frames = MIN_FRAMES; frames <= MAX_FRAMES; frames += FRAME_STEP) {
        int fifo_total = 0;
        int sc_total = 0;
        int clock_total = 0;

        // Executa os experimentos
        for (int exp = 0; exp < NUM_EXPERIMENTS; exp++) {
            Statistics fifo_stats = simulate_memory(FIFO, frames, NUM_REFERENCES, 0.8);
            Statistics sc_stats = simulate_memory(SECOND_CHANCE, frames, NUM_REFERENCES, 0.8);
            Statistics clock_stats = simulate_memory(CLOCK, frames, NUM_REFERENCES, 0.8);

            fifo_total += fifo_stats.page_faults;
            sc_total += sc_stats.page_faults;
            clock_total += clock_stats.page_faults;
        }

        // Calcula e salva as médias
        fprintf(results, "%d,%d,%d,%d\n",
                frames,
                fifo_total / NUM_EXPERIMENTS,
                sc_total / NUM_EXPERIMENTS,
                clock_total / NUM_EXPERIMENTS);
    }

    fclose(results);
    return 0;
}

