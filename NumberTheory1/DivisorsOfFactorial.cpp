#include<iostream>
using namespace std;
typedef long long ll;
#define m 10000000007;


ll fXn(int n){
    bool *arr=new bool[n+1];
    for(int i=0; i<=n; i++){
        arr[i]=true;
    }

    arr[0]=false;
    arr[1]=false;
    for(int i=2; i*i<=n; i++){
        if(arr[i]){
            for(int j=i; j*i<=n;j++){
                arr[j*i]=false;
            }
        }
    }

     ll mul=1;

    for(int i=0; i<n+1; i++){
        if(arr[i]){
            int k=1;
            int p=i;
            ll count=0;
            for(;p<=n;){
                count+=(n/p)%m;
                p*=i;
            }
            mul*=(count+1)%m;
        }
    }

    return mul%m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fXn(n)<<endl;
    }
    return 0;
}