/* Question 4
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are surrounded by water.
*/

// Time Complexity: O(M*N) where M is rows of matrix and N is columns of matrix
// Space Comlexity: O(M*N) where M is rows of matrix and N is columns of matrix

#include <bits/stdc++.h>
using namespace std;

// MARK:- Does the depth-first traversl in the given matrix
// DESC:- Visits all the elements in the all four directions and marks them true if they are valid and equal to 1
void dfsTraversal(int row, int col, vector<vector<int>> &matrix, vector<vector<bool>> &vis)
{
    // base case
    if (row < 0 or row >= matrix.size() or col < 0 or col >= matrix[0].size() or matrix[row][col] == 0 or vis[row][col] == true)
        return;

    vis[row][col] = true;

    // upwards
    dfsTraversal(row - 1, col, matrix, vis);

    // downwards
    dfsTraversal(row + 1, col, matrix, vis);

    // leftwards
    dfsTraversal(row, col - 1, matrix, vis);

    // rightwards
    dfsTraversal(row, col + 1, matrix, vis);
}

// MARK:- Calls the dfsTraversal method and returns the valid number of islands
// DESC:- If the current element has not been visited and it is 1, then calls the dfsTraversal method and increments the number of island by 1
int findIslands(vector<vector<int>> &matrix, int rows, int cols)
{
    vector<vector<bool>> visitedElements(rows, vector<bool>(cols, false));
    int numOfIslands = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (visitedElements[i][j] == false and matrix[i][j] == 1)
            {
                dfsTraversal(i, j, matrix, visitedElements);
                numOfIslands++;
            }
        }
    }
    return numOfIslands;
}

int main()
{
    int rows;
    cout << "Enter the rows of matrix: ";
    cin >> rows;

    int cols;
    cout << "Enter the columns of matrix: ";
    cin >> cols;

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

        cout << "The number of islands are: " << findIslands(matrix, rows, cols);
    }
    return 0;
}