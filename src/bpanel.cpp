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

WINDOW* gen_bottompannel(WINDOW*& win, std::vector<std::string>& listitems) {
    static int wx, wy;
    getmaxyx(win, wy, wx);

    // Generate the window under the screen
    WINDOW* bwin = mkwin(stdscr, 1, wx, wy-1, 0, false);
    PANEL* bp1 = mkpanel(bwin);
    wrefresh(bwin);
    update_panels();

    // Get width for 1
    static int psize = floor(wx/listitems.size());
    static int psizer = floor(wx%listitems.size());

    static int crlen = 0;

    
}