#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

ll merge(ll *arr, int n, ll st, ll en, ll k){

    if(st>en){
        return -1;
    }


    ll mid=(st+en)/2;
    int count=k;

    for(int i=0; i<n; i++){
        if(count<=0){
            break;
        }
        ll temp=arr[i]/mid;
        count-=temp;
    }

    ll num;
    if(count<=0){
        num=merge(arr, n, mid+1, en, k);
    }else{
        num=merge(arr, n, st, mid-1, k);
    }

    if(count<=0){
        return max(mid, num);
    }else{
        return num;
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){
        ll N,K;
        cin>>N>>K;

        ll *arr=new ll[N];
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }

        sort(arr, arr+N);

        cout<<merge(arr, N,0, arr[N-1], K)<<endl;

    }

    


    return 0;
}