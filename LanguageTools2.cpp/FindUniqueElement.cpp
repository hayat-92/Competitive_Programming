#include<iostream>
#include<algorithm>
using namespace std;

int findUnique(int *arr, int n) {
    // Write your code here
    sort(arr, arr+n);
    int num;
    for(int i=0; i<n; i+=2){
        if(arr[i]!=arr[i+1]){
            num=arr[i];
            break;
        }

        if((i+1)==n){
            num=arr[i];
        }
    }

    return num;
    
}

int main(){

    int arr[]={1, 3, 1, 3, 6, 6, 7, 10, 7};
    cout<<findUnique(arr, 9);

}