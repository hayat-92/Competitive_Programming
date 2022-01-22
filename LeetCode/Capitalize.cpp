#include <iostream>
#include <string>
using namespace std;

string capitalizeTitle(string title)
{
    int j = 0;
    int i = 0;
    string str = "";
    for (; i < title.length(); i++)
    {
        if (title[i] == ' ')
        {
            int temp = i - j;
            if (temp <= 2)
            {
                string temStr = title.substr(j, temp);
                for (int k = 0; k < temStr.length(); k++)
                {
                    str += tolower(temStr[k]);
                }
            }
            else
            {
                char c = title[j];
                str += toupper(c);
                string subst = title.substr(j + 1, temp - 1);
                for (int k = 0; k < subst.length(); k++)
                {
                    str += tolower(subst[k]);
                }
            }

            str += ' ';

            j = i + 1;
        }
    }

    if (i - j > 2)
    {
        char c = title[j];
        str += toupper(c);
        string subst = title.substr(j + 1, (i - j) - 1);
        for (int k = 0; k < subst.length(); k++)
        {
            str += tolower(subst[k]);
        }
    }
    else
    {
        string temStr = title.substr(j, i-j);
        for (int k = 0; k < temStr.length(); k++)
        {
            str += tolower(temStr[k]);
        }
    }

    return str;
}

int main()
{

    // string stt = "Abc def gFa";
    string title = "L hV";
    // getline(cin, stt);
    cout << capitalizeTitle(title);
    return 0;
}