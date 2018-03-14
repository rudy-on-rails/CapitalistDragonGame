#include <time.h>

void draw_boundaries(struct scenario *scenario){
  for (int i = 0; i < scenario->width; ++i)
  {
    printf("-");
  }
  printf("|");
}

void draw_free_scenario(struct scenario *scenario, int current_height, struct snake *snake){
  for (int i = 0; i < scenario->width; ++i)
  {
    if (snake->position_x == current_height && snake->position_y == i){
      printf("o");
    }
    else{
      printf(" ");
    }
  }
  printf("|");
}

void detect_collision(){

}

void draw_scenario(struct scenario *scenario, struct snake *snake){
  clear_screen();
  for (int height = 0; height < scenario->height; ++height)
  {
    printf("|");
    if (height == 0){
      draw_boundaries(scenario);
    }
    else if(height < scenario->height - 1){
      draw_free_scenario(scenario, height, snake);
    }
    else{
      draw_boundaries(scenario);
    }
    printf("\n");
  }
  if (snake->moviment_direction == 0){
    snake->position_y = snake->position_y + 1;
  }
  else{
    snake->position_x = snake->position_x + 1;
  }
  detect_collision();
  nanosleep((const struct timespec[]){{0, 600000000L}}, NULL);
}
