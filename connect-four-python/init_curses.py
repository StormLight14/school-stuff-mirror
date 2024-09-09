import curses

def init_curses():
    stdscr = curses.initscr() # setup terminal TUI settings
    curses.cbreak() # get stdin input instantly, without user pressing enter
    curses.start_color()
    curses.use_default_colors()
    
    curses.noecho() # don't echo entered input in terminal
    curses.curs_set(0) # don't show cursor
    stdscr.keypad(True) # handle escape sequences
    
    curses.init_pair(1, curses.COLOR_BLUE, curses.COLOR_BLACK) # player 1 colors
    curses.init_pair(2, curses.COLOR_RED, curses.COLOR_BLACK) # player 2 colors
    curses.init_pair(3, -1, curses.COLOR_BLACK) # bg color
    
    stdscr.bkgd(" ", curses.color_pair(3)) # fill bg with black
    return stdscr
