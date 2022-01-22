#include<iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    //Write your code here
    int *narr=new int [d];
    for(int i=0; i<d; i++){
        // int temp=arr[0];
        narr[i]=input[i];
    }
    int j=0;
    for(int i=d; i<n; i++){
        input[j++]=input[i];
    }

    for(int i=0; i<d; i++){
        input[j++]=narr[i];
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    rotate(arr, 2, 7);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }

}