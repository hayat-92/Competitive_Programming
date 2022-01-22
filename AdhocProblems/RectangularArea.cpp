#include <iostream>
#include <utility>
#include<cmath>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> v1, pair<int, int> v2)
{
    if(v1.first==v2.first){
        return v1.second>v2.second;
    }
    return v1.first < v2.first;
}

long long rectArea(pair<int, int> *arr, int n)
{
    sort(arr, arr + n, compare);
    int size = (arr[n-1].first);
    int *area = new int[size];
    int maxI = arr[n-1].second;
    int k = 0;
    
    for (int i = size; i > 0; i--)
    {
        int In = (std::lower_bound(arr, arr+n, make_pair(i, -1),
                                    [](pair<int, int> lhs, pair<int, int> rhs)
                                {
                                    return lhs.first < rhs.first;
                                 }))-arr;
        // int In=In1-arr;
        pair<int, int> temp=arr[In];
        maxI = max(maxI, temp.second);
        area[k++]=maxI;
    }

    long long m=pow(10,9)+7;

    long long sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum =(sum+ area[i])%m;
    }

    return (2 * sum)%m;
}

int main()
{
    int n;
    cin >> n;
    pair<int, int> *arr = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        int x, y;
        cin >> x >> y;
        p = make_pair(x/2, y);
        arr[i] = p;
    }

    cout << rectArea(arr, n) << endl;

    return 0;
}