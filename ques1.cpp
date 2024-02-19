// Question 1
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or
        ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U')
        return true;

    return false;
}

bool isValidName(string str)
{
    unordered_map<char, bool> vowels;

    for (int i = 0; i < str.size(); i++)
    {
        if (isVowel(str[i]))
        {
            if (vowels[str[i]] == true)
                return false;
            else
                vowels[str[i]] = true;
        }
    }

    int firstS = -1, secondS = -1;
    int indT = -1;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'T')
        {
            indT = i;
        }
        if (str[i] == 'S')
        {
            if (firstS != -1 and secondS != -1)
            {
                firstS = secondS;
                secondS = i;
            }
            else if (firstS == -1)
                firstS = i;
            else
                secondS = i;
        }

        if (firstS != -1 and secondS != -1 and indT != -1)
        {
            if (indT > firstS and indT < secondS)
                return false;
        }
    }
    return true;
}
int main()
{
    string str = "agdfywbSSA";

    if (isValidName(str))
        cout << "It is a valid name." << endl;
    else
        cout << "It is not a valid name." << endl;

    return 0;
}
