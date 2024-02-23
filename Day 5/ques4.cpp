/* Question 4
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

// MARK:- Function to return maximum water which is can be hold by the container
// DESC:- Uses two pointer approach to find the maximum area
int containerWithMostWater(vector<int> &heights)
{
    // Initializing the starting pointer at 0 and ending pointer at the last index
    int startIndex = 0, endIndex = heights.size() - 1;
    int maxArea = 0;
    while (startIndex < endIndex)
    {
        // Calculating the area of the current container and updating the maximum area
        // (endIndex - startIndex) * min(values[startIndex], values[endIndex]) is the area of the current container
        maxArea = max(maxArea, (endIndex - startIndex) * min(heights[startIndex], heights[endIndex]));

        // Updating the pointers by changing the pointer which represents smaller height
        if (heights[startIndex] < heights[endIndex])
            startIndex++;
        else
            endIndex--;
    }

    return maxArea;
}

int main()
{
    int sizeOfArray;
    cout << "Enter the size of the array: ";
    cin >> sizeOfArray;

    vector<int> heights(sizeOfArray);
    if (sizeOfArray > 0)
    {
        // Taking the input of all the heights
        cout << "Enter the heights" << endl;
        for (int i = 0; i < sizeOfArray; i++)
        {
            cin >> heights[i];
        }

        cout << "The area of container with most water is: " << containerWithMostWater(heights);
    }
    else
    {
        cout << "Invalid array size." << endl;
    }
    return 0;
}