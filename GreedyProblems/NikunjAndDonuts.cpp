#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll fXn(ll *arr, ll N){
    sort(arr, arr + N, greater<ll>());
    ll prod=1;
    ll sum=0;
    for(ll i=0; i<N; i++){
        sum=sum+(arr[i]*prod);
        prod=(prod*2);
    }

    return sum;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll N;
        cin>>N;
        ll *arr=new ll[N];
        for(ll i=0; i<N; i++){
            cin>>arr[i];
        }

        cout<<fXn(arr, N)<<endl;
    }
    return 0;
}