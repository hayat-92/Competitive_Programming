#include<iostream>
#include<algorithm>
using namespace std;

int fXn(int *arr, int N){
    sort(arr, arr+N);
    int minVal=INT_MAX;
    for(int i=1; i<N; i++){
        minVal=min(minVal, (arr[i]-arr[i-1]));
    }
    return minVal;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int *arr=new int[N];
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        cout<<fXn(arr, N)<<endl;
    }
    return 0;
}