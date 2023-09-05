#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // Enable special keys like arrow keys

    // Create a window for the menu
    WINDOW *menu_win = newwin( 6, 40, 5, 5);
    box(menu_win, 0, 0);    
    refresh();
    wrefresh(menu_win);

    // Define menu options
    char *choices[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit"
    };
    int choice;
    int highlight = 0;

    // Display the menu
    while ((choice = getch()) != KEY_F(1)) {
        for (int i = 0; i < 4; i++) {
            if (highlight == i ){
                wattron(menu_win, A_REVERSE);
            }
            mvwprintw(menu_win, i + 1, 1, choices[i]);
            wattroff(menu_win, A_REVERSE);
            wrefresh(menu_win);
        }
        choice = wgetch(menu_win);

        switch (choice) {
            case KEY_UP:
                highlight=2;
                break;
            case KEY_DOWN:
                highlight=4;
                break;
            default:
                break;
        }

        if (choice == 10) // Enter key
            break;
    }

    // Display a dialog box with the selected option
    clear();
    mvprintw(10, 2, "You chose: %s", choices[highlight]);
    refresh();
    getch();

    // Clean up and exit
    delwin(menu_win);
    endwin();
    return 0;
}
