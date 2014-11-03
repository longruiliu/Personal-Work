#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*Tree;

class Solution {
    public:
        vector<vector<int> > levelOrder(TreeNode *root) 
        {
            vector<vector<int> > result,l_child,r_child,all_child;
            vector<int> root_value;
            if (NULL == root)
                return result;
            if (NULL == root->left && NULL == root->right)
            {
                root_value.push_back(root->val);
                result.push_back(root_value);
                return result;
            }
            root_value.push_back(root->val);
            result.push_back(root_value);
            l_child = levelOrder(root->left);
            r_child = levelOrder(root->right);
            all_child = merge_all(l_child,r_child);
            for (int i = 0;i < all_child.size();i++)
                result.push_back(all_child[i]);
            
            return result;
        }
        vector<vector<int> > merge_all(vector<vector<int> > left,vector<vector<int> > right)
        {
            if (left.empty())
                return right;
            if (right.empty())
                return left;
            int left_length = left.size();
            int right_length = right.size();
            if (left_length >= right_length)
            {
                for (int i = 0;i < right_length;i++)
                    for (int j = 0; j < right[i].size();j++)
                        left[i].push_back(right[i][j]);
            }
            else
            {
                for (int i = 0;i < left_length;i++)
                    for (int j = 0; j < right[i].size();j++)
                        left[i].push_back(right[i][j]);

                for (int i = left_length;i < right_length;i++)
                    left.push_back(right[i]);
            }
            return left;
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
    vector<vector<int> > data = result.levelOrder(T);
    if (!data.empty())
    {
        for (int i = 0;i < data.size();i++)
        {
            for (int j = 0;j < data[i].size();j++)
                cout<<data[i][j]<<"  ";
            cout<<endl;
        }
    }

    return 0;
}
