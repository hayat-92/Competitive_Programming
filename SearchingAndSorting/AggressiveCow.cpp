#include <iostream>
#include <algorithm>
using namespace std;

int AcowsDistance(int arr[], int N, int C, int mn, int mx)
{

    if(mn>mx){
        return -1;
    }
    int count = C - 1, cur_In = 0;
    int mid = (mn + mx) / 2;

    for (int i = 1; i < N; i++)
    {
        int diff = arr[i] - arr[cur_In];
        if(count==0){
            break;
        }
        if (diff >= mid)
        {
            count--;
            cur_In=i;
        }
    }

    if(mn==mx){
        if(count==0){
            return mid;
        }else{
            return -1;
        }
    }

    int cur_Max;
    if (count == 0)
    {
        cur_Max = AcowsDistance(arr, N, C, mid + 1, mx);
        return max(cur_Max, mid);
    }
    else
    {
        cur_Max = AcowsDistance(arr, N, C, mn, mid - 1);
        return cur_Max;
    }


    
}

int main()
{
    
    int k;
    cin >> k;
    while (k--)
    {
        int N, C;
        cin >> N >> C;
        int *arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + N);

        int mx = (arr[N - 1] - arr[0]);
        int d = AcowsDistance(arr, N, C, 0, mx);
        cout<<d<<endl;
    }


    return 0;
}