#include <stdio.h>
#include "tokenizer.h" //project related declaration
#include "history.h" //project related declaration

int main(){
  printf("Welcome to the tokenizer machine! \n");
  char token_input[100];
  char menu_input; // char used to dictate menu function
  int id_input;
  char *retrived_token;
  List *history = init_history();
  // main_menu loop
  while(1){
    printf("\n------------------------------------------\n");
    printf("Would you like to tokenize \"t\" , view history \"h\", Find token by I.D. \"i\", or quit \"q\"\n ");
    printf(">");

    menu_input = getchar();
    getchar();
    switch(menu_input){

      case 't':
        //take user input and tokenize
	printf("Please type what you would like to tokenize\n >");
	
	fgets(token_input, sizeof(token_input), stdin);
	//try to tokenize, tell user if sucessfull or not
	char **tokens = tokenize(token_input);
	printf("\n");
	add_history(history, token_input);
	print_tokens(tokens);
	free_tokens(tokens);
	break;
	
      case 'h':
        //print history in linked list
	print_history(history);
	break;
	
      case 'i':
	//find a certain point in the linked list
	printf("Please enter the id of the token you are looking for\n");
	printf(">");

	scanf("%5d", &id_input);
	//call id finding
	if(get_history(history, id_input) != NULL){
	  retrived_token = get_history(history, id_input);
	}
	else{
	  break;
	}

	char **retrived = tokenize(retrived_token);
	printf("\nRetrived token:\n");
	print_tokens(retrived);
	free_tokens(retrived);
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
  free_history(history);
  printf("\nClosing tokenizer...\n");
  return 0;
}
