/* Question 3
Write an efficient algorithm that searches for a value in a m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

// Time Complexity: O(log(M*N)) where M is rows of matrix and N is columns of matrix
// Space ComplexitY: O(1)

#include <bits/stdc++.h>
using namespace std;

// MARK:- Finding the target in the matrix
// DESC:- Using binary search for searching the target
bool isTargetPresent(vector<vector<int>> &matrix, int rows, int cols, int target)
{
    // Applying binary search
    int startIndex = 0, endIndex = matrix.size() * matrix[0].size() - 1, mid;
    while (startIndex < endIndex)
    {
        // [mid/rows] : correct row ; [mid%cols] : correct column in the matrix
        mid = startIndex + (endIndex - startIndex) / 2;
        if (matrix[mid / rows][mid % cols] == target)
            return true;
        else if (matrix[mid / rows][mid % cols] < target)
            startIndex = mid + 1;
        else
            endIndex = mid - 1;
    }

    return false;
}

int main()
{
    int rows;
    cout << "Enter the rows of the matrix: ";
    cin >> rows;

    int cols;
    cout << "Enter the columns of the matrix: ";
    cin >> cols;

    cout << "Enter the elements of the matrix " << endl;
    // Defining a matrix of n*n where n is the size of matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Taking the input of the elements of the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the target to be searched: ";
    cin >> target;

    if (isTargetPresent(matrix, rows, cols, target))
        cout << "Target element is present in the matrix!" << endl;
    else
        cout << "Target element is not present in the matrix!" << endl;

    return 0;
}