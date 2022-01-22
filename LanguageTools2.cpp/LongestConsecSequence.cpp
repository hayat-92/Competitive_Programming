#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] = i;
    }
    int fElem = arr[0];
    int st = 0;
    int en = 0;

    sort(arr, arr + n);
    int maxCount = 1;
    vector<int> v;
    for (int i = 0; i < n;)
    {
        int count = 1;
        int j = i;
        while (true)
        {
            if ((j + 1) < n && (arr[j + 1] - arr[j]) == 1)
            {
                count++;
                j++;
            }
            else
            {
                break;
            }
        }
        if (count > maxCount)
        {
            st = i;
            en = j;
            maxCount = max(maxCount, count);
        }
        else if (count == maxCount)
        {
            // int stIn=);
            if (m[arr[i]] < m[arr[st]])
            {
                st = i;
                en = j;
            }
        }
        i = j + 1;
    }
    if (maxCount == 1)
    {
        v.push_back(fElem);
    }
    else
    {
        v.push_back(arr[st]);
        v.push_back(arr[en]);
    }

    return v;
}

int main()
{

    // int arr[]={2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6 };
    int arr[]={3, 7, 2, 1, 9, 8, 41};
    // int arr[] = {15, 24, 23, 12, 19, 11, 16};
    vector<int> v = longestConsecutiveIncreasingSequence(arr, 7);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
