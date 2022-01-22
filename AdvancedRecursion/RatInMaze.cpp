#include<iostream>
using namespace std;

void rat(int r, int c, int n, int **In, int **Out){

    if(r<0 || r>=n || c<0 || c>=n){
        return;
    }
    if(In[r][c]==0){
        return;
    }

    if(Out[r][c]==1){
        return;
    }

    if(In[r][c]==1){
        Out[r][c]=1;
    }

    if(r==n-1 && c==n-1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<Out[i][j]<<" ";
            }
        }
        cout<<endl;
        Out[r][c]=0;
        return;
    }


    rat(r, c+1, n, In, Out);
    // Out[r][c+1]=0;
    rat(r+1, c,n, In, Out);
    // Out[r+1][c]=0;
    rat(r, c-1, n, In, Out);
    // Out[r][c-1]=0;
    rat(r-1, c, n, In, Out);
    // Out[r-1][c]=0;
    Out[r][c]=0;

    
}

int main(){
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0; i<n; i++){
        int *v=new int[n];
        for(int j=0; j<n; j++){
            cin>>v[j];
        }

        arr[i]=v;
    }

    int **Out=new int*[n];
    for(int i=0; i<n; i++){
        int *v=new int[n];
        for(int j=0; j<n; j++){
            v[j]=0;
        }
        Out[i]=v;
    }

    rat(0, 0, n, arr, Out);


    return 0;
}