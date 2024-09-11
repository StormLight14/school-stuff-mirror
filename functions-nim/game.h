#ifndef GAME_H
#define GAME_H

bool isValidMove(int userMove, int stones);
void computerMove(int &stones);
void playerMove(int &stones);
bool checkWin(int stones);
int randomStonesAmount();

#endif
