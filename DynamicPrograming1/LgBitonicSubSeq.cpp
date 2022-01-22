#include<iostream>
using namespace std;

int lbs(int *input, int n){
    int *inc=new int[n];
    inc[0]=1;
    int *dec=new int[n];
    dec[n-1]=1;
    for(int i=1; i<n; i++){
        inc[i]=1;
        for(int j=i-1; j>=0; j--){
            if(input[j]>=input[i]){
                continue;
            }

            int pos=inc[j]+1;
            if(inc[i]<pos){
                inc[i]=pos;
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        dec[i]=1;
        for(int j=i+1; j<n; j++){
            if(input[j]>=input[i]){
                continue;
            }

            int pos=dec[j]+1;
            if(dec[i]<pos){
                dec[i]=pos;
            }
        }
    }

    int best=0;
    for(int i=0; i<n; i++){
        int pos=inc[i]+dec[i]-1;
        if(pos>best){
            best=pos;
        }
    }

    delete [] inc;
    delete [] dec;

    return best;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *input=new int[n];
        for(int i=0; i<n; i++){
            cin>>input[i];
        }

        cout<<lbs(input,n)<<endl;

        delete [] input;

    }
    return 0;
}