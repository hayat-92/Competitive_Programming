#include<iostream>
using namespace std;
typedef long long ll;
#define ml 1000000007;

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

        int m=100001;
        ll *fnl=new ll[m];
        int k=0;
        for(int i=0; i<m; i++){
            fnl[i]=0;
        }
        for(int i=0; i<n; i++){
            fnl[arr[i]]=1;
        }

        for(int i=1; i<m; i++){
            if(fnl[i]>0){
                for(int j=2*i; j<m; j+=i)
                if(fnl[j]>0){
                    fnl[j]=(fnl[i]+fnl[j])%ml;
                }
            }
        }

        ll sum=0;
        for(int i=0; i<m; i++){
            sum=(sum+fnl[i])%ml;
        }

        cout<<sum<<endl;

        
    }
    return 0;
}