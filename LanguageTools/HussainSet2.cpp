// #include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;

void HusSet(ll arr[], int n, int m, ll Q[]){
    int count=1, i=0, j=0;
    queue<ll> q;
    sort(arr, arr+n, greater<ll>());
    while(i<n || !q.empty()){
        ll num;
        if(!q.empty()){
            int e=q.front();
            if(e>=arr[i]){
                q.pop();
                num=e;
            }else{
                num=arr[i];
                i++;
            }
        }else{
            num=arr[i];
            i++;
        }
        if(count==Q[j]){
            cout<<num<<endl;
            j++;
        }
        count++;
        num/=2;
        if(num!=0){
            q.push(num);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    ll *arr=new ll[n];
    ll *Q=new ll[m];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<m; i++){
        cin>>Q[i];
    }
    
    HusSet(arr, n,m, Q);

    // int count=0, i=n-1;
    // queue<ll> q;
    // sort(arr, arr+n);
    // while (m--)
    // {
    //     int curr_m;
    //     cin>>curr_m;
    //     ll ans;
    //     for(;count<curr_m; count++){
    //         if(i>=0 && (q.empty() || arr[i]>=q.front())){
    //             ans=arr[i];
    //             i--;
    //         }else{
    //             ans=q.front();
    //             q.pop();
    //         }
    //         q.push(ans/2);
    //     }
    //     cout<<ans<<endl;
    // }

    return 0;
}