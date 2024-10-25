#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(
  int row, int col, 
  int row_moves[], int col_moves[],
  int& num_moves) {

    // all the possible moves that a knight can make
    int move_row[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int move_col[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // sets the number of moves to 0
    num_moves = 0;

    // iterates though all of the possible moves 
    for (int i = 0; i < 8; i++) {
        int new_row = row + move_row[i];
        int new_col = col + move_col[i];

        // check to see if the move hasnt been done before and is withing the bounds of the board
        if (new_row >= 0 && new_row < board_size && new_col >= 0 && new_col < board_size && this->board[new_row][new_col] == 0) {
            row_moves[num_moves] = new_row;
            col_moves[num_moves] = new_col;
            num_moves++;
        }
    }
}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours) {
    // Mark the current position with m
    this->board[row][col] = ++m;

    // if the number of moves is the max amount of the board then 
    //add to the number of tours and print the board
    if (m == board_size * board_size) {
        num_tours++;  
        print(); 
    } else {
        // Array to hold valid move positions
        int row_moves[8], col_moves[8], num_moves = 0;

        // Get all valid moves from the current position
        get_moves(row, col, row_moves, col_moves, num_moves);

        // Try's each valid move
        for (int i = 0; i < num_moves; i++) {
            move(row_moves[i], col_moves[i], m, num_tours);
        }
    }

    // Backtrack: Unmark this position (reset it to 0)
    this->board[row][col] = 0;
    m--;  // Decrease the number of moves
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}
