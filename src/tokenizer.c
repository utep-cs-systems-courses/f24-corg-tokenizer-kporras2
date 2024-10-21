#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h" //project related declarations

//function that checks if a character is a space, tab and is non-zero aka terminator
int space_char(char c){
  if((c == ' ' || c == '\t') && c != '\0'){
    return 1;//true
  }
  else{
    return 0;//false
  }
}

//function that checks if a charater is non-zerp and is not a space or not a tab
int non_space_char(char c){
  if((c == ' ' || c == '\t') && c != '\0'){
    return 0;//false
  }
  else{
    return 1;//true
  }
}

char *token_start(char *str){
  //use an indexing to look at current char
  int i = 0;
  
  while(*(str + i)){//loop to check as long as there is a char
    
    if(non_space_char(*(str+i))){ // verify that the char is a nonspace char, aka a letter, which signifies the start of a word
      return str + i; // return address of ptr plus index to get start of word
    }
    
    i++; // increment if char is not a beginning of a word
  }
  return str + i; //return initial address if a nonspace char is not found with str
}

char *token_terminator(char *token){
  int i = 0;// index that will use to increment and iterate to find end of str
  
  while(*(token +i)){// while there is a char we will enter this loop
    
    if(space_char(*(token+i))){ // if the current char is a space char return the address of the str + the index which will give us the location of the end
      return token + i;
    }
    
    i++;//otherwise we will increment the index to look at next char
  }
  return token + i; // if space char are not found we will return base index
}

int count_tokens(char *str){
  // counter that will count amount of tokens
  int count = 0;
  // ptr to iterate through string
  char *current = str;

  //find current start before iterating through str so we dont instantly exit loop
  current = token_start(current);

  //while there is token
  while(*current){
    //increment count if we see a letter which signifies begining of word
    if(non_space_char(*current)){
      count++;
    }
    //move to next token by finding the end of current and finding start of next
    current = token_terminator(current);
    current = token_start(current);
  }

  return count;// return total count 
}

char *copy_str(char *inStrm ,short len){
  char *copied_str = malloc((len+1)*sizeof(char));// allocate new memory with space of original str and +1 for the terminator

  //loop that is use to copy every char for the length of the str
  for(int index = 0; index < len; index++){
    copied_str[index] = inStrm[index];
  }

  //add terminator to the end since malloc has junk when initialized
  copied_str[len] ='\0';
  return copied_str;
}

char **tokenize(char* str){
  //count total amount of tokens is str
  int total_toks = count_tokens(str);
  //create pointer we will use to iterate over str with it initialized pointing to str
  char *curr_token = str;
  //allocate memory for total size of token length and +1 for the terminator
  char **tokens = malloc(sizeof(char*) * (total_toks+1));

  //loop that go for the total length of tokens in str, will get start and end of each token and subtract the address to get the length of the token so we can copy it
  for(int index = 0; index < total_toks; index++){
    //find start
    curr_token = token_start(curr_token);
    //find end
    char *curr_token_end = token_terminator(curr_token);
    //get length
    int length = curr_token_end - curr_token;
    //set tokens at curr index to freshly allocated copy of str
    tokens[index] = copy_str(curr_token, length);
    //update pointer to the end of curr token so we can find the next 
    curr_token = curr_token_end;
  }

  //add terminator cause malloc doesnt do it for us
  tokens[total_toks] = '\0';
  return tokens;
}

void print_tokens(char **tokens){
  
  int i = 0;// index that is used to iterate and increment to traverse tokens
  while(tokens[i]){ //loop that checks if the token is non-terminating
    printf("%s->",tokens[i]);//print tok with format
    i++;//increment index
  }
}

void free_tokens(char **tokens){
  int i = 0; // index used to traverse the tokens array

  while(tokens[i]){ //loop that is used to iterate over tokens and free them one by one
    free(tokens[i]);//free memory
    i++;//increment index
  }
  
}
