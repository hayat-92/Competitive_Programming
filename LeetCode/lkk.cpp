#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int length(node *head)
{
    int count = 0;
    // node *temp=head;
    while (head != NULL)
    {
        count++;
        head = (head)->next;
    }
    return count;
}
bool check_palindrome(node *head)
{
    node *temp=head;
    int l = length(temp);
    node *t1 = head;
    int mid = l / 2;
    bool isPalindrome = true;

    for (int i = 0; i <= mid; i++)
    {
        t1 = t1->next;
    }
    node *t2 = NULL;
    t2 = t1->next;
    t1->next = NULL;
    while (t2->next != NULL)
    {
        if (t2->data == t1->data)
        {
            isPalindrome = true;
        }
        else
        {
            isPalindrome = false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return isPalindrome;
}