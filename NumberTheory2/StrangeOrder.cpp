#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void fxn(int n){
    int * sieve=new int[n+1];
    for(int i=0; i<=n; i++){
        sieve[i]=i;
    }

    for(int i=2; i<=n;i++){
        if(sieve[i]==i){
            for(int j=2*i; j<=n; j+=i){
                sieve[j]=min(sieve[j], i);
            }
        }
    }

    bool *isChecked=new bool[n+1];
    for(int i=0; i<=n; i++){
        isChecked[i]=false;
    }

    

    for(int i=n; i>0; i--){
        vector<int> v;
        if(isChecked[i]){
            continue;
        }
        int x=i;
        int p=sieve[x];
        v.push_back(x);
        while(x!=1){
            for(int j=i-p; j>=p; j-=p){
                v.push_back(j);
                isChecked[j]=true;
            }

            while(x%p==0){
                x/=p;
            }
            p=sieve[x];
        }

        sort(v.begin(), v.end());
        for(int i=v.size()-1; i>=0; i--){
            cout<<v[i]<<" ";
        }
    }

    // v.push_back(1);

    // return v;


}

int main(){
    int n;
    cin>>n;
    // vector<int> arr=
    fxn(n);
    // for(int i=0; i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
}