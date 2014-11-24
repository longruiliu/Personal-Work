#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
}*PList;

class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) 
        {
            if (NULL == head)
                return head;
            ListNode *p_first,*p_second;
            p_second = head;
            p_first = head->next;
            while (NULL != p_first)
            {
                if (p_second->val == p_first->val)
                {
                    ListNode *tmp = p_first;
                    p_first = p_first->next;
                    p_second->next = p_first;
                    free(tmp);
                }
                else
                {
                    p_second = p_first;
                    p_first = p_first->next;
                }
            }
            return head;
        }
};

void build_list(PList &head)
{
    cout<<"Create a list ,end with -1:"<<endl;
    head = (PList)malloc(sizeof(ListNode));
    if (NULL == head)
    {
        cout<<"create list error!"<<endl;
        return;
    }
    head->next = NULL;
    int val;
    cin>>val;
    while (-1 != val)
    {
        ListNode *tmp = new ListNode(val);
        if (NULL == tmp)
        {
            cout<<"create list error!"<<endl;
            return;
        }
        tmp->next = head->next;
        head->next = tmp;
        cin>>val;
    }
}

void print_list(PList &head)
{
    ListNode *p = head->next;
    while (NULL != p)
    {
        cout<<p->val<<"\t";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    ListNode *List;
    build_list(List);
    cout<<"before:"<<endl;
    print_list(List);
    Solution result;
    result.deleteDuplicates(List);
    cout<<"after:"<<endl;
    print_list(List);
    
    return 0;
}
