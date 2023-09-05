#include <ncurses.h>

int main() {
    initscr();
    keypad(stdscr, TRUE);

    // Create a window for the menu
    WINDOW *menu_win = newwin( 6, 40, 5, 5);
    box(menu_win, 0, 0);    
    refresh();
    wrefresh(menu_win);

    char *choices[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit"
    };
    int choice;
    int highlight = 0;

    while (1) {
        int ch = getch();
        if (ch == KEY_UP) {
            printw("Up arrow key pressed\n");
        } else if (ch == KEY_DOWN) {
            printw("Down arrow key pressed\n");
        } else if (ch == 'q') {
            break;
        }
        refresh();
    }

    endwin();
    return 0;
}
