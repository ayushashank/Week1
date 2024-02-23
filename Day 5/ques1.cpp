/* Question 1
Find all interleavings of given strings that can be formed from all the characters of the first and second string where the order of characters is preserved.
*/

// Time Complexity: O(2^(M+N))
// Space Complexity: O(N+M)
#include <bits/stdc++.h>
using namespace std;

// MARK:- Recursive function to generate all the possible strings
// DESC:- Generates all the interleaving strings by taking one character each time from each string and then calling the recursive function again, when the length of resultant string equals the sum of size of both the strings, that string is printed.
void findAllStrings(int index1, int index2, string &first, string &second, string current)
{
    // Printing the current string if its size equals the sum of size of both the strings
    if (current.size() == first.size() + second.size())
    {
        cout << current << " ";
        return;
    }

    // Appending the character to current string if it exists; then calling the recursive function, removing the last character after the recursive call
    if (index1 < first.size())
    {
        current += first[index1];
        findAllStrings(index1 + 1, index2, first, second, current);
        current.pop_back();
    }
    // Appending the character to current string if it exists; then calling the recursive function; removing the last character after the recursive call
    if (index2 < second.size())
    {
        current += second[index2];
        findAllStrings(index1, index2 + 1, first, second, current);
        current.pop_back();
    }
}

int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    findAllStrings(0, 0, str1, str2, "");

    return 0;
}