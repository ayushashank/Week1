// Question 4
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool isValidURL(string url)
{
    string actintials1 = "http://www.", actintials2 = "https://www.";
    string intials1 = url.substr(0, 11), initials2 = url.substr(0, 12);

    if (intials1 != actintials1 and initials2 != actintials2)
        return false;

    string actEnd1 = ".org/", actEnd2 = ".com/";
    string end1 = url.substr(url.size() - 5), end2 = url.substr(url.size() - 5);

    if (end1 != actEnd1 and end1 != actEnd2 and end2 != actEnd1 and end2 != actEnd2)
        return false;

    if (intials1 == actintials1)
    {
        string subdomain = url.substr(11, url.size() - 5 - 11);
        if (subdomain.size() < 2 or subdomain.size() > 256)
            return false;

        for (int i = 11; i < url.size() - 5; i++)
        {
            if (!((url[i] >= 'a' and url[i] <= 'z') or (url[i] >= 'A' and url[i] <= 'Z') or (url[i] >= '0' and url[i] <= '9') or (url[i] == '-')))
                return false;
        }
    }
    else if (initials2 == actintials2)
    {
        string subdomain = url.substr(12, url.size() - 5 - 12);
        if (subdomain.size() < 2 or subdomain.size() > 256)
            return false;
        for (int i = 12; i < url.size() - 5; i++)
        {
            if (!((url[i] >= 'a' and url[i] <= 'z') or (url[i] >= 'A' and url[i] <= 'Z') or (url[i] >= '0' and url[i] <= '9') or (url[i] == '-')))
                return false;
        }
    }

    return true;
}

int main()
{
    string url = "https://www.bigohtech.com/";

    if (isValidURL(url))
        cout << "It is a valid url" << endl;
    else
        cout << "It is not a valid url" << endl;

    return 0;
}
