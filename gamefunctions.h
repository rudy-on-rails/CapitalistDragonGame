void draw_boundaries(struct scenario *scenario,struct WINDOW *win){
  for (int i = 0; i < scenario->width; ++i)
  {
    printw("-");
    wrefresh(win);
  }
  printw("|");
  wrefresh(win);
}

void draw_free_scenario(struct scenario *scenario, int current_height, struct snake *snake,struct WINDOW *win){
  int empty_spaces_to_skip = 0;
  for (int width = 0; width < scenario->width; ++width)
  {
    if (snake->position_x == current_height && snake->position_y == width){
      for (int width = 0; width < snake->number_of_foods_eaten + 1; ++width)
      {
        printw("🐉");
        wrefresh(win);
        empty_spaces_to_skip += 1;
      }
    }

    if (scenario->food_position_x == current_height && scenario->food_position_y == width){
      printw("💷");
      wrefresh(win);
      empty_spaces_to_skip += 1;
    }

    if (empty_spaces_to_skip == 0){
      printw(" ");
      wrefresh(win);
    }
    else{
      empty_spaces_to_skip -= 1;
    }
  }

  printw("|");
  wrefresh(win);
}

void detect_collision(){

}

void draw_scenario(struct scenario *scenario, struct snake *snake, struct WINDOW *win){
  clear_screen();

  int current_speed = 20000000L;

  for (int height = 0; height < scenario->height; ++height)
  {
    printw("|");
    if (height == 0){
      draw_boundaries(scenario, win);
    }
    else if(height < scenario->height - 1){
      draw_free_scenario(scenario, height, snake, win);
    }
    else{
      draw_boundaries(scenario, win);
    }
    printw("\n");
    wrefresh(win);
  }

  if (snake->moviment_direction == 0){
    snake->position_y += 1;
  }
  else if(snake->moviment_direction == 1){
    snake->position_y -= 1;
  }
  else if(snake->moviment_direction == 2){
    snake->position_x += 1;
  }
  else{
    snake->position_x -= 1;
  }

  if (scenario->food_position_x == snake->position_x && scenario->food_position_y == snake->position_y){
    snake->number_of_foods_eaten += 1;
    scenario->food_position_x = generate_random_position(LIMIT_SCREEN_HEIGHT / 2);
    scenario->food_position_y = generate_random_position(LIMIT_SCREEN_WIDTH / 2);
  }

  switch (getch()){
    case KEY_UP:
      snake->moviment_direction = 3;
      break;
    case KEY_DOWN:
      snake->moviment_direction = 2;
      break;
    case KEY_LEFT:
      snake->moviment_direction = 1;
      break;
    case KEY_RIGHT:
      snake->moviment_direction = 0;
      break;
  }

  clear();
  detect_collision();

  nanosleep((const struct timespec[]){{0, current_speed}}, NULL);
}
