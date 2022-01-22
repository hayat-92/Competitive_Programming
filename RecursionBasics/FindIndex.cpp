#include <iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
    if(size==0){
        return -1;
    }

    if(input[0]==x){
        return 0;
    }

    int num=firstIndex(input+1, size-1, x);
    if(num!=-1){
        return num+1;
    }else{
        return -1;
    }

}

int main(){
    int arr[]={1,2,3,4,5};
    cout<<firstIndex(arr, 5, 5);
}