#include <stdlib.h>
#include "algorithms.h"

int find_page(Page* frames, int num_frames, int page_number) {
    for(int i = 0; i < num_frames; i++) {
        if(frames[i].page_number == page_number) {
            return i;
        }
    }
    return -1;
}

int fifo_replace(Page* frames, int num_frames, int page_number, int current_time) {
    int oldest_index = 0;
    int oldest_time = frames[0].arrival_time;
    
    for(int i = 1; i < num_frames; i++) {
        if(frames[i].arrival_time < oldest_time) {
            oldest_time = frames[i].arrival_time;
            oldest_index = i;
        }
    }
    
    set_page(&frames[oldest_index], page_number, current_time);
    return oldest_index;
}

int second_chance_replace(Page* frames, int num_frames, int page_number, int current_time) {
    static int pointer = 0;
    
    while(1) {
        if(!frames[pointer].referenced) {
            int victim = pointer;
            pointer = (pointer + 1) % num_frames;
            set_page(&frames[victim], page_number, current_time);
            return victim;
        }
        frames[pointer].referenced = false;
        pointer = (pointer + 1) % num_frames;
    }
}

int clock_replace(Page* frames, int num_frames, int page_number, int current_time) {
    static int pointer = 0;
    
    while(1) {
        if(!frames[pointer].referenced) {
            int victim = pointer;
            pointer = (pointer + 1) % num_frames;
            set_page(&frames[victim], page_number, current_time);
            return victim;
        }
        frames[pointer].referenced = false;
        pointer = (pointer + 1) % num_frames;
    }
}

Statistics simulate_memory(Algorithm alg, int num_frames, int num_references) {
    Statistics stats = {0, 0};
    Page* frames = malloc(sizeof(Page) * num_frames);
    
    // Inicializa os quadros
    for(int i = 0; i < num_frames; i++) {
        init_page(&frames[i]);
    }
    
    // Executa a simulação
    for(int time = 0; time < num_references; time++) {
        int page_number = (rand() % 200) + 1;
        int frame_index = find_page(frames, num_frames, page_number);
        
        if(frame_index == -1) {
            // Page fault
            stats.page_faults++;
            
            // Procura por um quadro vazio
            frame_index = find_page(frames, num_frames, -1);
            
            if(frame_index != -1) {
                set_page(&frames[frame_index], page_number, time);
            } else {
                // Necessário substituir uma página
                switch(alg) {
                    case FIFO:
                        fifo_replace(frames, num_frames, page_number, time);
                        break;
                    case SECOND_CHANCE:
                        second_chance_replace(frames, num_frames, page_number, time);
                        break;
                    case CLOCK:
                        clock_replace(frames, num_frames, page_number, time);
                        break;
                }
            }
        } else {
            // Page hit
            stats.page_hits++;
            frames[frame_index].referenced = true;
        }
    }
    
    free(frames);
    return stats;
}