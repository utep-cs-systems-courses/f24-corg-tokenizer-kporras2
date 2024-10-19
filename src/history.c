#include <stdio.h>
#include <stdlib.h>
#include "history.h" //project related declerations



List* init_history(){
  List *history = (List*)malloc(sizeof(List));

  if(history != NULL){
    history->root = NULL;
  }

  return history;
}



void add_history(List *list, char *str){
  //function def goes here
}

char *get_history(List *list, int id){
  //function def goes here
}

void print_history(List *list){
  //function def goes here
}

void free_history(List *list){
  //function def goes here
}
