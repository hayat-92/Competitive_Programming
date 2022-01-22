#include <iostream>
using namespace std;

int allIndecies(int input[], int size, int x, int output[]){
    if(size==0){
        return 0;
    }

    int index=allIndecies(input+1, size-1, x, output);

    for(int i=0; i<index; i++){
        output[i]++;
    }

    if(input[0]==x){
        for(int i=index-1; i>=0; i--){
            output[i+1]=output[i];
        }
        output[0]=0;
        return index+1;
    }else{
        return index;
    }
}

int main(){
    // int arr[]={21, 22, 46, 12, 61, 25, 33,25,25, 16, 99, 96, 25};
    int arr[]={9, 8, 10, 8, 8};
    int output[3];
    // cout<<output<<endl;
    int num=allIndecies(arr, 5, 8, output);
    for(int i=0; i<num; i++){
        cout<<output[i]<<" ";
    }

    // cout<<output<<endl;
}