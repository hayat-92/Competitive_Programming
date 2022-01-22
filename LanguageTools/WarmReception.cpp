#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int *dep=new int[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>dep[i];								
    }
    
    sort(arr,arr+n);
    sort(dep,dep+n);
    int j=0,chairs=0;
    for(int i=0;i<n;i++)
    {
		if(arr[i]<dep[j])
        {
			chairs++;
            continue;
        }
        j++;
    }
    
    cout<<chairs<<'\n';
}