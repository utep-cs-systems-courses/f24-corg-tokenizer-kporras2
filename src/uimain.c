#include <stdio.h>
#include "tokenizer.h" //project related declaration
#include "history.h" //project related declaration

int main(){
  printf("Welcome to the tokenizer machine! \n");
  char token_input[100];
  char *toks_ptr;
  char menu_input; // char used to dictate menu function
  char index_input[3];
  char idx = 0; // index of current token we are inputing

  // main_menu loop
  while(1){
    printf("------------------------------------------\n");
    printf("Would you like to tokenize \"t\" , view history \"h\", Find token by I.D. \"i\", or quit \"q\"\n ");
    printf(">");

    menu_input = getchar();

    switch(menu_input){

      case 't':
        //take user input and tokenize
	printf("Please type what you would like to tokenize\n");
	printf(">");

	fgets(token_input, sizeof(token_input), stdin);
	//try to tokenize, tell user if sucessfull or not
	break;
	
      case 'h':
        //print history in linked list
	printf("Current token history:\n\n");
	//print hitory here
	break;
	
      case 'i':
	//find a certain point in the linked list
	printf("Please enter the id of the token you are looking for\n");
	printf(">");

	fgets(index_input, sizeof(index_input), stdin);
	//call id finding
	
	break;
	
      case 'q':
	//this signifies the user wants to exit, free tokens
        printf("Thank you for using the tokenize machine, BYE! \n");
	goto end;
	
      default:
	printf("Invalid option, Try again! \n");
    }

    int c; // this loop is to clear the buffer so it does not affect the next iteration of the main_menu loop
    while((c = getchar()) != '\n' && c != EOF){}
  }

 end:
  return 0;
}
