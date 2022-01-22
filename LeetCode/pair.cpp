#include<iostream>
#include<utility>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    pair<int, int> *arr=new pair<int, int>[m];
    for(int i=0; i<m; i++){
        cin>>arr->first>>arr->second;
    }
    int t=(n*(n-1))/2-m;
    t+=n+1;
    cout<<t<<endl;
    return 0;
}