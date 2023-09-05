#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Create a window
    WINDOW *win = newwin(10, 20, (LINES - 10) / 2, (COLS - 20) / 2);
    box(win, 0, 0); // Create a box around the window
    refresh();
    wrefresh(win);

    int
     ch;
    int row = 1, col = 1; // Initial position inside the box
    int selected_row = 1;

    while ((ch = getch()) != KEY_F(1)) { // Exit loop on F1 key press
        // Clear previous highlighting
        mvwchgat(win, selected_row, 1, -1, A_NORMAL, 0, NULL);

        // Handle arrow key inputs
        switch (ch) {
            case KEY_UP:
                if (selected_row > 1)
                    selected_row--;
                break;
            case KEY_DOWN:
                if (selected_row < 8)
                    selected_row++;
                break;
        }

        // Highlight the selected row
        mvwchgat(win, selected_row, 1, -1, A_REVERSE, 0, NULL);

        // Update the position and refresh the window
        wrefresh(win);
    }

    // Clean up and exit
    delwin(win);
    endwin();
    return 0;
}
