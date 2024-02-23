/* Question 2
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
*/

// Time Complexity: O(M+N) where N and M are size of two given strings
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

// MARK:- Function to find the median of two sorted arrays using two pointer approach
// DESC:-
float findMedian(vector<int> &arr1, vector<int> &arr2)
{
    int numOfElements = 0;  // Represents the number of elements traversed so far
    int ptr1 = 0, ptr2 = 0; // Initializing two pointers to denote the start of each array

    // Total number of elements in both arrays
    int totalSize = arr1.size() + arr2.size();

    // Middle element in case of odd number of elements
    int midIndex = totalSize / 2;

    // Middle elements in case of odd number of elements
    int midIndex1 = totalSize / 2 - 1, midIndex2 = totalSize / 2;

    // Denoting two middle values
    float value1 = FLT_MAX, value2 = FLT_MAX;

    // Traversing both the arrays
    while (ptr1 < arr1.size() || ptr2 < arr2.size())
    {
        // logic for odd number of elements
        if ((totalSize & 1) == 1)
        {
            if (numOfElements == midIndex)
            {
                // if element does not exist in first array returning element of second array
                if (ptr1 >= arr1.size())
                    return arr2[ptr2];

                // if element does not exist in second array returning element of first array
                else if (ptr2 >= arr2.size())
                    return arr1[ptr1];

                //  returning the minimum of both arrays
                else
                    return min(arr1[ptr1], arr2[ptr2]);
            }
        }

        // logic for even number of elements
        else
        {
            if (numOfElements == midIndex1)
            {
                // if element does not exist in first array returning element of second array
                if (ptr1 >= arr1.size())
                    value1 = arr2[ptr2];

                // if element does not exist in second array returning element of first array
                else if (ptr2 >= arr2.size())
                    value1 = arr1[ptr1];

                //  returning the minimum of both arrays
                else
                    value1 = min(arr1[ptr1], arr2[ptr2]);
            }
            if (numOfElements == midIndex2)
            {
                // if element does not exist in first array returning element of second array
                if (ptr1 >= arr1.size())
                    value2 = arr2[ptr2];

                // if element does not exist in second array returning element of first array
                else if (ptr2 >= arr2.size())
                    value2 = arr1[ptr1];

                //  returning the minimum of both arrays
                else
                    value2 = min(arr1[ptr1], arr2[ptr2]);
            }

            // Returning the median if both middle elemengts have been found
            if (value1 != FLT_MAX and value2 != FLT_MAX)
                return (value1 + value2) / 2;
        }

        // Incrementing the pointers if they are in bounds
        if (ptr1 >= arr1.size())
            ptr2++;
        else if (ptr2 >= arr2.size())
            ptr1++;
        else if (arr1[ptr1] <= arr2[ptr2])
            ptr1++;
        else
            ptr2++;

        numOfElements++; // incrementing the number of elements traversed so far
    }

    return 1.0;
}

int main()
{
    int sizeOfArr1, sizeOfArr2;
    cout << "Enter the size of first array: ";
    cin >> sizeOfArr1;
    vector<int> arr1(sizeOfArr1);

    // Taking the input of elements of array 1
    if (sizeOfArr1 > 0)
    {
        cout << "Enter the elements of the first array: ";
        for (int i = 0; i < sizeOfArr1; i++)
        {
            cin >> arr1[i];
        }
    }
    else
    {
        cout << "Invalid size or array 1." << endl;
    }

    cout << "Enter the size of second array: ";
    cin >> sizeOfArr2;
    vector<int> arr2(sizeOfArr2);

    // Taking the input of elements of array 1
    if (sizeOfArr2 > 0)
    {
        cout << "Enter the elements of the second array: ";
        for (int i = 0; i < sizeOfArr2; i++)
        {
            cin >> arr2[i];
        }
    }
    else
    {
        cout << "Invalid size or array 2." << endl;
    }

    // Calling the function if there are some elements in any of the array
    if (sizeOfArr1 > 0 or sizeOfArr2 > 0)
    {
        cout << "Median of the two arrays is: " << findMedian(arr1, arr2);
    }
    return 0;
}