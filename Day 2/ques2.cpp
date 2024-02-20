/* Question 2
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold. If no three numbers sum up to the target sum, the function should return an empty array.
Ex:
target_sum = 6
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
result = [[1, 2, 3]]*/

// Time Complexity: O(N*N)
// Space Complexity: O(logN)

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &arr, int start, int end)
{

    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

vector<vector<int>> findTriplets(vector<int> &nums, int target)
{

    vector<vector<int>> res;

    // sort(nums.begin(), nums.end());

    // Using quick sort to sort the array
    quickSort(nums, 0, nums.size() - 1);

    // Checking if triplets exist
    for (int i = 0; i < nums.size() - 2; i++)
    {
        // using two pointers to check if sum == target-(current element)
        int start = i + 1, end = nums.size() - 1;

        // if starting element is greater than target-(current element), then there will not be any triplet satisfying the condition
        if (nums[start] > target - nums[i])
            break;

        while (start < end)
        {
            // if sum is equal to target-(current element), pushing it into the result
            if (nums[start] + nums[end] == target - nums[i])
            {
                res.push_back({nums[i], nums[start], nums[end]});
                start++;
                end--;
            }
            // if sum is less than target-(current element), incrementing the starting pointer
            else if (nums[start] + nums[end] < target - nums[i])
            {
                start++;
            }
            // if sum is greater than target-(current element), decrementing the ending pointer
            else
                end--;
        }
    }

    return res;
}

int main()
{

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums;
    cout << "Enter the numbers: ";
    int val;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        nums.push_back(val);
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> triplets = findTriplets(nums, target);

    // Printing all the triplets that sum up to the target
    if (triplets.size() == 0)
    {
        cout << "There are no triplets whos sum is equal to target" << endl;
    }
    else
    {
        cout << "The triplets whose sum is equal to target are: ";
        for (int i = 0; i < triplets.size(); i++)
        {
            cout << "{" << triplets[i][0] << "," << triplets[i][1] << "," << triplets[i][2] << "} ";
        }
    }

    return 0;
}
