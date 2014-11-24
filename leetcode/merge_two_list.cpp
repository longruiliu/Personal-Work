#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}*PList;

class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
        {
            if (NULL == l1 && NULL == l2)
                return NULL;
            if (NULL == l1)
                return l2;
            if (NULL  == l2)
                return l1;
            if (l1->val <= l2->val)
            {
                l1->next = mergeTwoLists(l1->next,l2);
                return l1;
            }
            else 
            {
                l2->next = mergeTwoLists(l1,l2->next);
                return l2;
            }
        }
};

void create_list(PList &head)
{
    head = (PList)malloc(sizeof(ListNode));
    if (NULL == head)
    {
        cout<<"Create list error!"<<endl;
        exit(0);
    }
    int val;
    cin>>val;
    while (-1 != val)
    {
        ListNode *tmp = new ListNode(val);
        tmp->next = head->next;
        head->next = tmp;
        cin>>val;
    }
}

void print_list(PList &head)
{
    PList p = head;
    while (NULL != p)
    {
        cout<<p->val<<"\t";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    PList head1,head2;
    cout<<"Create list1:"<<endl;
    create_list(head1);
    cout<<"Create list2:"<<endl;
    create_list(head2);
    Solution result;
    PList p_result = result.mergeTwoLists(head1->next,head2->next);
    print_list(p_result);

    return 0;
}
