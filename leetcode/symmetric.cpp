#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*Tree;

class Solution {
    public:
        bool isSymmetric(TreeNode *root)
        {
            if (NULL == root)
                return true;
            reverseTree(root->left);
            if (isSameTree(root->left,root->right))
            {
                reverseTree(root->left);
                return true;
            }
            else
            {
                reverseTree(root->left);
                return false;
            }
        }
        void reverseTree(TreeNode *root)
        {
            if (NULL == root)
                return;
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            reverseTree(root->left);
            reverseTree(root->right);
        }
        bool isSameTree(TreeNode *p,TreeNode *q) 
        {
            if (NULL == p && NULL == q)
                return true;
            if ((NULL == p && NULL != q) || (NULL != p && NULL == q))
                return false;
            if (p->val != q->val)
                return false;
            if (!isSameTree(p->left,q->left))
                return false;
            if (!isSameTree(p->right,q->right))
                return false;

            return true;
        }
};

void build_tree(Tree &T)
{
    int data;
    cin>>data;
    if (-1 != data)
    {
        Tree tmp = new TreeNode(data);
        T = tmp;
        build_tree(T->left);
        build_tree(T->right);
    }
}

void print_tree(Tree &root)
{
    if (NULL != root)
    {
        print_tree(root->left);
        cout<<root->val<<"   ";
        print_tree(root->right);
    }
}

int main()
{
    Tree T = NULL,S = NULL;
    cout<<"tree 1:"<<endl;
    build_tree(T);
    Solution result;
    cout<<result.isSymmetric(T)<<endl;
    print_tree(T);
    cout<<endl;

    return 0;
}
