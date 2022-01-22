#include<iostream>
#include<algorithm>
using namespace std;

void subset(int *arr, int k, int index, int &count, int n){
    if(k<0){
        return;
    }

    if(k==0){
        count++;
    }

    for(int i=index; i<n; i++){
        if(k-arr[i]>=0){
            subset(arr, k-arr[i], i+1, count, n);
        }else{
            return;
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int count=0;
        int *arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        sort(arr, arr+n);
        subset(arr, k, 0, count, n);
        cout<<count<<endl;
    }
    return 0;
}