#ifndef _DEFINED_CURSES

#include<panel.h>
#include<ncurses.h>

#define _DEFINED_CURSES
#endif

#ifndef _MCLASSES

#include<iostream>
#include<vector>
#include<math.h>

#define _MCLASSES
#endif

WINDOW* mkwin(WINDOW*& win, int h, int l, int y, int x, bool border);
PANEL* mkpanel(WINDOW*& w);

int main(int argc, char** argv) {
    // Init Window
    int my, mx;

    initscr();
    getmaxyx(stdscr, my, mx);
    curs_set(0);

    // Start the coloring
    start_color();

    // mvprintw(0, 0, "Window size: %d x %d", mx, my);
    refresh();

    int hoffset = 1;
    int woffset = 2;
    int vph = floor(my/2)-1;
    int vphrem = floor(my%2);
    int& vpl = mx;

    // mvprintw(1, 0, "Window offsets: %d [%d]", vph, vphrem);

    // Initialize windows

    WINDOW* win1 = mkwin(stdscr, vph, mx, hoffset, 0, true);
    PANEL* p1 = mkpanel(win1);
    mvwprintw(win1, 1, 1, "Window 1");
    wrefresh(win1);
    update_panels();

    WINDOW* win2 = mkwin(stdscr, vph + vphrem, mx, vph+1, 0, true);
    PANEL* p2 = mkpanel(win1);
    mvwprintw(win2, 1, 1, "Window 2");
    wrefresh(win2);
    update_panels();
    
    // Add top panel

    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    std::vector<std::string> options = {
        "File", "Command", "View", "Options", "Other"
    };

    WINDOW* hwin1 = mkwin(stdscr, 1, mx, 0, 0, false);
    PANEL* hp1 = mkpanel(hwin1);
    wrefresh(hwin1);
    update_panels();

    int wss = 2;
    static int clen = 0;

    for(auto x : options) {
        wattron(hwin1, COLOR_PAIR(1));
        
        mvwprintw(hwin1, 0, clen, " %s ", x.c_str());
        wrefresh(hwin1);
        wattroff(hwin1, COLOR_PAIR(1));

        // int wcw = wcwidth(x.c_str())
        clen = clen + (x.length() + wss);
    }

    // Fill the empty space

    wattron(hwin1, COLOR_PAIR(1));
    std::string filler;
    std::fill(filler.begin(), filler.begin()+(mx-clen), ' ');
    mvwprintw(hwin1, 0, clen, filler.c_str());
    wrefresh(hwin1);
    wattroff(hwin1, COLOR_PAIR(1));

    // Add bottom panel

    std::vector<std::string> bottom_opts = {
        "Help", "Menu", "Select", "Home", "", "", "", "", "Smtn", "Quit"
    };

    // End window
    

    getch();
    curs_set(1);
    endwin();

    return 0;
}