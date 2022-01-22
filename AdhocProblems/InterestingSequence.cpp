#include<iostream>
#include<algorithm>
using namespace std;


typedef long long ll;

int main(){

    int n;
    cin>>n;
    ll k,l;
    cin>>k>>l;
    int *arr=new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int minElem=INT_MAX;
    int maxElem=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]<minElem){
            minElem=arr[i];
        }

        if(arr[i]>maxElem){
            maxElem=arr[i];
        }
    }

    ll fcost=LLONG_MAX;
    for(int j=minElem; j<=maxElem; j++){
        int inc=0, dec=0;
        for(int i=0; i<n; i++){
            if(arr[i]<j){
                inc+=(j-arr[i]);
            }

            if(arr[i]>j){
                dec+=(arr[i]-j);
            }
        }

        

        if(inc>=dec){
            ll cost=0;
            cost+=(ll)(dec*k);
            cost+=(ll)((inc-dec)*l);
            fcost=min(fcost, cost);
        }
        
    }
    cout<<fcost;
    return 0;
}