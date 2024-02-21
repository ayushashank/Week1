/* Question 5
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

// Time Complexity: O(N*N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void transposeOfMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            // swapping the (i,j) and (j,i) elements
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void reverseEachRow(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        int startIndex = 0, endIndex = matrix.size() - 1;
        while (startIndex < endIndex)
        {
            swap(matrix[i][startIndex], matrix[i][endIndex]);
            startIndex++;
            endIndex--;
        }
    }
}

void printMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int sizeOfMatrix;
    cout << "Enter the size of the matrix ";
    cin >> sizeOfMatrix;

    cout << "Enter the elements of the matrix " << endl;
    // Defining a matrix of n*n where n is the size of matrix
    vector<vector<int>> matrix(sizeOfMatrix, vector<int>(sizeOfMatrix));

    // Taking the input of the elements of the matrix
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // Taking the transpose of the matrix
    transposeOfMatrix(matrix);

    // Reversing each row of the matrix
    reverseEachRow(matrix);

    // Printing the elemets after rotation
    cout << "\nMatrix after rotating 90 degrees clockwise is:" << endl;
    printMatrix(matrix);
    return 0;
}