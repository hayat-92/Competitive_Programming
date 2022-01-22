#include <iostream>
using namespace std;

int Kadane(int *arr, int n){
    int best_sum=0;
    int current_sum=0;
    for(int i=0; i<n; i++){
        current_sum=current_sum+arr[i];
        if(best_sum<current_sum){
            best_sum=current_sum;
        }

        if(current_sum<0){
            current_sum=0;
        }
    }

    return best_sum;
}

int main(){
    int arr[]={-5,6,7,-20,3,5,8,-9};
    cout<<Kadane(arr, 8);
}