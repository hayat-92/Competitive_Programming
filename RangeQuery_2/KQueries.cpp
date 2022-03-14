#include <iostream>
#include <vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
struct event
{
// public:
    int left, right, index;
    ll value;
    // event(int left, int right, int value, int index)
    // {
    //     left = left;
    //     right=right;
    //     value=value;
    //     index=index;
    // }
};

bool compare(event a, event b){
    if(a.value>b.value){
        return true;
    }else if(a.value==b.value){
        return a.left>b.left;
    }else{
        return false;
    }
}

int query(int right, int *bit, int n){
    int sum=0;
    for(; right>0; ){
        sum+=(bit[right]);
        right-=(right&(-right));
    }

    return sum;
}

void update(int right, int *bit, int N ){
    for(; right<=N;){
        bit[right]++;
        right+=(right&(-right));
    }
}
int main()
{

    int N;
    cin >> N;
    ll *arr = new ll[N+1];
    for (int i = 1; i <N+1; i++)
    {
        cin >> arr[i];
    }

    int Q;
    cin >> Q;
    vector<event> *queries = new vector<event>();

    for (int i = 1; i <=Q; i++)
    {
        // cout<<"fai"<<endl;
        event x;
        cin>>x.left>>x.right>>x.value;
        x.index=i;
        queries->push_back(x);
    }

    for(int i=1; i<=N; i++){
        event x;
        x.left=0;
        x.right=i;
        x.value=arr[i];
        x.index=i;
        queries->push_back(x);
    }

    sort(queries->begin(), queries->end(), compare);

    // cout<<"khan"<<endl;

    // for(int i=0; i<queries->size(); i++){
    //     event e=queries->at(i);
    //     cout<<e.left<<" "<<e.right<<" "<<e.value<<endl;
    // }

    int *bit=new int[N+1]();

    

    vector<pair<int, int>> *fnl=new vector<pair<int, int>>();

    for(int i=0; i<queries->size(); i++){
        event e=queries->at(i);
        if(e.left!=0){
            int ans=query(e.right, bit, N)-query(e.left-1, bit, N);
            // cout<<ans<<endl;
            fnl->push_back({e.index, ans});
            // cout<<query(e.right, bit, N)-query(e.left-1, bit, N)<<endl;

        }else{
            update(e.right, bit, N);
        }
    }

    sort(fnl->begin(), fnl->end());

    for(int i=0; i<fnl->size(); i++){
        cout<<fnl->at(i).second<<endl;
    }

    



    return 0;
}