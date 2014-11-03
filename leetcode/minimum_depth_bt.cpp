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
        int minDepth(TreeNode *root)
        {
            if (NULL == root)
                return 0;
            if (NULL == root->left && NULL == root->right)
            {
                _current_depth++;
                if (_current_depth < _min_depth)
                    _min_depth = _current_depth;
                _current_depth--;
            }
            if (NULL != root->left)
            {
                _current_depth++;
                minDepth(root->left);
                _current_depth--;
            }
            if (NULL != root->right)
            {
                _current_depth++;
                minDepth(root->right);
                _current_depth--;
            }
            return _min_depth;
        }
        int _min_depth,_current_depth;
        Solution()
        {
            _min_depth = 10000;
            _current_depth = 0;
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
    cout<<result.minDepth(T)<<endl;

    return 0;
}
