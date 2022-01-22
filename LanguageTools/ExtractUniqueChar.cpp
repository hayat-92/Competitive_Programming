#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string uniqueChar(string str)
{
    // Write your code here
    unordered_set<int> s;
    string ns = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (s.find(str[i]) == s.end())
        {
            s.insert(str[i]);
            ns+=str[i];
            
        }
        
    }
    return ns;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
    return 0;
}