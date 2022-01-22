#include<iostream>
#include<map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m;
        cin>>n;
        int *stAr=new int[m+1];
        int *enAr=new int[m+1];

        for(int i=0; i<m+1; i++){
            stAr[i]=0;
            enAr[i]=0;
        }
        for(int i=0; i<n; i++){
            int st,en;
            cin>>st>>en;
            stAr[st]++;
            enAr[en]++;
        }

        int *boxCoin=new int[m+1];
        boxCoin[0]=0;
        boxCoin[1]=stAr[1];
        for(int i=2; i<m+1; i++){
            int temp=stAr[i]-enAr[i-1]+boxCoin[i-1];
            boxCoin[i]=temp;
        }

        map<int, int> mp;
        for(int i=0; i<m+1; i++){
            mp[boxCoin[i]]++;
        }

        int *fbox=new int[m+1];
        fbox[m]=mp[m];
        for(int i=m-1; i>0; i--){
            fbox[i]=fbox[i+1]+mp[i];
        }
        fbox[0]=m;

        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            cout<<fbox[x]<<endl;
        }




    }
    return 0;
}