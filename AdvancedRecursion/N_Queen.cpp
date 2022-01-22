#include <iostream>
using namespace std;

void N_queen(int **arr, int r, int n, int &count)
{
    if (r == n)
    {
        if (count == n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << arr[i][j] << " ";
                }
            }
        }

        cout << endl;
        return;
    }
    

    for (int j = 0; j < n; j++)
    {
        bool flag = false;
        for (int k = 0; k < n; k++)
        {
            if (arr[k][j] == 1)
            {
                flag = true;
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (arr[r][k] == 1)
            {
                flag = true;
            }
        }

        int x = r, y = j;
        for (; x >= 0 && y >= 0; x--, y--)
        {
            if (arr[x][y] == 1)
            {
                flag = true;
            }
        }

        x = r, y = j;
        for (; x < n && y < n; x++, y++)
        {
            if (arr[x][y] == 1)
            {
                flag = true;
            }
        }

        x = r, y = j;
        for (; x < n && y >= 0; x++, y--)
        {
            if (arr[x][y] == 1)
            {
                flag = true;
            }
        }

        x = r, y = j;
        for (; x >= 0 && y < n; x--, y++)
        {
            if (arr[x][y] == 1)
            {
                flag = true;
            }
        }

        if (!flag)
        {
            arr[r][j] = 1;
            count++;
            N_queen(arr, r + 1, n, count);
            count--;
            arr[r][j] = 0;
            flag = false;
        }
    }

    if (count == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
        // return;
    }
}

int main()
{
    int n;
    cin >> n;
    // int arr[3][3];
    int count = 0;
    int **x = new int *[n];
    for (int i = 0; i < n; i++)
    {
        int *y = new int[n];
        for (int j = 0; j < n; j++)
        {
            y[j] = 0;
        }
        x[i] = y;
    }
    N_queen(x, 0, n, count);
    return 0;
}