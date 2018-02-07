#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "gamefunctions.h"

void clear_screen(){
  system("clear");
}

void startGame(){
  clear_screen();
}

void display_high_scores(){
  clear_screen();
}

void render_menu(){
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
        display_high_scores();
        break;
      case 3:
        clear_screen();
        exit(0);
      default:
        printf("Invalid selection...\n\n");
        render_menu();
    }
  }
}

int main(){
  clear_screen();
  printf("The snake game Old-school...\n\n");
  printf("**************************\n");
  render_menu();
  return 0;
}


