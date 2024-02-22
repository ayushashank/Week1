/* Question 2
Write a program to print all the possible combinations according to the input values.
Example :
Given Values
'1' : ['Z', 'Y', 'A'],
'2' : ['B', 'O'],
'12' : ['L']
'3' : ['U', 'P']
Input: 123
Output : [ZBU, ZBP, ZOU, ZOP, YBU, YBP, YOU, YOP, ABU, ABP, AOU, AOP, LU, LP]
*/

// Time Complexity:
// Space Complexity:

#include <bits/stdc++.h>
using namespace std;

// MARK:- Method to produce all the possible combinations
// DESC:- Takes all the values corresponding to a key and appends to the current string and prints the string if index exceeds the size of the input string
void printCombinations(string key, int index, string currentString, unordered_map<string, vector<char>> &values, string input)
{
    // prints the string if index exceeds the input string size
    if (index == input.size())
    {
        cout << currentString << " ";
        return;
    }

    // adds the value in the current string and makes the recursive call and deletes the last character after returning from the recursive call
    for (auto val : values[key])
    {
        currentString += val;
        if (index + 1 < input.size())
        {
            string newKey(1, input[index + 1]);
            printCombinations(newKey, index + 1, currentString, values, input);
        }
        else
        {
            printCombinations("", index + 1, currentString, values, input);
        }

        currentString.pop_back();
    }
}

int main()
{
    unordered_map<string, vector<char>> values;
    values.insert({"1", {'Z', 'Y', 'A'}});
    values.insert({"2", {'B', 'O'}});
    values.insert({"3", {'U', 'P'}});
    values.insert({"121", {'X', 'M'}});
    // values.insert({"123", {'L', 'Q'}});

    string input = "121";

    cout << "\nAll the possible combinations are" << endl;

    // Generating all the starting keys
    string key = "";
    for (int i = 0; i < input.size(); i++)
    {
        key += input[i];
        printCombinations(key, i, "", values, input);
    }
    cout << endl;
    return 0;
}