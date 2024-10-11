#include <stdio.h>
#include "tokenizer.h" //project related declaration
#include "history.h" //project related declaration

int main(){
  puts("Welcome to the tokenizer machine!");
  puts("---------------------------------");

  while(1){

    puts("Would you like to tokenize \"t\" , view history \"h\",  or quit \"q\" ");
    puts(">");

    char user_input;

    user_input = getchar();

    switch(user_input){
      case "t":
        //take user input and tokenize
        break;
      case "h":
        //print history show history
	break;
      case"q":
        puts("Thank you for using the tokenize machine, BYE!");
	goto end;
    }

    
  }

 end:
  return 0;
}
