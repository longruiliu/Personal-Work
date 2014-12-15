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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
        {
            if (NULL == headA || NULL == headB)
                return NULL;
            int data[10000],index = 0,i = 0;
            ListNode *p = headA;
            while (p)
            {
                data[index] = p->val;
                index++;
                p->val += 1;
                p = p->next;
            }
            dealList(headB,-1);
            p = headA;
            while (p)
            {
                if ((p->val - 1) != data[i])
                    break;
                p = p->next;
                i++;
            }
            dealList(headA,-1);
            dealList(headB,1);
            if (i == index)
                return NULL;
            else
            {
                p = headA;
                for (int j = 0;j < i;j++)
                    p = p->next;
                return p;
            }
        }
        void dealList(ListNode *head,int val)
        {
            ListNode *p = head;
            while (p)
            {
                p->val += val;
                p = p->next;
            }
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

void join_list(PList &head1,PList &head2,PList head)
{
    ListNode *p = NULL,*q = NULL;
    p = head1;q = head->next;
    while (p->next)
        p = p->next;
    while (q)
    {
        p->next = q;
        q = q->next;
        p = p->next;
    }

    p = head2;q = head->next;
    while (p->next)
        p = p->next;
    while (q)
    {
        p->next = q;
        q = q->next;
        p = p->next;
    }
}

int main()
{
    ListNode *List1,*List2,*List_com;
    build_list(List1);
    build_list(List2);
    build_list(List_com);
    join_list(List1,List2,List_com);

    cout<<"List1:"<<endl;
    print_list(List1);
    cout<<"List2:"<<endl;
    print_list(List2);

    Solution result;
    ListNode *p = result.getIntersectionNode(List1,List2);
    if (p)
        cout<<p->val<<endl;
    
    return 0;
}
