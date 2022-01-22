#include<iostream>
#include <algorithm>
// #include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll Kadane(int *arr, int n){
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
ll Kconcat(int arr[], int n, int k){
    ll Kadane_sum=Kadane(arr, n);
    ll current_pref_sum=0, current_suff_sum=0;
    ll max_pref_sum=INT_MIN, max_suff_sum=INT_MIN;

    for(int i=0; i<n; i++){
        current_pref_sum+=arr[i];
        max_pref_sum=max(current_pref_sum, max_pref_sum);
    }

    ll totalSum=current_pref_sum;

    for(int i=n-1; i>=0; i--){
        current_suff_sum+=arr[i];
        max_suff_sum=max(current_suff_sum, max_suff_sum);
    }

    ll ans;
    if(totalSum<0){
        ans=max(max_suff_sum+max_pref_sum, Kadane_sum);
    }else{
        ans=max(max_suff_sum+(k-2)*totalSum+max_pref_sum, Kadane_sum);
    }

    return ans;



}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int *arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<Kconcat(arr, n,k);
    }

    return 0;

}