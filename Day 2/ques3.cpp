// Question 3

// Time Complexity: O(N*N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void printPattern(int n)
{

    // Printing the upper half
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                cout << "\\";
            else if (j == n - 1 - i)
                cout << "/";
            else
                cout << "*";
        }
        cout << endl;
    }

    // Printing the middle pattern if n is odd
    if (n & 1 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == n / 2)
                cout << "/";
            else
                cout << "*";
        }
        cout << endl;
    }

    // printing the lower half
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n / 2 - i - 1)
                cout << "/";
            else if (j == n / 2 + i + 1)
                cout << "\\";
            else
                cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of pattern: ";
    cin >> n;

    printPattern(n);

    return 0;
}
