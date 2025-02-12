#pragma once
#include<iostream>
using namespace std;

class Maze{

public:

void solve(){
    if(solve(startRow, startCol))
        cout << "Success" << endl;
    else
        cout << "Could not be solved." << endl;
}

// recursive method to solve the maze
bool solve(int curRow, int curCol){
    if (curRow == endRow && curCol == endCol) {
      maze[curRow][curCol] = '.';
      return true;
    }

    if (isEmpty(curRow, curCol)) {
      maze[curRow][curCol] = ' .';
      // below, above, left, right
      if (solve(curRow - 1, curCol) || solve(curRow + 1, curCol) || solve(curRow, curCol - 1) || solve(curRow, curCol + 1)) {
        return true;
      } else {
        maze[curRow][curCol] = ' '; // not correct path
        return false;
      }
    }

    return false;
}

// print the current state of the maze
void printMaze()
{
   // nested for loops to iterate through maze
   for ( int i = 0; i < 12; i++ )  {
      for ( int j = 0; j < 12; j++ )
			  cout << maze[ i ][ j ] << ' ';

      cout << '\n';
   } // end for
}

// determines if a location in the maze is empty
bool isEmpty(int r, int c){
    if(r >= 0 && c >= 0 && r < 12 && c < 12){
        if(maze[r][c] == ' ')
            return true;
    }
    return false;
}

private:
    int startRow = 2;
    int startCol = 0;
    int endRow = 4;
    int endCol = 11;
    // # is a wall, space is empty, . is the path
    char maze[ 12 ][ 12 ] =
      { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
      {  '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
      {  ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
      {  '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
      {  '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', ' '},
      {  '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {  '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {  '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
      {  '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
      {  '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
      {  '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
      {  '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };
};

