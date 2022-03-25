#include <iostream>
using namespace std;

int fxn(int **matrix, int N, int M){
    int count=0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j){
                continue;
            }
            if(matrix[i][j]==1){
                for(int k=1; k<=N; k++){
                    if(k==j){
                        continue;
                    }
                    if(k==i){
                        continue;
                    }
                    if(matrix[j][k]==1){
                        if(matrix[k][i]==1){
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count/6;
}
int main()
{
    int N, M;
    cin>>N>>M;
    int *U=new int[M+1];
    int *V=new int[M+1];
    for(int i=1; i<=M; i++){
        cin>>U[i];
    }

    for(int i=1; i<=M; i++){
        cin>>V[i];
    }

    int **matrix=new int*[N+1];
    for(int i=1; i<=N; i++){
        matrix[i]=new int[N+1];
        for(int j=1; j<=N; j++){
            matrix[i][j]=0;
        }
    }

    for(int i=1; i<=M; i++){
        matrix[U[i]][V[i]]=1;
        matrix[V[i]][U[i]]=1;
    }

    int count=fxn(matrix, N,M);
    cout<<count<<endl;


    return 0;
}