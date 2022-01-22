#include<iostream>
using namespace std;

int partition(int *arr, int st, int en){
    int count=0;
    for(int i=st+1; i<=en; i++){
        if(arr[i]<arr[st]){
            count++;
        }
    }

    int c=st+count;

    int temp=arr[c];
    arr[c]=arr[st];
    arr[st]=temp;

    int i=st; 
    int j=en;
    while(i<c && j>c){
        if(arr[i]>=arr[c] &&arr[j]<arr[c]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }else if(arr[i]>=arr[c]){
            j--;
        }else if(arr[j]<arr[c]){
            i++;
        }else{
            i++;
            j--;
        }
    }

    return c;
}

void quick(int *arr, int st, int en){
    if(st>=en){
        return;
    }

    int c=partition(arr, st, en);
    quick(arr, st, c-1);
    quick(arr, c+1, en);
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        quick(arr, 0, n-1);

        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}