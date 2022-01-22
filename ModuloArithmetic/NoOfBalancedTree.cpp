#include<iostream>
#include<cmath>
using namespace std;

int NoBalancedTree(int h){
    if(h==0 || h==1){
        return 1;
    }

    int x=NoBalancedTree(h-1);
    int y=NoBalancedTree(h-2);
    long xxans=(long)x*x;
    long xyans=(long)x*y*2;
    int rem=pow(10, 9)+7;
    int xxf=(int)(xxans%rem);
    int xyf=(int)(xyans%rem);
    int fnl=(xxf+xyf)%rem;
    

    return fnl;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int h;
        cin>>h;

        cout<<NoBalancedTree(h)<<endl;

    }
    return 0;
}

