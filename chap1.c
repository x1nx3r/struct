#include <ncurses.h>

int main() {
    
    //initialize the screen
    //sets up memory and clears the scren 
    initscr();
    cbreak();   //makes it so that ctrl+c exits the program
    noecho();   //whatever input that user types won't be shown on the screen

    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y=start_x=10;


    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();


    //box(win, 103, 103); // (windowname, left&right char border, up&down char border)
    int left, right, top, bottom, tlc, trc, blc, brc;
    left=right=103;
    top=bottom=103;
    char c= '+';
    tlc=trc=brc=blc- (int)c;
    
    wborder(win, left, right, top, bottom, tlc, trc, blc, brc);


    mvwprintw(win, 1, 1, "this is my box");
    wrefresh(win);


    //waits for user input
    int x =getch();

    endwin();

    return 0;
}