#include<iostream>
#include<algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    // int count=0;
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         for(int k=j+1; k<n; k++){
    //             int sum=arr[i]+arr[j]+arr[k];
    //             if(sum==num){
    //                 count++;
    //             }
    //         }
    //     }
    // }

    // return count;
    sort(arr, arr+n);

    int Tsum=0;

    for(int i=0; i<n; i++){
        int sum=num-arr[i];
        int j=i+1;
        int k=n-1;
        while(j<k){
            int total=0;
            if(arr[j]+arr[k]<sum){
                j++;
            }else if(arr[j]+arr[k]>sum){
                k--;
            }else{
                if(arr[j]==arr[k]){
                    total=((k-j)*(k-j+1))/2;
                }else{
                    int lcount=0;
                    int rcount=0;
                    for(int s=j; s<=k; ++s){
                        if(arr[s]==arr[j]){
                            lcount++;
                        }else{
                            break;
                        }
                    }

                    for(int s=k; s>=j; s--){
                        if(arr[s]==arr[k]){
                            rcount++;
                        }else{
                            break;
                        }
                    }
                    total=lcount*rcount;
                    
                    j+=lcount;
                    k-=rcount;
                }
                Tsum+=total;
                
            }

        }

    }

    return Tsum;


}

int main(){

    int arr[]={2, -5, 8, -6, 0, 5 ,10, 11, -3};
    cout<<tripletSum(arr, 9, 10);

}