#include <unistd.h>

void draw_up_or_down_wall(struct scenario *scenario){
  for (int i = 0; i < scenario->width; ++i)
  {
    printf("-");
  }
  printf("|");
}

void draw_left_and_right_walls(struct scenario *scenario){
  for (int i = 0; i < scenario->width; ++i)
  {
    printf(" ");
  }
  printf("|");
}

void draw_scenario(struct scenario *scenario, struct snake *snake){
  clear_screen();
  for (int i = 0; i < scenario->height; ++i)
  {
    printf("|");
    if (i == 0){
      draw_up_or_down_wall(scenario);
    }
    else if(i < scenario->height - 1){
      draw_left_and_right_walls(scenario);
    }
    else{
      draw_up_or_down_wall(scenario);
    }
    printf("\n");
  }
  sleep(1);
}
