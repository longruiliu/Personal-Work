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
        int maxDepth(TreeNode *root)
        {
            if (NULL == root)
                return 0;

            int l_depth = maxDepth(root->left);
            int r_depth = maxDepth(root->right);

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
    cout<<result.maxDepth(T)<<endl;

    return 0;
}
