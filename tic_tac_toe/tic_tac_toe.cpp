#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_board(const vector<vector<char>>& board) {
        for (const auto& row : board) {
              for (char cell : row) {
            cout << cell << " | ";
        }
            cout << endl;
             cout << "---------" << endl;
    }
}

bool check_win(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if 
         ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
           
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    
    if 
        ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
       
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool check_draw(const vector<vector<char>>& board) {
      for (const auto& row : board) {
      for (char cell : row) {
              if (cell == ' ') {
                   return false;
            }
        }
    }
      return true;
}

int main() {
       vector<vector<char>> board(3, vector<char>(3, ' '));
           char currentPlayer = 'X';
           bool game_over = false;

                    while (!game_over) {
        
                     print_board(board);

    
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row col): ";
        cin >> row >> col;

        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            
            if (check_win(board, currentPlayer)) {
                   print_board(board);
                   cout << "Player " << currentPlayer << " wins!" << endl;
                game_over = true;
            }
            
            else if (check_draw(board)) {
                   print_board(board);
                   cout << "It's a draw!" << endl;
                game_over = true;
            }
            
            else 
            {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else 
        
        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y')
     {
        main();
    } else 
    {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}
