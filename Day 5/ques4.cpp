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

int containerWithMostWater(vector<int> &values)
{
    int startIndex = 0, endIndex = values.size() - 1;
    int maxArea = 0;
    while (startIndex < endIndex)
    {
        maxArea = max(maxArea, (endIndex - startIndex) * min(values[startIndex], values[endIndex]));
        if (values[startIndex] < values[endIndex])
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

    vector<int> values = {9, 0, 0, 0, 0, 0, 9};
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> values[i];
    }

    cout << "The area of container with most water is: " << containerWithMostWater(values);
    return 0;
}