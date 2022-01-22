#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here
    // int i=0, j=n-1;
    // sort(arr, arr+n);
    // int total=0;

    // while(i<j){
    //     if(arr[i]>0){
    //         break;
    //     }

    //     if(arr[j]<0){
    //         break;
    //     }

    //     if(arr[i]==0 && arr[j]==0){
    //         total+=(j-i+1)*2;
    //         break;
    //     }

    //     if((arr[i]+arr[j])>0){
    //         j--;
    //     }

    //     if((arr[i]+arr[j])<0){
    //         i++;
    //     }

    //     if((arr[i]+arr[j])==0){
    //         int lcount=0, rcount=0;
    //         for(int k=i; k<=j; k++){
    //             if(arr[k]==arr[i]){
    //                 lcount++;
    //             }else{
    //                 break;
    //             }
    //         }

    //         for(int k=j; k>=i; k--){
    //             if(arr[k]==arr[j]){
    //                 rcount++;
    //             }else{
    //                 break;
    //             }
    //         }

    //         total+=rcount*lcount;
    //         i+=lcount;
    //         j-=rcount;
    //     }
    // }

    // return total;

    unordered_map<int, int> m;
    int count=0;
    for(int i=0; i<n; i++){
        if(m.find(-arr[i])==m.end()){
            m[arr[i]]++;
        }else{
            count+=m[-arr[i]];
            m[arr[i]]++;
        }
        // cout<<(m.find(-arr[i]))<<" ";
        // cout<<m[arr[i]]<<" ";
    }

    return count;


}

int main(){
    int arr[]={2, 1 ,-2, 2, 3};
    // int arr[]={0, 0, 0, 0, 0};
    cout<<pairSum(arr, 5);
    return 0;
}