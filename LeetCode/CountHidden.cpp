#include<iostream>
#include<vector>
using namespace std;

int numberOfArrays(vector<int>& differences, int lower, int upper) {
    int k=lower;
    int count=0;
    while(k<=upper){
        int i=0;
        int u=0;
        int l=k;
        for(; i<differences.size(); i++){
            u=l+differences[i];
            if(u>=lower && u<=upper){
                l=u;
            }else{
                break;
            }
        }
        if(i==differences.size()){
            count++;
        }
        if(u>upper){
            break;
        }
        k++;
    }

    return count;
    }

int main(){
    vector<int> v={3,-4,5,1,-2};
    cout<<numberOfArrays(v, -4, 5);
    return 0;
}