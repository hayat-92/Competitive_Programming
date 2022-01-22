#include<iostream>
using namespace std;
#include<vector>

vector<long long> mindBind(int arr[], int n){
    vector<long long> parr(n);
    long long product=1;

    if(n==1){
        parr[0]=0; 
    }else{
        parr[0]=1;
    }

    
    for(int i=1; i<n; i++){
        product*=arr[i-1];
        parr[i]=product;
    }

    product=1;
    for(int i=1; i<n; i++){
        product *=arr[n-i];
        parr[n-1-i]*=product;
    }
    
    return parr;
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
        
        vector<long long> v=mindBind(arr, n);
        vector<long long>::iterator it;
        for(it=v.begin(); it!=v.end(); it++){
           cout<<*it<<" ";
        }
        cout<<endl;
    }
}