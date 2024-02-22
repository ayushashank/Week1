/*
Question 1
Write a method void printArray(int[][]arr)
Prints array elements clockwise and anti-clockwise alternatively.
Input :
 1 2 3
 4 5 6
 7 8 9
Output :
1 2 3 6 9 8 7 4 5
3 2 1 4 7 8 9 6 5
*/

// Time Complexity: O(M*N) where M is rows of matrix and N is columns of matrix
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

// MARK:- Function to print clockwise spiral matrix
// DESC:- Prints the first row, then last column, then last row, then first column
void clockwiseTraversal(vector<vector<int>> &matrix)
{
    int rowStart = 0, rowEnd = matrix.size() - 1;
    int colStart = 0, colEnd = matrix[0].size() - 1;

    // Maintaing a count and running the loop till count is less than total elements
    int totalElements = (matrix.size()) * (matrix[0].size());
    int count = 0;
    cout << "\nThe clockwise traversal of the matrix is" << endl;
    while (count < totalElements)
    {
        // Printing the first row
        for (int col = colStart; col <= colEnd and count < totalElements; col++)
        {
            cout << matrix[rowStart][col] << " ";
            count++;
        }
        rowStart++;

        // Printing the last column
        for (int row = rowStart; row <= rowEnd and count < totalElements; row++)
        {
            cout << matrix[row][colEnd] << " ";
            count++;
        }
        colEnd--;

        // Printing the last row
        for (int col = colEnd; col >= colStart and count < totalElements; col--)
        {
            cout << matrix[rowEnd][col] << " ";
            count++;
        }
        rowEnd--;

        // Printing the first column
        for (int row = rowEnd; row >= rowStart and count < totalElements; row--)
        {
            cout << matrix[row][colStart] << " ";
            count++;
        }
        colStart++;
    }
    cout << endl;
}

// MARK:- Function to print anti-clockwise spiral matrix
// DESC:- Prints the first row, then last column, then last row, then first column
void antiClockwiseTraversal(vector<vector<int>> &matrix)
{
    int rowStart = 0, rowEnd = matrix.size() - 1;
    int colStart = 0, colEnd = matrix[0].size() - 1;

    // Maintaing a count and running the loop till count is less than total elements
    int totalElements = (matrix.size()) * (matrix[0].size());
    int count = 0;

    cout << "\nThe anti-clockwise traversal of the matrix is" << endl;
    while (count < totalElements)
    {
        // Printing the first row
        for (int col = colEnd; col >= colStart and count < totalElements; col--)
        {
            cout << matrix[rowStart][col] << " ";
            count++;
        }
        rowStart++;

        // Printing the first column
        for (int row = rowStart; row <= rowEnd and count < totalElements; row++)
        {
            cout << matrix[row][colStart] << " ";
            count++;
        }
        colStart++;

        // Printing the last row
        for (int col = colStart; col <= colEnd and count < totalElements; col++)
        {
            cout << matrix[rowEnd][col] << " ";
            count++;
        }
        rowEnd--;

        // Printing the last column
        for (int row = rowEnd; row >= rowStart and count < totalElements; row--)
        {
            cout << matrix[row][colEnd] << " ";
            count++;
        }
        colEnd--;
    }
    cout << endl;
}

int main()
{
    int rows;
    cout << "Enter the rows of matrix: ";
    cin >> rows;

    int cols;
    cout << "Enter the columns of matrix: ";
    cin >> cols;

    // If dimension of matrix are not valid, then executing the function
    if (!(rows > 0 and cols > 0))
        cout << "Invalid dimensions!" << endl;
    else
    {
        vector<vector<int>> matrix(rows, vector<int>(cols));
        cout << "Enter the elements of the matrix" << endl;
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                cin >> matrix[row][col];
            }
        }

        clockwiseTraversal(matrix);
        antiClockwiseTraversal(matrix);
    }
    return 0;
}
