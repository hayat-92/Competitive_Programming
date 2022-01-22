#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

ll momoCouny(ll *arr,ll st, ll en, ll x){

    if(st>en){
        return 0;
    }
    // if(st==en){
    //     if(arr[st]<=x){
    //         return st;
    //     }else{
    //         return 0;
    //     }
    // }
    ll mid=(st+en)/2;
    ll num;
    if(arr[mid]==x){
        return mid;
    }
    if(arr[mid]<x){
        num=momoCouny(arr, mid+1, en, x);
        return max(mid, num);
    }else{
        num=momoCouny(arr, st, mid-1, x);
        return num;
    }

    

}

int main(){

    int n;
    cin>>n;
    ll *arr=new ll[n];
    ll sum=0;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        sum+=temp;
        arr[i]=sum;
    }

    int q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        int momoCount=0;
        ll In=momoCouny(arr, 0, n-1,x);
        
        cout<<In+1<<" "<<(x-arr[In])<<endl;
    }


    return 0;

}