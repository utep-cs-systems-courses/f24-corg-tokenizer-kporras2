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
  //create staring id
  static int curr_id = 1;
  // create a new node of type Item that is filled with garbage
  Item *newNode = (Item*)malloc(sizeof(Item));

  //verify node is not empty, because malloc returns NULL if unsucessfull memory location
  if(newNode == NULL){
    printf("Creating node failed, could not allocate memory");
    return;
  }

  //set int to zero that will be used to count the length of our input string
  int strLength = 0;
  // loop used to count the length of the string, check if char is not null or terminator, if not one of those increment
  while(*(str+strLength) != '\0' && *(str+strLength) != '\n') {strLength++; }

  //allocate memory for string in new node
  newNode->str = (char*) malloc((strLength+1) * sizeof(char));

  //verify memory allocation was successfull
  if(newNode->str == NULL){
    printf("allocating str in node failed");
    free(newNode);
    return;
  }

  //fill new node string with input string
  for(int i=0; i < strLength; i++) {newNode->str[i] = str[i]; }

  newNode->next = NULL;

  //if the list is empty put the node as the root
  if(list->root == NULL){
    newNode->id = curr_id;
    list->root = newNode;
  }
  //otherwise we find the end of the LL and point to the end of the LL last node
  else{
    Item *temp = list->root;
    while(temp->next != NULL){
      temp = temp->next;
    }

    //set id to current id int
    newNode->id = curr_id;
    //set next of last node in LL in to new node
    temp->next = newNode;
  }

  curr_id++;
}

char *get_history(List *list, int id){
  //verify that list is not empty before iterating over it
  if(list->root == NULL || list == NULL){
    printf("\nCurrent history is empty\n");
    return NULL;
  }
  //make ptr to head of the list to iterate over list
  Item *temp = list->root;
  //loop used to iterate through the entire list to find if a node matches the search id
  while(temp != NULL){

    //if current nodes id matches search id return the nodes str
    if(temp->id == id){
      return temp->str;
    }
    //move to next node to check
    temp = temp->next;
  }

  printf("\nID was not found in the list\n");
  return NULL;
}

void print_history(List *list){
  //check if list is empty before iterating over list
  if(list->root == NULL || list == NULL){
    printf("\nCurrent history is empty\n");
  }

  //create ptr that points to the head of the list so we can iterate over the LL
  Item *temp = list->root;
  printf("\nCurrent history:\n");
  while(temp != NULL){
    if(temp->str != NULL){
      printf("\nID: %d Str: %s", temp->id, temp->str);
    }
    else{
      printf("\nID: %d, Str: NULL", temp->id);
    }
  }
}

void free_history(List *list){
  //check if list is empty before iterating over
  if(list == NULL){
    return;
  }

  //create temp node to iterate over LL and node ptr to free memory
  Item *node;
  Item *temp = list->root;

  while(temp != NULL){
    node = temp;

    free(node->str);
    free(node);

    temp = temp->next;
  }

  printf("\nHistory has been cleared\n");
  
}
