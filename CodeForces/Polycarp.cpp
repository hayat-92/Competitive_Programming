#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int arr[7];
        for(int i=0; i<7; i++){
            cin>>arr[i];
        }
        int a=arr[0];
        int b=arr[1];
        int c=arr[6]-(a+b);
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}