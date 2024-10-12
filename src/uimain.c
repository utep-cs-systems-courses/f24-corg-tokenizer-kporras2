#include <stdio.h>
#include "tokenizer.h" //project related declaration
#include "history.h" //project related declaration

int main(){
  puts("Welcome to the tokenizer machine!");
  puts("---------------------------------");
  char tokens[10][100];
  char *toks_ptr;
  char menu_input; // char used to dictate menu function
  char idx = 0; // index of current token we are inputing
  char tok_ptr[10];

  // main_menu loop
  while(1){

    puts("Would you like to tokenize \"t\" , view history \"h\", Find token by I.D. \"i\", or quit \"q\" ");
    puts(">");

    menu_input = getchar();

    switch(menu_input){

      case 't':
        //take user input and tokenize
	puts("Please type what you would like to tokenize");
	puts(">");
	break;
	
      case 'h':
        //print history in linked list
	puts("Current token history: ");
	break;
	
      case 'i':
	//find a certain point in the linked list
	puts("Please enter the id of the token you are looking for");
	puts(">");
	break;
	
      case 'q':
	//this signifies the user wants to exit, free tokens
        puts("Thank you for using the tokenize machine, BYE!");
	goto end;
	
      default:
	puts("Invalid option, Try again! \n");
    }

    int c; // this loop is to clear the buffer so it does not affect the next iteration of the main_menu loop
    while((c = getchar()) != '\n' && c != EOF){}

    
  }

 end:
  return 0;
}
