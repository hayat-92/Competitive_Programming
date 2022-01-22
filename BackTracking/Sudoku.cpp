#include <iostream>
#include <utility>
#include<string>
using namespace std;

pair<int, int> PosOfEmpty(int **arr, int r, int c, int n)
{
    
    pair<int, int> p;
    for (int i = r; i < n; i++)
    {
        for (int j = c; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                p.first = i;
                p.second = j;
                return p;
            }
        }
    }
    p.first = -1;
    p.second = -1;
    return p;
}

bool sudoku(int **arr, int n)
{
    pair<int, int> pos = PosOfEmpty(arr, 0, 0, n);
    if (pos.first == -1 && pos.second == -1)
    {
        return true;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                if (arr[pos.first][j] == i)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                if (arr[j][pos.second] == i)
                {
                    flag = true;
                    break;
                }
            }


            if (flag)
            {
                continue;
            }
            int rs, re, cs, ce;


            if (pos.first >= 0 && pos.first < 3)
            {
                rs = 0;
                re = 2;
            }
            else if (pos.first >= 3 && pos.first < 6)
            {
                rs = 3;
                re = 5;
            }
            else if (pos.first >= 6 && pos.first < 9)
            {
                rs = 6;
                re = 8;
            }

            if (pos.second >= 0 && pos.second < 3)
            {
                cs = 0;
                ce = 2;
            }
            else if (pos.second >= 3 && pos.second < 6)
            {
                cs = 3;
                ce = 5;
            }
            else if (pos.second >= 6 && pos.second < 9)
            {
                cs = 6;
                ce = 8;
            }

            for (int x = rs; x <= re; x++)
            {
                for (int j = cs; j <= ce; j++)
                {
                    if (arr[x][j] == i)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
            {
                continue;
            }
            int elem = i;

            arr[pos.first][pos.second] = elem;
            bool ck = sudoku(arr, n);
            if (ck)
            {
                return true;
            }
            else
            {
                arr[pos.first][pos.second] = 0;
                continue;
            }
        }

        return false;
    }
}

int main()
{

    int **arr = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        int *x = new int[9];
        // string s;
        // cin>>s;
        // for (int j = 0; j < 9; j++)
        // {
        //     x[j]=s[j]-'0';
        // }
        // arr[i] = x;

        for(int j=0; j<9; j++){
            cin>>x[j];
        }
        arr[i]=x;
    }


    

    sudoku(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // cout << arr[i][j];
            if(arr[i][j]==0){
                cout<<"false"<<endl;
                return 0;
                // return false;
            }
        }
    }
    cout<<"true"<<endl;

    return 0;
}