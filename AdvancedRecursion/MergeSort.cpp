#include<iostream>
using namespace std;

void merge(int *arr, int st, int en){
    if(st>=en){
        return;
    }

    int mid=(st+en)/2;
    merge(arr, st, mid);
    merge(arr, mid+1, en);
    int *narr=new int[en-st+1];
    int i=st, j=mid+1;
    int k=0;
    for(; i<=mid && j<=en;){
        if(arr[i]<=arr[j]){
            narr[k++]=arr[i++];
        }else{
            narr[k++]=arr[j++];
        }
    }

    while(i<=mid){
        narr[k++]=arr[i++];
    }

    while(j<=en){
        narr[k++]=arr[j++];
    }

    int x=st;


    for(int s=0; s<=(en-st+1)&& x<=en; s++){
        arr[x++]=narr[s];
    }
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

        merge(arr, 0, n-1);
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}