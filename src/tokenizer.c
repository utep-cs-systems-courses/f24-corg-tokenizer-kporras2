#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h" //project related declarations

int space_char(char c){
  if((c == ' ' || c == '\t') && c != '\0'){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  if((c == ' ' || c == '\t') && c != '\0'){
    return 0;
  }
  else{
    return 1;
  }
}

char *token_start(char *str){
  int i = 0;
  
  while(*(str + i)){
    
    if(non_space_char(*(str+i))){
      return str + i;
    }
    
    i++;
  }
  return str + i;
}

char *token_terminator(char *token){
  int i = 0;
  
  while(*(token +i)){
    
    if(space_char(*(token+i))){
      return token + i;
    }
    
    i++;
  }
  return token + i;
}

int count_tokens(char *str){
  // counter that will count amount of tokens
  int count = 0;
  // ptr to iterate through string
  char *current = str;

  //find current start before iterating through str so we dont instantly exit loop
  current = token_start(current);

  
  while(*current){
    
    printf("%c\n",*current);
    if(non_space_char(*current)){
      count++;
    }
    
    current = token_terminator(current);
    current = token_start(current);
  }

  return count;
}

char *copy_str(char *inStrm ,short len){
  char *copied_str = malloc((len+1)*sizeof(char));
  
  for(int index = 0; index < len; index++){
    copied_str[index] = inStrm[index];
  }

  copied_str[len] ='\0';
  return copied_str;
}

char **tokenize(char* str){
  int total_toks = count_tokens(str);
  char *curr_token = str;
  char **tokens = malloc(sizeof(char*) * (total_toks+1));
  
  for(int index = 0; index < total_toks; index++){
    curr_token = token_start(curr_token);
    char *curr_token_end = token_terminator(curr_token);

    int length = curr_token_end - curr_token;

    tokens[index] = copy_str(curr_token, length);

    curr_token = curr_token_end;
  }
  
  tokens[total_toks] = '\0';
  return tokens;
}

void print_tokens(char **tokens){
  
  int i = 0;
  while(tokens[i]){
    printf("%s->",tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens){
  int i = 0; // index used to traverse the tokens array

  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  
}
