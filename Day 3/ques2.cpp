/* Question 2
Write a method Boolean isKingSafe(int[][]chessBoard)
Returns true if king in the given chess board is safe from the given enemies otherwise false;
NOTE: Enemies are- Horse, Camel, Queen, Elephant only
Do not consider the colour case of the chess board for traversal of camel and all.
*/

// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int kingRow, kingCol, horseRow, horseCol, camelRow, camelCol, queenRow, queenCol, elephantRow, elephantCol;

bool isKingSafeFromHorse()
{
    // Upper left position 1
    if ((horseRow - 2 >= 0 and horseCol - 1 >= 0) and (horseRow - 2 == kingRow and horseCol - 1 == kingCol))
        return false;
    // Upper right position 1
    else if ((horseRow - 2 >= 0 and horseCol + 1 < 8) and (horseRow - 2 == kingRow and horseCol + 1 == kingCol))
        return false;
    // Lower left position 1
    else if ((horseRow + 2 < 8 and horseCol - 1 >= 0) and (horseRow + 2 == kingRow and horseCol - 1 == kingCol))
        return false;
    // Lower right position 1
    else if ((horseRow + 2 < 8 and horseCol + 1 < 8) and (horseRow + 2 == kingRow and horseCol + 1 == kingCol))
        return false;

    // Upper left position 2
    else if ((horseRow - 1 >= 0 and horseCol - 2 >= 0) and (horseRow - 1 == kingRow and horseCol - 2 == kingCol))
        return false;
    // Upper right position 2
    else if ((horseRow - 1 >= 0 and horseCol + 2 < 8) and (horseRow - 1 == kingRow and horseCol + 2 == kingCol))
        return false;
    // Lower left position 2
    else if ((horseRow + 1 < 8 and horseCol - 2 >= 0) and (horseRow - 1 == kingRow and horseCol + 2 == kingCol))
        return false;
    // Lower right position
    else if ((horseRow + 1 < 8 and horseCol + 2 < 8) and (horseRow + 1 == kingRow and horseCol + 2 == kingCol))
        return false;
    else
        return true;
}

bool isKingSafeFromCamel(int rowCamel, int colCamel)
{

    // Checking for upper left diagonal
    for (int currRow = rowCamel, currCol = colCamel; currRow >= 0 and colCamel >= 0; currRow--, currCol--)
    {
        if ((currRow == horseRow and currCol == horseCol) or (currRow == elephantRow and currCol == elephantCol))
            break;
        if (currRow == kingRow and currCol == kingCol)
            return false;
    }
    // Checking for lower left diagonal
    for (int currRow = rowCamel, currCol = colCamel; currRow < 8 and colCamel >= 0; currRow++, currCol--)
    {
        if ((currRow == horseRow and currCol == horseCol) or (currRow == elephantRow and currCol == elephantCol))
            break;
        if (currRow == kingRow and currCol == kingCol)
            return false;
    }

    // Checking for upper right diagonal
    for (int currRow = rowCamel, currCol = colCamel; currRow >= 0 and colCamel < 8; currRow--, currCol++)
    {
        if ((currRow == horseRow and currCol == horseCol) or (currRow == elephantRow and currCol == elephantCol))
            break;
        if (currRow == kingRow and currCol == kingCol)
            return false;
    }
    // Checking for lower right diagonal
    for (int currRow = rowCamel, currCol = colCamel; currRow < 8 and colCamel < 8; currRow++, currCol++)
    {
        if ((currRow == horseRow and currCol == horseCol) or (currRow == elephantRow and currCol == elephantCol))
            break;
        if (currRow == kingRow and currCol == kingCol)
            return false;
    }

    return true;
}

bool isKingSafeFromElephant(int rowElephant, int colElephant)
{

    // Checking for the column
    if (colElephant == kingCol)
    {
        // checking the lower column
        for (int currRow = rowElephant; currRow < 8; currRow++)
        {
            // Another piece is in between king and elephant
            if ((currRow == horseRow and colElephant == horseCol) or (currRow == camelRow and colElephant == camelCol))
                break;
            if (currRow == kingRow)
                return false;
        }

        // checking the upper column
        for (int currRow = rowElephant; currRow >= 0; currRow--)
        {
            // Another piece is in between king and elephant
            if ((currRow == horseRow and colElephant == horseCol) or (currRow == camelRow and colElephant == camelCol))
                break;

            if (currRow == kingRow)
                return false;
        }
    }

    // Checking for the row
    if (rowElephant == kingRow)
    {
        // checking the left row
        for (int currCol = colElephant; currCol >= 0; currCol--)
        {
            if ((rowElephant == horseRow and currCol == horseCol) or (rowElephant == camelRow and currCol == camelCol))
                break;

            if (currCol == kingCol)
                return false;
        }

        // checking the right row
        for (int currCol = colElephant; currCol < 8; currCol++)
        {
            if ((rowElephant == horseRow and currCol == horseCol) or (rowElephant == camelRow and currCol == camelCol))
                break;

            if (currCol == kingCol)
                return false;
        }
    }

    return true;
}

bool isKingSafeFromQueen()
{
    // Checking both the conditions of elephant and camel for the coordinates of queen
    if (isKingSafeFromCamel(queenRow, queenCol) and isKingSafeFromElephant(queenRow, queenCol))
        return true;

    return false;
}

int main()
{

    cout << "Enter the position of the King (row, column) ";
    cin >> kingRow >> kingCol;

    cout << "Enter the position of the Horse (row, column) ";
    cin >> horseRow >> horseCol;

    cout << "Enter the position of the Camel (row, column) ";
    cin >> camelRow >> camelCol;

    cout << "Enter the position of the Queen (row, column) ";
    cin >> queenRow >> queenCol;

    cout << "Enter the position of the Elephant (row, column) ";
    cin >> elephantRow >> elephantCol;

    // Checking for the Horse
    bool isSafeFromHorse = true;
    if (horseCol >= 8 or horseCol < 0 or horseRow >= 8 or horseRow < 0)
        cout << "Invalid position for the horse." << endl;
    else
        isSafeFromHorse = isKingSafeFromHorse();

    // Checking for the Camel
    bool isSafeFromCamel = true;
    if (camelRow >= 8 or camelRow < 0 or camelCol >= 8 or camelCol < 0)
        cout << "Invalid position for the camel." << endl;
    else
        isSafeFromCamel = isKingSafeFromCamel(camelRow, camelCol);

    // Checking for the Elephant
    bool isSafeFromElephant = true;
    if (elephantRow >= 8 or elephantRow < 0 or elephantCol >= 8 or elephantCol < 0)
        cout << "Invalid position for the elephant." << endl;
    else
        isSafeFromElephant = isKingSafeFromElephant(elephantRow, elephantCol);

    // Checking for Queen
    bool isSafeFromQueen = true;
    if (queenRow >= 8 or queenRow < 0 or queenCol >= 8 or queenCol < 0)
        cout << "Invalid position for the queen." << endl;
    else
        isSafeFromQueen = isKingSafeFromQueen();

    // Checking if king is safe from all the pieces
    if (isSafeFromCamel and isSafeFromElephant and isSafeFromHorse and isSafeFromQueen)
        cout << "King is safe!" << endl;
    else
        cout << "King is unsafe!" << endl;
    return 0;
}