#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <locale.h>
#include <time.h>
#include "helpers.h"
#include "types.h"
#include "gamefunctions.h"

void start_game(struct WINDOW *win){
  clear_screen();

  int snake_position_x = generate_random_position(LIMIT_SCREEN_HEIGHT / 2);
  int snake_position_y = generate_random_position(LIMIT_SCREEN_WIDTH / 2);

  int food_position_x = generate_random_position(LIMIT_SCREEN_HEIGHT / 2);
  int food_position_y = generate_random_position(LIMIT_SCREEN_WIDTH / 2);

  struct snake player = { 0, snake_position_x, snake_position_y, 0 };
  struct scenario main_scenario = { LIMIT_SCREEN_WIDTH, LIMIT_SCREEN_HEIGHT, food_position_x, food_position_y };

  while(1){
    draw_scenario(&main_scenario, &player, win);
  };
}

void display_high_scores(struct WINDOW *win){
  clear_screen();
}

void render_menu(struct WINDOW *win){
  int option;

  printw("Choose an option:\n");
  printw("1 - Start a new game\n");
  printw("2 - Display highest records\n");
  printw("3 - Exit\n");

  wrefresh(win);

  scanf("%d", &option);

  switch(option){
    case 1:
      start_game(win);
      render_menu(win);
    case 2:
      display_high_scores(win);
      render_menu(win);
    case 3:
      printw("See you soon\n");
      endwin();
      exit(0);
    default:
      printw("Invalid selection...\n\n");
      render_menu(win);
  }
}

int main(){
  setlocale(LC_CTYPE, "");
  WINDOW * win;

  win = initscr();

  srand ( time(NULL) );

  clear();
  noecho();
  cbreak();
  timeout(100);
  keypad(stdscr, TRUE);

  clear_screen();


  printw("💷  💷  💷  💷    The capitalist dragon game   💷  💷  💷  💷\n\n");
  printw("🐉   🐉   🐉   🐉   🐉   🐉   🐉   🐉   🐉   🐉   🐉   🐉   🐉   🐉\n");

  render_menu(win);

  return 0;
}


