/*Asssignment - Make Mine Sweeper game on console in n*n with n bombs.*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class MineSweeperGame
{
private:
    int sizeOfBoard;
    int numOfBombs;
    bool gameOver;
    vector<vector<char>> mineSweeperBoard;
    // vector<vector<bool>> revealedCells;

public:
    // Constructor to assign all the values
    MineSweeperGame(int size)
    {
        sizeOfBoard = size;
        numOfBombs = size;
        gameOver = false;

        // Assigning the values to the board
        mineSweeperBoard.assign(sizeOfBoard, vector<char>(sizeOfBoard, '#'));
        // revealedCells.assign(sizeOfBoard, vector<bool>(sizeOfBoard, false));

        placeBombs();
    }

    // MARK:- Method to place all the bombs on the board randomly
    // DESC:- Using rand function to find out the positions of row and col and placing bomb there if it has not been already placed at that position
    void placeBombs()
    {
        // To avoid repeating values
        srand(time(0));

        int bombsPlaced = 0;
        while (bombsPlaced < numOfBombs) // Placing all the bombs i.e. 'numOfBombs' number of bombs
        {
            int currRow = rand() % sizeOfBoard; // Calculating the row randomly
            int currCol = rand() % sizeOfBoard; // Calculating the column randomly

            // Placing the bomb if it is an empty cell
            if (mineSweeperBoard[currRow][currCol] != 'B')
            {
                mineSweeperBoard[currRow][currCol] = 'B';
                bombsPlaced++;
            }
        }
    }

    // MARK:- Method to display all the visited cells
    // DESC:- Displaying all the visited cells otherwise displaying '#' to imply this cell is not visited yet
    void displayMineSweeperBoard()
    {
        cout << endl;
        for (int currRow = 0; currRow < sizeOfBoard; currRow++)
        {
            for (int currCol = 0; currCol < sizeOfBoard; currCol++)
            {
                // if (revealedCells[currRow][currCol] == true)
                // {
                //     cout << mineSweeperBoard[currRow][currCol] << " ";
                // }
                // else
                // {
                //     cout << "# ";
                // }
                if (mineSweeperBoard[currRow][currCol] == 'B')
                {
                    cout << "# ";
                }
                else
                {
                    cout << mineSweeperBoard[currRow][currCol] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    // MARK:- Method to check whether the cell is valid
    // DESC:- Checking if the cell is within the bounds and has not been visited already
    bool isMoveValid(int row, int col)
    {
        if (row >= 0 and row < sizeOfBoard and col >= 0 and col < sizeOfBoard and
            (mineSweeperBoard[row][col] == '#' or mineSweeperBoard[row][col] == 'B'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // MARK:- Method to reveal/display the cell if it is valid and not a bomb
    // DESC:- Checking if the current cell opened by the player is inside the bounds and it is not a bomb
    void revealCell(int row, int col)
    {
        if (isMoveValid(row, col) == false)
        {
            cout << "Invalid move! Please try again!" << endl;
            return;
        }

        // If the cell has a bomb then it the player has lost.
        if (mineSweeperBoard[row][col] == 'B')
        {
            gameOver = true;
            cout << "Game Over! You found a bomb!" << endl;
        }
        else
        {
            // Marking the cell as visited
            // revealedCells[row][col] = true;

            mineSweeperBoard[row][col] = 'S';

            // Checking if the player has won
            if (checkWin() == true)
            {
                gameOver = true;
                cout << "Congratulations! You have completed the game.\n";
            }
        }
    }

    // MARK:- Method to check whether the player has won the game
    // DESC:- Checking if all cells which do not have bombs are visited or not, if they are, then the player has won
    bool checkWin()
    {
        for (int currRow = 0; currRow < sizeOfBoard; currRow++)
        {
            for (int currCol = 0; currCol < sizeOfBoard; currCol++)
            {
                // revealedCells[currRow][currCol] == false
                if (mineSweeperBoard[currRow][currCol] == '#' and mineSweeperBoard[currRow][currCol] != 'B')
                {
                    return false;
                }
            }
        }
        return true;
    }

    // MARK:- Method to check whether the game has ended or not
    // DESC:- If the gameOver variable is marked true i.e. gave has ended otherwise it is still ongoing
    bool isGameOver()
    {
        if (gameOver == true)
            return true;
        else
            return false;
    }

    // MARK:- Method to display the complete board
    // DESC:- Displaying each cell of the board
    void displayCompleteMineSweeperBoard()
    {
        for (int currRow = 0; currRow < sizeOfBoard; currRow++)
        {
            for (int currCol = 0; currCol < sizeOfBoard; currCol++)
            {
                if (mineSweeperBoard[currRow][currCol] == '#')
                {
                    cout << "S ";
                }

                else
                {
                    cout << mineSweeperBoard[currRow][currCol] << " ";
                }
            }
            cout << endl;
        }
    }
};

// MARK:- Function to check whether the input is a number or not
// DESC:- Checking each character of the string if it is a number or not
bool isValidNumber(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < '0' or str[i] > '9')
            return false; // if a character is not a digit then returning false
    }
    return true;
}

int main()
{
    string boardSize;
    cout << "Enter size of the Minesweeper board (n * n): ";
    cin >> boardSize;

    // If the input is a number then only executing the game
    if (isValidNumber(boardSize))
    {
        if (stoi(boardSize) > 1 and stoi(boardSize) <= 10) // Limiting the size of the board
        {
            MineSweeperGame game(stoi(boardSize)); // Making an object

            // To check the positions of bomb
            cout << "\nThe complete board is shown below (S - Safe Positions     B - Bomb Positions)" << endl;
            game.displayCompleteMineSweeperBoard();

            // Executing the game until a bomb is encountered or the game is completed
            while (game.isGameOver() == false)
            {
                game.displayMineSweeperBoard();
                string row, col;
                cout << "Enter the row and column of the cell you want to reveal: ";
                cin >> row >> col;

                if (isValidNumber(row) and isValidNumber(col))
                {
                    game.revealCell(stoi(row), stoi(col));
                }
                else
                {
                    cout << "Invalid input! Please enter correct values!" << endl;
                }
            }

            // Displaying the complete board after the game ends
            cout << "\nThe complete board is shown below (S - Safe Positions   B - Bomb Positions)" << endl;
            game.displayCompleteMineSweeperBoard();
        }
        else
        {
            cout << "Invalid size! Please restart the game!" << endl;
        }
    }
    else
    {
        cout << "Invalid input! Please restart the game!" << endl;
    }

    return 0;
}