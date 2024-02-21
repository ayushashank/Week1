/* Question 1
Write a method Boolean isValidSudoku(int[][]Sudoku)
Returns true if the given Sudoku is correctly arranged otherwise false
Determine if a 9 x 9 The Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/

// Time Complexity: O(9*9*9)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<vector<char>> &board)
{
    for (int ind = 0; ind < board.size(); ind++)
    {
        // Checking the whole row for duplicate value
        if (ind != col and board[row][ind] == board[row][col])
            return false;

        // Checking the whole column for duplicate value
        if (ind != row and board[ind][col] == board[row][col])
            return false;

        // Checking the 3*3 smaller box for duplicate value
        if (ind != (3 * (row / 3) + ind / 3) and (col != 3 * (col / 3) + ind % 3) and board[3 * (row / 3) + ind / 3][3 * (col / 3) + ind % 3] == board[row][col])
            return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    // Traversing the board
    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board.size(); col++)
        {
            // if current charcter is a valid character then checking its validity
            if (board[row][col] >= '1' and board[row][col] <= '9')
            {
                if (isValid(row, col, board) == false)
                    return false;
            }
            else if (board[row][col] != '.')
                return false;
        }
    }

    return true;
}
int main()
{
    // 9*9 board of the sudoku
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '2', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '.', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    if (isValidSudoku(board))
    {
        cout << "It is a valid sudoku" << endl;
    }
    else
    {
        cout << "It is an invalid sudoku" << endl;
    }

    return 0;
}