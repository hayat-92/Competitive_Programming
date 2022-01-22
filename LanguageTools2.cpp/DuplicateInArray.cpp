#include<iostream>
#include<algorithm>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    sort(arr,arr+n);
    int num;
    for(int i=1; i<n; i++){
        if(arr[i]==arr[i-1]){
            num=arr[i];
        }
    }

    return num;
    
}