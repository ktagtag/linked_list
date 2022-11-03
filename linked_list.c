#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Cell *head = NULL;

//セル p の直後に新しいセルを挿入する
void insert_cell(Cell *p, int d) { 
  Cell *new_cell = (Cell*)malloc(sizeof(Cell));
  new_cell->data = d;
  new_cell->next = p->next;
  p->next = new_cell;
}

//リストの先頭に新しいセルを挿入する
void insert_cell_top(int d) {
  Cell *new_cell = (Cell*)malloc(sizeof(Cell));
  if (head == NULL){
    head = new_cell;
    head->data = d;
  }
  else {
    new_cell->data = d;
    new_cell->next = head;
    head = new_cell;
  }  
}

//セル p の直後のセルを削除する
void delete_cell(Cell *p) {
  Cell *q = p->next;
  p->next = p->next->next;
  free(q);
}

//リストの先頭のセルを削除する
void delete_cell_top(void) {
  Cell *ahead = head;
  head = head->next;
  free(ahead);
}

//リストの要素を順に標準出力する
void display(void) {
  Cell *ahead = head;
  while (ahead != NULL) {
    printf("%2d",ahead->data);
    ahead = ahead->next;
  }
  printf("\n");
}
