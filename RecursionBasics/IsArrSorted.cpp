#include <iostream>
using namespace std;

int Is_Sorted(int arr[], int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }

    return Is_Sorted(arr+1, size-1);
}

int main(){
    int arr[]={1,2,7,4,5,6};
    cout<<Is_Sorted(arr, 6);
}