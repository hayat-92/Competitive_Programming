#include <iostream>
#include <string>
#include <set>
using namespace std;

string removeDup(string str, string &newstr)
{
    if (str.length() == 0)
    {
        return newstr;
    }

    // string nstr="";
    newstr += str[0];
    int j = 1;
    int count = 0;
    while (str[j] == str[0])
    {
        j++;
        count++;
    }
    

    string fstr = removeDup(str.substr(1+count, (str.length() - 1-count)), newstr);

    return fstr;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        // getline(cin, str);
        set<char> s;
        string newstr = "";
        cout << removeDup(str, newstr) << endl;
    }
    return 0;
}