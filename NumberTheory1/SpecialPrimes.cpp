#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    bool *arr = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = true;
    }

    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i; j * i <= n; j++)
            {
                arr[j * i] = false;
            }
        }
    }

    int i = 2;
    int j = 3;
    int count = 0;
    while (j <= n)
    {
        if (arr[j])
        {
            int check = i + j + 1;
            if (check <= n)
            {
                if (arr[check])
                {
                    count++;
                    i = j;
                    j++;
                }
                else
                {
                    i=j;
                    j++;
                    
                }
            }else{
                break;
            }
        }
        else
        {
            j++;
        }
    }
    cout<<count<<endl;
    return 0;
}