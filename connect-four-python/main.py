import time
import os
import curses
import init_curses
# (char, color pair)
piece_one = ("◉", 1) 
piece_two = ("◉", 2) 
empty_slot = ("▿", 3)

# delay in seconds for piece to fall to next slot
fall_delay = 0.05

#Function that returns 0 if no one wins, 1 if player 1 wins, 2 if player 2 wins
def check(board):
    for row in board:
        for col in range(len(row)):
            if col < 4: #3 or more to the right
                current_piece = row[col]
                #Check if 3 pieces to the right are all the same as current piece
                if row[col + 1] == current_piece and row[col + 2] == current_piece and row[col + 3] == current_piece:
                    if current_piece == piece_one:
                        return 1
                    elif current_piece == piece_two:
                        return 2
    for row in range(len(board)):
        for col,piece in enumerate(board[row]):
            if row < 3: #3 or more downward
                current_piece = piece
                #Check if 3 pieces down are the same as current_piece
                if board[row + 1][col] == current_piece and board[row + 2][col] == current_piece and board[row + 3][col] == current_piece:
                    if current_piece == piece_one:
                        return 1
                    elif current_piece == piece_two:
                        return 2
    for row in range(len(board)):
        for col,piece in enumerate(board[row]):
            if row < 3 and col < 4: #3 or more downward and 3 more rightward
                current_piece = piece
                #Check if pieces diagonal (upward, are all equal to current_piece
                if board[row + 1][col + 1] == current_piece and board[row + 2][col + 2] == current_piece and board[row + 3][col + 3] == current_piece:
                    if current_piece == piece_one:
                        return 1
                    elif current_piece == piece_two:
                        return 2
    for row in range(len(board)):
        for col,piece in enumerate(board[row]):
            if row > 3 and col < 4: #3 more upward and 3 more rightward
                current_piece = piece
                #Check if row[col + 1], row[col + 2], row[col + 3] are all equal to current_piece
                if board[row - 1][col + 1] == current_piece and board[row - 2][col + 2] == current_piece and board[row - 3][col + 3] == current_piece:
                    if current_piece == piece_one:
                        return 1
                    elif current_piece == piece_two:
                        return 2
     

def place_piece(board):
    global selected_col
    
    # gets currently pressed character
    ch = stdscr.getch()

    if selected_col > 0 and (ch == 97 or ch == 260): # A key or left arrow key
        selected_col -= 1
        print_board(board)
    elif selected_col < 6 and (ch == 100 or ch == 261): # D key or right arrow key
        selected_col += 1
        print_board(board)
    elif ch == 32 or ch == 115 or ch == 258: # space key, S key, or down key
        if board[0][selected_col] == empty_slot: # the top slot is empty
            if current_turn == 1:
                board[0][selected_col] = piece_one
            else:
                board[0][selected_col] = piece_two
                
            stdscr.refresh()
            print_board(board)
            time.sleep(fall_delay)
            
            for row in range(6):
                if row < 5:
                    # places piece and creates animation effect
                    piece = piece_one
                    if current_turn == 2:
                        piece = piece_two
                        
                    if board[row][selected_col] == piece and board[row + 1][selected_col] == empty_slot:
                        board[row][selected_col] = empty_slot
                        board[row + 1][selected_col] = piece
                        
                        stdscr.refresh()
                        print_board(board)
                        time.sleep(fall_delay)
                
            change_turn()
            print_board(board)
        
    # debugging to find char numbers
    # stdscr.addstr(f"You pressed {chr(ch)} || {ch}\n")

def change_turn():
    global current_turn
    if current_turn == 1:
        current_turn = 2
    else:
        current_turn = 1

def print_board(board):
    stdscr.clear() # clear terminal output
    # stdscr.addstr is more or less the same as print(), but you have to specify newlines at the end.
    stdscr.addstr(f"It is player {current_turn}'s turn.\n\n", curses.A_BOLD | curses.color_pair(current_turn)) # print the selected column.
    stdscr.addstr("╭ ")
    for col in range(7):
        if col > 0:
            stdscr.addstr(" ")
        if col == selected_col:
            stdscr.addstr(str(col + 1), curses.A_BOLD | curses.color_pair(current_turn))
        else:
            stdscr.addstr(str(col + 1))
        if col < 6:
            stdscr.addstr(" ")
    stdscr.addstr(" ╮\n")
    
    for row in board:
        stdscr.addstr("│ ")
        for col in range(7):
            if col > 0:
                stdscr.addstr(" ")
            if row[col] == empty_slot:
                stdscr.addstr(empty_slot[0], curses.A_BOLD | curses.color_pair(empty_slot[1]))
            else:
                stdscr.addstr(row[col][0], curses.color_pair(row[col][1]))
            if col < 6:
                stdscr.addstr(" ")
        stdscr.addstr(" │\n")
    stdscr.addstr("╰─────────────────────╯\n")
# 7 columns x 6 rows 
    
def pieces():
    board = []
    for i in range(6):
        board.append([empty_slot, empty_slot, empty_slot, empty_slot, empty_slot, empty_slot, empty_slot])
    return board
    
board = pieces()

selected_col = 0
current_turn = 1 # player 1 or player 2

stdscr = init_curses.init_curses()

print_board(board)
while True:
    place_piece(board)
    board_check = check(board)
    if board_check:
        stdscr.addstr(f"Player {board_check} has won!", curses.A_BOLD | curses.color_pair(board_check))
        stdscr.refresh()
        break
