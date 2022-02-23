#include <iostream>
#include<algorithm>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt, dt+n);
    int mx=1;
    int count=1;
    int j=0;
    for(int i=1; i<n;){
        if(at[i]<=dt[j]){
            count++;
            mx=max(mx, count);
            i++;
        }else{
            if(j<i){
                j++;
                count--;
            }
        }
    }
    return mx;

}
int main()
{
    int at[]={900, 940, 950, 1100, 1500, 1800};
    int dt[]={910, 1200, 1120, 1130, 1900, 2000};
    cout<<calculateMinPatforms(at, dt, 6)<<endl;

    return 0;
}