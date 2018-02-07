#include <stdio.h>
#include <stdlib.h>

void clearScreen(){
  system("clear");
}

void startGame(){
  clearScreen();
}

void displayHighScores(){
  clearScreen();
}

void renderMenu(){
  int option;
  printf("Choose an option:\n");
  printf("1 - Start a new game\n");
  printf("2 - Display Highest Records\n");
  printf("3 - Exit\n");
  while(scanf("%d", &option) == 1){
    switch(option){
      case 1:
        startGame();
        break;
      case 2:
        displayHighScores();
        break;
      case 3:
        clearScreen();
        exit(0);
      default:
        printf("Invalid selection...\n\n");
        renderMenu();
    }
  }
}

int main(){
  clearScreen();
  printf("The snake game Old-school...\n\n");
  printf("**************************\n");
  renderMenu();
  return 0;
}


