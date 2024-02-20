// Question 5
// Time Complexity: O(N*N);
// Space Complexity: O(1)

#include <iostream>
using namespace std;

long long findLCM(long long a, long long b)
{
    long long big, small;
    if (a >= b)
    {
        big = a;
        small = b;
    }
    else
    {
        big = b;
        small = a;
    }

    for (long long val = big;; val += big)
    {
        if (val % small == 0)
            return val;
    }
}

long long solve(long long n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    long long lcm = 2;
    for (long long i = 3; i <= n; i++)
    {
        lcm = findLCM(lcm, i);
    }

    return lcm;
}

int main()
{
    long long n = 25;
    cout << solve(n) << endl;

    return 0;
}
