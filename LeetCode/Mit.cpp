#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int sum=0;
        for(int i=cost.size()-1; i>=0;){
            sum+=cost[i];
            if(i-1>=0){
                sum+=cost[i-1];
            }
            i-=3;
            
        }

        return sum;
        
    }

int main(){
    vector<int> v={1,2,3};
    cout<<minimumCost(v)<<endl;

    return 0;
}