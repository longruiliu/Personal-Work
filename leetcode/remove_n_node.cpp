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
        ListNode *removeNthFromEnd(ListNode *head, int n) 
        {
            ListNode *p,*p_prev,*q;
            p_prev = p = q = head;
            int i = 0;
            if (NULL == head)
                return head;
            for (i = 0;i < n - 1&&NULL != q->next;i++)
                q = q->next;
            if (i < n - 1 && NULL == q->next)
                return head;
            while(NULL != q->next)
            {
                p_prev = p;
                p = p->next;
                q = q->next;
            }
            if (p == head)
            {
                head = head->next;
                free(p);
            }
            else
            {
                p_prev->next = p->next;
                free(p);
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

void print_list_two(PList head)
{
    ListNode *p = head;
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
    int n;
    cin>>n;
    build_list(List);
    cout<<"before:"<<endl;
    print_list(List);
    Solution result;
    cout<<"after:"<<endl;
    print_list_two(result.removeNthFromEnd(List->next,n));
    
    return 0;
}
