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
        bool hasPathSum(TreeNode *root, int sum)
        {
            if (NULL == root)
                return false;
            if (NULL == root->left && NULL == root->right)
                if (sum == root->val)
                {
                    result = true;
                    return result;
                }
            if (result)
                return result;
            if (NULL != root->left)
                hasPathSum(root->left,sum - root->val);
            if (NULL != root->right)
                hasPathSum(root->right,sum - root->val);

            return result;
        }
       bool result;
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
        cout<<root->val<<"   ";
        print_tree(root->left);
        print_tree(root->right);
    }
}

int main()
{
    Tree T = NULL;
    build_tree(T);
    print_tree(T);
    cout<<endl;
    int sum;
    cin>>sum;
    Solution result;
    cout<<result.hasPathSum(T,sum)<<endl;

    return 0;
}
