#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }

        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++)
        {
            if ((*it).second & 1 != 0)
            {
                cout << (*it).first << endl;
                break;
            }
        }
    }
    return 0;
}