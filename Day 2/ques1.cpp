/* Question 1
Write a program to remove duplicate values from an array and returns an array of unique values. int[] removeDuplicates(int[]values)
Ex:
values = [2, 4, 6, 2, 8, 10, 4, 12, 14, 6]
result = [2, 4, 6, 8, 10, 12, 14]
*/
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> &values)
{
    // map for storing the occurance of a number
    unordered_map<int, bool> uniqueVals;

    // inserting each number in the map
    for (int i = 0; i < values.size(); i++)
    {
        if(uniqueVals.find(values[i]) != uniqueVals.end()){

        }
        uniqueVals[values[i]] = true;

    }

    // values = {};

    // // storing the unique values in the array
    // vector<int> result;
    // for (auto val : uniqueVals)
    // {
    //     values.push_back(val.first);
    // }

    // return values;
}

int main()
{
    vector<int> values;

    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Enter the values: ";
    int val;

    // taking input of all the values
    while (size > 0)
    {
        cin >> val;
        values.push_back(val);
        size--;
    }

    vector<int> uniqueValues = removeDuplicates(values);

    // displaying all the unique values
    cout << "The unique values are: ";
    for (int i = 0; i < uniqueValues.size(); i++)
    {
        cout << uniqueValues[i] << " ";
    }

    return 0;
}
