#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

long long helper(long long *arr, int n, ll *output){

    

    if(n==1){
        output[0]=arr[0];
        return 0;
    }

    ll *A1=new ll[n/2];
    ll *A2=new ll[n-n/2];

    int Lcount=helper(arr, n/2, A1);
    int Rcount=helper(arr+n/2, (n-n/2), A2);

    int count=0;

    int SA1=n/2;
    int SA2=(n-n/2);

    int i=0, j=0,k=0;

    while(i<SA1 && j<SA2){
        if(A1[i]<A2[j]){
            output[k++]=A1[i++];
        }else{
            output[k++]=A2[j++];
            count+=(SA1-i);
        }
    }

    if(i<SA1){
        while(i<SA1){
            output[k++]=A1[i++];
        }
    }else if(j<SA2){
        while(j<SA2){
            output[k++]=A2[j++];
        }
    }

    int Tcount=Lcount+Rcount+count;
    return Tcount;

    

}

long long getInversions(long long *arr, int n){
    // Write your code here.
    // long long *output=new long long[n];
    ll *output=new ll[n];
    return helper(arr, n, output);
}

int main(){

    // ll arr[]={3, 2, 1};
    ll arr[]={2, 5, 1, 3 ,4};
    cout<<getInversions(arr, 5);

}