/* Question 3
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
*/

// Time Complexity:
// Space Complexity:

#include <bits/stdc++.h>
using namespace std;

void findMaxInWindowSize(vector<int> &values, int windowSize)
{
    unordered_map<int, int> freq;
    priority_queue<int> maxHeap;

    int leftPtr = 0, rightPtr = 0;

    while (rightPtr < values.size())
    {
        freq[values[rightPtr]]++;
        maxHeap.push(values[rightPtr]);
    }
}

int main()
{
    int sizeOfArray;
    cout << "Enter the size of the array";
    cin >> sizeOfArray;

    vector<int> elements;
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> elements[i];
    }

    int windowSize;
    cout << "Enter the window size";
    cin >> windowSize;

    cout << "The maximum values in each window of given size are: ";
    findMaxInWindowSize(elements, windowSize);
    return 0;
}