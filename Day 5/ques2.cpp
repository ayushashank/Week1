#include <bits/stdc++.h>
using namespace std;

float findMedian(vector<int> &arr1, vector<int> &arr2)
{
    int numOfElements = 0;
    int ptr1 = 0, ptr2 = 0;

    while (ptr1 < arr1.size() or ptr2 < arr2.size())
    {
        

    }
}

int main()
{
    int sizeOfArr1, sizeOfArr2;
    cout << "Enter the size of first array: ";
    cin >> sizeOfArr1;
    vector<int> arr1;
    cout << "Enter the elements of the first array";
    for (int i = 0; i < sizeOfArr1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of second array: ";
    cin >> sizeOfArr2;
    vector<int> arr2;
    cout << "Enter the elements of the first array";
    for (int i = 0; i < sizeOfArr2; i++)
    {
        cin >> arr2[i];
    }

    cout << "Median of the two arrays is: " << findMedian(arr1, arr2);
    return 0;
}