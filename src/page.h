#ifndef PAGE_H
#define PAGE_H

#include <stdbool.h>

// Estrutura para representar uma página na memória
typedef struct {
    int page_number;     // Número da página (-1 indica quadro vazio)
    bool referenced;     // Bit de referência (para Segunda Chance e Relógio)
    int arrival_time;    // Tempo de chegada (para FIFO)
} Page;

// Funções para manipulação de páginas
void init_page(Page* page);
void set_page(Page* page, int number, int time);
void clear_page(Page* page);

#endif