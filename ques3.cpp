// Question 3
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool isValid(int num)
{
    while (num > 0)
    {
        int dig = num % 10;
        if (dig != 2 and dig != 3 and dig != 5 and dig != 7)
            return false;
        num /= 10;
    }

    return true;
}

int solve(int n)
{
    for (int i = n - 1; i > 1; i--)
    {
        if (isValid(i))
            return i;
    }
    return -1;
}

int main()
{
    int n = 1745;
    cout << solve(n) << endl;
    return 0;
}
