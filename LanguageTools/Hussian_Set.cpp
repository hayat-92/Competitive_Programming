#include<iostream>
#include <queue>
#include<algorithm>
using namespace std;

typedef long long ll;

void HusSet(ll arr[], int n, int m){
    int count=0, i=0, j=0;
    queue<ll> q;
    sort(arr, arr+n, greater<ll>());
    while (m--)
    {
        int curr_m;
        cin>>curr_m;
        ll ans;
        for(;count<curr_m; count++){
            if(i<n && (q.empty() || (arr[i]>=q.front()))){
                ans=arr[i];
                i++;
            }else{
                ans=q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<<ans<<endl;
    }
    

    while(i<n || !q.empty()){
        int num;
        if(!q.empty()){
            int e=q.front();
            if(e>arr[i]){
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


int main(){
    int n,m;
    cin>>n>>m;
    ll *arr=new ll[n];
    // ll *Q=new ll[m];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<m; i++){
        cin>>Q[i];
    }

    int n,m;
    cin>>n>>m;
    ll *arr=new ll[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int count=0, i=n-1;
    queue<ll> q;
    sort(arr, arr+n);
    while (m--)
    {
        int curr_m;
        cin>>curr_m;
        ll ans;
        for(;count<curr_m; count++){
            if(i>=n && (q.empty() || (arr[i]>=q.front()))){
                ans=arr[i];
                i--;
            }else{
                ans=q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<<ans<<endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     ll arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }

//     int count=0, i=n-1;
//     queue<ll> q;
//     sort(arr, arr+n);
//     while (m--)
//     {
//         int curr_m;
//         cin>>curr_m;
//         ll ans;
//         for(;count<curr_m; count++){
//             if(i>=0 && (q.empty() || arr[i]>=q.front())){
//                 ans=arr[i];
//                 i--;
//             }else{
//                 ans=q.front();
//                 q.pop();
//             }
//             q.push(ans/2);
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }