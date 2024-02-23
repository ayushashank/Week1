/* Question 3
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
*/

// Time Complexity: O(NlogN)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

// MARK:- Function to print the maximum value from the window
// DESC:- Using map and priority queue to find the maximum element in each window size, when a window size is achieved then printing the top element if its frequency is greater than 0
void findMaxInWindowSize(vector<int> &values, int &windowSize)
{
    // Using map and priority queue to store the elements
    unordered_map<int, int> freq;
    priority_queue<int> maxHeap;

    int leftPtr = 0, rightPtr = 0;

    while (rightPtr < values.size())
    {
        // adding the current element in the map and priority queue
        freq[values[rightPtr]]++;
        maxHeap.push(values[rightPtr]);

        if (rightPtr - leftPtr + 1 == windowSize)
        {
            // if frequency of top element is less than 1 then removing it from the max heap
            int maxVal = maxHeap.top();
            while (!maxHeap.empty() and freq[maxVal] <= 0)
            {
                maxHeap.pop();
                maxVal = maxHeap.top();
            }

            // if frequency of top element is greater than 0 then printing that
            if (freq[maxVal] > 0)
                cout << maxVal << " ";

            // incrementing the left pointer and decrementing its frequency
            freq[values[leftPtr]]--;
            leftPtr++;
        }

        rightPtr++;
    }
}
int main()
{
    int sizeOfArray;
    cout << "Enter the size of the array: ";
    cin >> sizeOfArray;
    vector<int> elements(sizeOfArray);

    // Taking the input of all the elements
    if (sizeOfArray > 0)
    {
        cout << "Enter the elements of the array" << endl;
        for (int i = 0; i < sizeOfArray; i++)
        {
            cin >> elements[i];
        }
    }
    else
    {
        cout << "Invalid array size" << endl;
    }

    int windowSize;
    cout << "Enter the window size: ";
    cin >> windowSize;

    if (windowSize > 0)
    {
        cout << "The maximum values in each window of given size are: ";
        findMaxInWindowSize(elements, windowSize);
    }
    else
    {
        cout << "Invalid window size." << endl;
    }

    return 0;
}