#include<iostream>
#include<vector>
using namespace std;
int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    // Write your code here.
    int *arr=new int[n];
    for(int i=0; i<n; i++){
        arr[i]=gas[i]-cost[i];
    }

    int trailSum=0;
    int leadSum=0;
    int index=0;
    for(int i=0; i<n; i++){
        if(leadSum==0 && arr[i-1] != 0){
            index=i;
        }
        leadSum+=arr[i];
        if(leadSum<0){
            trailSum+=leadSum;
            leadSum=0;
        }
    }

    if((leadSum+trailSum)>=0){
        return index;
    }else{
        return -1;
    }
}
int main(){
    vector<int> gas={1, 2, 3, 4, 5};
    vector<int> cost={3, 4, 5, 1, 2};
    cout<<minimumStartingIndex(gas, cost, 5);

return 0;
}