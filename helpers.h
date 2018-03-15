void clear_screen(){
  system("clear");
}

int generate_random_position(int max){
  int nbr = rand();
  return nbr % max;
}
