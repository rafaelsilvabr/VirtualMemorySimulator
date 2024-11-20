#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "page.h"

// Tipos de algoritmos implementados
typedef enum {
    FIFO,
    SECOND_CHANCE,
    CLOCK
} Algorithm;

// Estrutura para manter estatísticas
typedef struct {
    int page_faults;
    int page_hits;
} Statistics;

// Funções dos algoritmos de substituição
int fifo_replace(Page* frames, int num_frames, int page_number, int current_time);
int second_chance_replace(Page* frames, int num_frames, int page_number, int current_time);
int clock_replace(Page* frames, int num_frames, int page_number, int current_time);

// Função para verificar se uma página está na memória
int find_page(Page* frames, int num_frames, int page_number);

// Função principal de simulação
Statistics simulate_memory(Algorithm alg, int num_frames, int num_references, double zipf_s);

int generate_zipf_page_number(double s);

#endif