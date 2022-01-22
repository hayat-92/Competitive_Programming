#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//  */

int pairSum(ListNode *head)
{
    vector<int> vt;
    ListNode *temp=head;
    while(temp!=0){
        vt.push_back(temp->val);
        temp=temp->next;
    }

    int maxVal=INT_MIN;
    int n=vt.size();
    for(int i=0; i<vt.size(); i++){
        int v1=vt[i];
        int v2=vt[(n-1-i)];
        maxVal=max((v1+v2), maxVal);
    }

    return maxVal;
}

int main()
{
    return 0;
}