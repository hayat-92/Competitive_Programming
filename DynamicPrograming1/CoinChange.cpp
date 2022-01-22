#include<iostream>
using namespace std;

typedef long long ll;

ll coinChange(int V, int *d, int dnum, ll **k){
    if(V==0){
        return 1;
    }

    if(dnum==0){
        return 0;
    }

    if(V<0){
        return 0;
    }

    if(k[V][dnum]>-1){
        return k[V][dnum];
    }

    ll m=pow(10,9)+7;

    int fst=coinChange(V-d[0], d, dnum, k);
    int sec=coinChange(V, d+1, dnum-1, k);
    k[V][dnum]=(fst+sec)%m;
    return (fst+sec)%m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int v;
        cin>>v;

        ll **K=new ll*[v+1];
        for(int i=0; i<v+1; i++){
            ll *in=new ll[n+1];
            for(int j=0; j<n+1; j++){
                in[j]=-1;
            }
            K[i]=in;
        }

        cout<<coinChange(v, arr, n, K)<<endl;
        delete [] arr;
        for(int i=0; i<v+1; i++){
            delete [] K[i];
        }

        delete [] K;

        
    }
    return 0;
}