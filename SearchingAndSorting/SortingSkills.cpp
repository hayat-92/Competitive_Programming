#include <iostream>
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
        for (int i = 0, j = 1; i < n && j < n;)
        {
            int fcount = 0;
            int k = i;

            while(arr[k] == arr[i]){
                fcount++;
                k++;
            }
            j=k;

            int scount = 0;
            int s = j;
            while(arr[s] == arr[j]){
                scount++;
                s++;
            }
            if (arr[i] - arr[j] == 1)
            {
                int fnum = arr[i];
                int snum = arr[j];
                int t = i;
                for (int x = 0; x < scount; x++)
                {
                    arr[t++] = snum;
                }
                for (int x = 0; x < fcount; x++)
                {
                    arr[t++] = fnum;
                }
            }
            i =j;
            j =j+1;
        }
        int i = 1;
        for (; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                cout << "No" << endl;
                break;
            }
        }

        if (i == n)
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
