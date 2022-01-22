#include <iostream>
#include<string>
using namespace std;

int Cost(string str1, string str2, int n)
{
    int count = 0;
    for (int i = 0; i < n;)
    {
        if (str1[i] != str2[i])
        {
            if (i + 1 < n && str1[i] != str1[i + 1] && str1[i + 1] != str2[i + 1])
            {
                count++;
                i += 2;
            }
            else
            {
                count++;
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    // char *str1 = new char[n];
    // char *str2 = new char[n];
    string s, t;
    cin >> s >> t;
    // cin >> str2;
    cout << Cost(s, t, n) << endl;
    return 0;
}