#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n1,n2, n3;
    cin>>n1>>n2>>n3;

    int *l1=new int[n1];
    int *l2=new int[n2];
    int *l3=new int[n3];

    for(int i=0; i<n1; i++){
        cin>>l1[i];
    }

    for(int i=0; i<n2; i++){
        cin>>l2[i];
    }

    for(int i=0; i<n3; i++){
        cin>>l3[i];
    }
    int j=0;

    int *lFinal=new int[n1+n2+n3];

    for(int i=0; i<n1; i++){
        lFinal[j++]=l1[i];
    }

    for(int i=0; i<n2; i++){
        lFinal[j++]=l2[i];
    }

    for(int i=0; i<n3; i++){
        lFinal[j++]=l3[i];
    }

    int nf=n1+n2+n3;


    sort(lFinal, (lFinal+nf));
    vector<int> v;
    for(int i=0; i<nf;){
        int j=i+1;
        int elem=lFinal[i];
        while(true){
            if(elem==lFinal[j]){
                j++;
            }else{
                break;
            }
        }
        int num=j-i;
        if(num>1){
            v.push_back(elem);
        }
        i=j;
    }


    cout<<v.size()<<endl;
    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++){
        cout<<*it<<endl;
    }

}