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
        bool isBalanced(TreeNode *root)
        {
            if (NULL == root)
                return true;
            if (!isBalanced(root->left) || !isBalanced(root->right))
                return  false;
            int h_left = depth(root->left);
            int h_right = depth(root->right);
            if (h_left - h_right > 1 || h_right - h_left > 1)
                return false;

            return true;
        }
        int depth(TreeNode *root)
        {
            if (NULL == root)
                return 0;

            int l_depth = depth(root->left);
            int r_depth = depth(root->right);

            return ((l_depth > r_depth) ? (l_depth + 1) : (r_depth + 1));
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
    Solution result;
    cout<<result.isBalanced(T)<<endl;

    return 0;
}
