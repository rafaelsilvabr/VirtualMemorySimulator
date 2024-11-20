#include "page.h"

void init_page(Page* page) {
    page->page_number = -1;
    page->referenced = false;
    page->arrival_time = 0;
}

void set_page(Page* page, int number, int time) {
    page->page_number = number;
    page->referenced = false;
    page->arrival_time = time;
}

void clear_page(Page* page) {
    init_page(page);
}