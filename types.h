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
};

struct score{
  int score;
  char player_name[20];
};
