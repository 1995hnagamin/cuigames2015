#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i;
  char str[6];
  srand((unsigned)time(NULL));
  for (i = 0; i < 6; ++i) str[i] = '\0';
	int key;

	initscr();
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  bkgd(COLOR_PAIR(1));
	noecho();
	cbreak();
	timeout(0);

  for (i = 0; i < 3; ++i) {
    char strbef[6];
    char straft[6];
  	while (1) {
      int j;
      for (j = 2 * i; j < 5; ++j) {
        int ir = rand() % 26;
        str[j] = (j % 2 == 1 ? ' ':'A' + ir);
      }

      strcpy(strbef, str);
      strcpy(straft, str);
      for (j = 0; j < 5; j += 2) {
        strbef[j]--;
        straft[j]++;
      }
      for (j = 1; j < 4; j += 2) {
        strbef[j] = straft[j] = '|';
      }
      
      erase();
      move(0, 0);
      attrset(COLOR_PAIR(1));
      addstr(strbef);
      move(1, 0);
      attrset(COLOR_PAIR(2)|A_BOLD);
      addstr(str);
      move(2, 0);
      attrset(COLOR_PAIR(1));
      addstr(straft);
  		refresh();
  
  		key = getch();
  		if (key == ' ') break;
  
  		usleep(110000);
  	}
  }
  usleep(500000);
  endwin();
  printf("%s\n", str);
  return 0;
}
