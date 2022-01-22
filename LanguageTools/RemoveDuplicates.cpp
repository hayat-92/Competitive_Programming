#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> removeDuplicates(vector<int> arr) {
//APROACH 1

//   set<int> s;
//   vector<int> v;
//   for (int i = 0; i < arr.size(); i++)
//   {
//       if(s.find(arr[i])==s.end()){
//           s.insert(arr[i]);
//           v.push_back(arr[i]);
//       }
//   }

//   return v;


//APROACH 2
vector<int> v;
sort(arr.begin(), arr.end());
v.push_back(arr[0]);

for(int i=1; i<v.size(); i++){
    if(arr[i]!=arr[i-1]){
        v.push_back(arr[i]);
    }
}

return v;
  

}

