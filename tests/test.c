#include <assert.h>
#include <stdio.h>
#include "../src/algorithms.h"

void test_page_initialization() {
    Page page;
    init_page(&page);
    assert(page.page_number == -1);
    assert(page.referenced == false);
    assert(page.arrival_time == 0);
    printf("Test page initialization: PASSED\n");
}

void test_fifo() {
    Page frames[3];
    for(int i = 0; i < 3; i++) init_page(&frames[i]);
    
    // Teste básico do FIFO
    fifo_replace(frames, 3, 1, 0);
    assert(frames[0].page_number == 1);
    printf("Test FIFO: PASSED\n");
}

void test_second_chance() {
    Page frames[3];
    for(int i = 0; i < 3; i++) init_page(&frames[i]);
    
    second_chance_replace(frames, 3, 1, 0);
    assert(frames[0].page_number == 1);
    printf("Test Second Chance: PASSED\n");
}

void test_clock() {
    Page frames[3];
    for(int i = 0; i < 3; i++) init_page(&frames[i]);
    
    clock_replace(frames, 3, 1, 0);
    assert(frames[0].page_number == 1);
    printf("Test Clock: PASSED\n");
}

int main() {
    printf("Iniciando testes...\n");
    test_page_initialization();
    test_fifo();
    test_second_chance();
    test_clock();
    printf("Todos os testes passaram!\n");
    return 0;
}
