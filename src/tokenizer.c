int space_char(char c){
  return ((c == ' ' || c == '\t') && c != '0')? 1 : 0;
}

int non_space_char(char c){
  return ((c != ' ' || c != '\t') && c != '0')? 1 : 0;
}

char *token_start(char *str){
  int i = 0;
  while(space_char(str[i]) && str[i] != '\n'){
    i++;
  }
  return &str[i];
}

char *token_terminator(char *token){
  char *start = token_start(token);
  int i = 0;
  while(non_space_char(start[i])&& start[i] != '\n'){
    i++;
  }
  return &start[i];
}

int count_tokens(char *str){
  int count = 0;
  char *current = token_start(str);
  while(*current != '\0'){
    count++;
    current = token_terminator(current);
    current = token_start(current);
  }

  return count + 1;
}

char *copy_str(char *inStrm ,short len){
  char *copied_str;
  
}

char **tokenize(char* str){
  
}

void print_tokens(char **tokens){
  
}

void free_tokens(char **tokens){
  
}
