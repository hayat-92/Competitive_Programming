#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	// your code goes here
	ll N,K;
    cin>>N>>K;
    ll *arr=new ll[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    ll count=0;

    sort(arr, arr+N);
    for(int i=0, j=1; i<N && j<N;){
        if(i==j){
            j++;
        }
        if(arr[j]-arr[i]>=K){
            count+=(N-j);
            i++;
        }else{
            j++;
        }
        
    }

    cout<<count<<endl;
	return 0;
}