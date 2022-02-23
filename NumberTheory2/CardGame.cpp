#include <iostream>
#include <map>
using namespace std;

void factors(map<int, int> &m, int n, bool inc)
{
    int k=n;
    for (int i = 2; i * i <= n && k>1; i++)
    {
        if (k % i == 0)
        {
            int count = 0;
            while (k > 1)
            {
                if (k % i == 0)
                {
                    count++;
                    k /= i;
                }
                else
                {
                    break;
                }
            }
            if (inc)
            {
                m[i] += count;
            }
            else
            {
                m[i] -= count;
            }
        }
    }

    if (k>1)
    {
        if (inc)
        {
            m[k]++;
        }
        else
        {
            m[k]--;
        }
    }
}

int fxn(int *arr, int k, int n)
{
    map<int, int> m, mk;
    factors(mk, k, true);
    map<int, int>::iterator it;
    

    bool *isCheck=new bool[n];
    for(int i=0; i<n; i++){
        isCheck[i]=false;
    }

    int i = 0, j = 0;
    int count=0;
    while (i < n && j < n)
    {
        if(!isCheck[i]){
            factors(m, arr[i], true);
            isCheck[i]=true;
        }
        
        bool flag = false;
        map<int, int>::iterator it;
        for (it = mk.begin(); it != mk.end(); it++)
        {
            if(m[(*it).first]>=(*it).second){
                flag=true;
            }else{
                flag=false;
                break;
            }
        }

        if(flag){
            count+=(n-i);
            factors(m, arr[j], false);
            j++;
        }else{
            i++;
        }
    }

    return count;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<fxn(arr, k, n)<<endl;
}