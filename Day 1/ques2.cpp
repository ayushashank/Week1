// Question 2
// Time Complexity: O(logN)
// Space Complexity:O(1)

#include <iostream>
using namespace std;

int swapDigits(int n)
{
    int lastDigit = n % 10;

    // calculating the base of 10
    int num = n;
    int numOfDigits = 0;
    while (num > 9)
    {
        num /= 10;
        numOfDigits++;
    }

    int firstDigit = num;

    // forming the base of 10 number
    int newNum = 1;
    while (numOfDigits > 0)
    {
        newNum *= 10;
        numOfDigits--;
    }

    // retrieving the number except first and last digit
    int middleNum = n % newNum;
    middleNum /= 10;

    // forming the new number
    newNum *= lastDigit;
    newNum += middleNum * 10 + firstDigit;

    return newNum;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "The number after reversing the first and last digits is: ";
    cout << swapDigits(n) << endl;
    return 0;
}
