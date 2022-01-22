#include<iostream>
using namespace std;
#include <algorithm>


int maxProduct(int arr[], int n){
    int current_max=1, current_min=1;
    int fmax=INT_MIN;
    // int fmin=INT_MAX
    ;

    for(int i=0; i<n; i++){
        if(arr[i]>0){
            current_max=current_max*arr[i];
            current_min=min(1, current_min*arr[i]);

            if(fmax<current_max){
                fmax=current_max;
            }
            
        }else if(arr[i]<0){
            int temp=current_max;
            current_max=max(1, current_min*arr[i]);
            current_min=temp*arr[i];

            if(fmax<current_max){
                fmax=current_max;
            }

        }else{
            current_max=1, current_min=1;
        }
    }

    return fmax;
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
        cout<<maxProduct(arr, n);
    }


    return 0;
}