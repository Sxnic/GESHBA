#ifndef _DEFINED_CURSES

#include<panel.h>
#include<ncurses.h>

#define _DEFINED_CURSES
#endif

WINDOW* mkwin(WINDOW*& win, int h, int l, int y, int x, bool border) {
    // Make the panel
    WINDOW* rxwin = newwin(h, l ,y, x);
    if(border)
        box(rxwin, 0, 0);
    // PANEL* pa = new_panel(rxwin);
    wrefresh(rxwin);
    return rxwin;
}

PANEL* mkpanel(WINDOW*& w) {
    PANEL* pa = new_panel(w);
    update_panels();
    return pa;
}