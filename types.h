struct scenario{
  int width;
  int height;
  int food_position_x;
  int food_position_y;
};

struct snake{
  int number_of_foods_eaten;
  int position_x;
  int position_y;
  int moviment_direction; // 0 for right, 1 for left, 2 for up, 3 down
};

struct score{
  int score;
  char player_name[20];
};

enum{
  ARROW_UP    = 256 + 72,
  ARROW_DOWN  = 256 + 80,
  ARROW_LEFT  = 256 + 75,
  ARROW_RIGHT = 256 + 77
};
