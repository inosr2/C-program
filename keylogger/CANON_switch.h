void tc_canon_on() {
  struct termios term;
  tcgetattr(0,&term);
  term.c_lflag |= ICANON;
  tcsetattr(0,TCSANOW,&term);
  return;
}

void tc_canon_off() {
  struct termios term;
  tcgetattr(0,&term);
  term.c_lflag &= ~ICANON;
  tcsetattr(0,TCSANOW,&term);
  return;
}
