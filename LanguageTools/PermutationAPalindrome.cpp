#include <iostream>
#include <vector>
#include <string>
#include <map>
// #include<cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        map<char, vector<int>> m;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]].push_back(i + 1);
        }

        int count = 0;

        map<char, vector<int>>::iterator it;
        

        for (it = m.begin(); it != m.end(); it++)
        {
            if ((*it).second.size() % 2 != 0)
            {
                count++;
            }
        }

        if (count >= 2)
        {
            cout << -1 << endl;
        }
        else
        {
            int *arr = new int[s.length()];
            int st = 0;
            int ed = s.length() - 1;
            for (it = m.begin(); it != m.end(); it++)
            {
                vector<int> v = (*it).second;

                if (v.size() % 2 == 0)
                {
                    for (int i = 0; i < v.size(); i++)
                    {
                        if (i % 2 == 0)
                        {
                            arr[st++] = v[i];
                        }
                        else
                        {
                            arr[ed--] = v[i];
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < v.size() - 1; i++)
                    {
                        if (i % 2 == 0)
                        {
                            arr[st++] = v[i];
                        }
                        else
                        {
                            arr[ed--] = v[i];
                        }
                    }
                    arr[s.length() / 2] = v[v.size() - 1];
                }
            }

            for (int i = 0; i < s.length(); i++)
            {
                cout << arr[i] << " ";
            }
        }     
    }
}








// for (it = m.begin(); it != m.end(); it++)
        // {
        //     // cout << (*it).first << " :" << (*it).second << endl;
        //     cout << (*it).first << " :[";
        //     for (int i = 0; i < (*it).second.size(); i++)
        //     {
        //         cout << (*it).second[i] << " ";
        //     }
        //     cout << " ]" << endl;
        // }

        // cout << endl;










// cout << count << endl;

        // for (int i = 0; i < s.length(); i++)
        // {
        //     cout << s[i] << " :";
        //     for (int j = 0; j < m[s[i]].size(); j++)
        //     {
        //         cout << m[s[i]][j] << " ";
        //     }
        //     cout << endl;
        // }