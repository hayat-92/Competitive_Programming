#include<iostream>
#include <algorithm>
#include<cmath>
using namespace std;
struct Interval{
    int st;
    int et;
};

bool compare(Interval i1, Interval i2){
    return i1.st < i2.st;
}


int main(){
    int arr[]={1,3,2,5,7,3,6};
    sort(arr, arr+6);
    // for(int i=0; i<7; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    //BINARY SORT
    // cout<<binary_search(arr, arr+7, 9);
    // cout<<endl;


    //LOWER_BOUND or INDEX FIND
    cout<<lower_bound(arr, arr+7, 0)-arr;
    cout<<endl;

    //UPPER BOUND
    // cout<<upper_bound(arr, arr+7, 2)-arr;
    // cout<<endl;

    // cout<<endl;

    //GCD
    // cout<<__gcd(2, 8)<<endl;

    //POWER
    // cout<<pow(2,5)<<endl;

    //SWAP
    // int x=10;
    // int y=12;
    // swap(x,y);
    // cout<<x<<endl;
    // cout<<y<<endl;

    //MINIMUM
    // cout<<min(14, 18)<<endl;


    //SORT2

    // Interval arr[]={{6,4}, {3,4}, {4,6}, {8,13}};
    // sort(arr, arr+4, compare);

    // for(int i=0; i<4; i++){
    //     cout<<arr[i].st<<" :"<<arr[i].et<<endl;
    // }

    return 0;


}