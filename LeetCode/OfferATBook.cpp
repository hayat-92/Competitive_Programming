#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n, greater<int>());
    int total=0;
    int i=0;
    for(; i<n-(n%3);){
        total+=arr[i];
        total+=arr[i+1];
        i+=3;
    }
    for(;i<n;i++){
        total+=arr[i];
    }
    cout<<total<<endl;
    return 0;
}