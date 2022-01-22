#include<iostream>
#include<algorithm>
using namespace std;

int Kadane(int *arr, int n){
    int best_sum=0;
    int current_sum=0;
    for(int i=0; i<n; i++){
        current_sum=current_sum+arr[i];
        if(best_sum<current_sum){
            best_sum=current_sum;
        }

        if(current_sum<0){
            current_sum=0;
        }
    }

    return best_sum;
}

int maxSumRect(int **mat, int m, int n){
    int maxRect=INT_MIN;
    int *arr=new int[m];
    for(int t=0; t<m; t++){
        arr[t]=0;
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=0; k<m; k++){
                arr[k]+=mat[j][k];
            }
            int currmax=Kadane(arr, m);
            maxRect=max(currmax, maxRect);
        }
        for(int t=0; t<m; t++){
            arr[t]=0;
        }
    }

    return maxRect;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>n>>m;
        int **mat=new int*[n];
        for(int i=0; i<n; i++){
            mat[i]=new int[m];
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        cout<<maxSumRect(mat, m, n)<<endl;
    }
    return 0;
}