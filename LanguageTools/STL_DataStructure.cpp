#include<iostream>
#include<vector>

#include<string>
#include<utility>
#include<set>
#include<map>
using namespace std;

int main(){

    //VECTORS

    // vector<int> v(5);
    // vector<int> v;

    // for(int i=0; i<5; i++){
    //     v.push_back(i+1);
    // }

    // for(int i=0; i<v.size(); i++){
    //     v[i]=i+1;
    // }

    // vector<int>::iterator it;
    // for(it=v.begin(); it!=v.end(); it++){
    //     cout<<*it<<endl;
    // }

    //
    string s= "Faisal";
    string s1(s, 2,3);
    cout<<s[2]<<endl;
    cout<<s1<<endl;
    cout<<&s<<endl;
    cout<<s.find('f')<<endl;
    // cout<<s.end()<<endl;


    string s2=s.substr(2,1);
    cout<<s2<<endl;


    // if(s1.compare(s2)==0){
    //     cout<<s1<<" is equal to "<< s2<<endl;
    // }else{
    //     cout<<s1<<" is not equal to "<< s2<<endl;
    // }


    // PAIR

    // pair<int, char> p;
    // p=make_pair(2, 'b');
    // pair<int, char> p2(1, 'a');
    // cout<<p.first<<" "<<p.second<<endl;
    // cout<<p2.first<<" "<<p2.second<<endl;



    //SET

    // set<int> s;
    // int arr[]={1,2,3,4,5,6,5};

    // for(int i=0; i<7; i++){
    //     s.insert(arr[i]);
    // }

    // set<int>::iterator it;
    // for(it=s.begin(); it != s.end(); it++){
    //     cout<<*it<<endl;
    // }

    // if(s.find(7)==s.end()){
    //     cout<<"Element not found"<<endl;
    // }else{
    //     cout<<"Element found"<<endl;
    // }


    //MAP

    // int arr[]={1,2,3,4,5,6,5};
    // map<int, int> m;
    // for(int i=0; i<7; i++){
    //     cout<<"faisal "<<m[arr[i]]<<"  "<<endl;
    //     m[arr[i]]=m[arr[i]]+1;
    // }

    // map<int, int>::iterator it;
    // for(it=m.begin(); it!=m.end(); it++){
    //     cout<<(*it).first<<" :"<<(*it).second<<endl;
    // }

    // cout<<endl;
    // m.erase(1);
    // for(it=m.begin(); it!=m.end(); it++){
    //     cout<<(*it).first<<" :"<<(*it).second<<endl;
    // }

    return 0;
}