#include<iostream>
using namespace std;
#include<algorithm>


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int *arr=new int[N];
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }

        sort(arr, arr+N);
        int curr=0;
        int ans=0;
        for(int i=0; i<N; i++){
            if(++curr==arr[i]){
                ans++;
                curr=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}