#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "types.h"
#include "gamefunctions.h"

void start_game(){
  clear_screen();

  int limit_screen_width = 100;
  int limit_screen_height = 50;
  int snake_position_x = generate_random_position(limit_screen_width / 2);
  int snake_position_y = generate_random_position(limit_screen_height / 2);

  struct snake player = { 0, snake_position_x, snake_position_y, 0 };

  while(1){
    int food_position_x = generate_random_position(limit_screen_width);
    int food_position_y = generate_random_position(limit_screen_height);

    struct scenario main_scenario = { limit_screen_width, limit_screen_height, food_position_x, food_position_y };

    draw_scenario(&main_scenario, &player);
  };
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

  scanf("%d", &option);

  switch(option){
    case 1:
      start_game();
      render_menu();
    case 2:
      display_high_scores();
      render_menu();
    case 3:
      printf("See you soon\n");
      exit(0);
    default:
      printf("Invalid selection...\n\n");
      render_menu();
  }
}

int main(){
  clear_screen();

  printf("The old-school snake game...\n\n");
  printf("**************************\n");

  render_menu();

  return 0;
}


