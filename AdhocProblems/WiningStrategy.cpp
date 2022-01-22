#include <iostream>
#include <algorithm>
using namespace std;


//Mycode

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

        int count = 0;
        int i = 0;
        for (; i < n; i++)
        {
            int deff = abs((arr[i] - (i + 1)));
            if (deff == 0 && (i - 1) >= 0 && (i + 1) < n)
            {
                int def1 = abs((arr[i - 1] - (i - 1 + 1)));
                int def2 = abs((arr[i + 1] - (i + 1 + 1)));
                if (def1 != 0 && def2 != 0)
                {
                    count += 2;
                }
            }
            if (deff <= 2)
            {
                count += deff;
            }
            else
            {
                break;
            }
        }
        if (i < n)
        {
            cout << "NO" << endl;
            // cout<<0<<endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << count / 2 << endl;
        }
    }
    return 0;
}




//CodingNinjas Solution

// #include <bits/stdc++.h>
// using namespace std;
void solve(int arr[], int n)
{
    // to check the answer
    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i] - i - 1) > 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != (i + 1))
        {
            if (((i - 1) >= 0) && arr[i - 1] == (i + 1))
            {
                cnt++;
                swap(arr[i], arr[i - 1]);
            }
            else if (((i - 2) >= 0) && arr[i - 2] == (i + 1))
            {
                cnt += 2;
                arr[i - 2] = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = i + 1;
            }
            else
            {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n%d\n", cnt);
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n);
    }
}