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
        vector<vector<int> > levelOrderBottom(TreeNode *root) 
        {
            vector<vector<int> > result,l_child,r_child;
            vector<int> root_value;
            if (NULL == root)
                return result;
            if (NULL == root->left && NULL == root->right)
            {
                root_value.push_back(root->val);
                result.push_back(root_value);
                return result;
            }
            l_child = levelOrderBottom(root->left);
            r_child = levelOrderBottom(root->right);
            result = merge_all(l_child,r_child);
            root_value.push_back(root->val);
            result.push_back(root_value);
            
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
                    for (int j = 0; j < right[right_length - i - 1].size();j++)
                        left[left_length - i - 1].push_back(right[right_length - i - 1][j]);
            }
            else
            {
                for (int i = 0;i < left_length;i++)
                    for (int j = 0; j < right[right_length - i - 1].size();j++)
                        left[left_length - i - 1].push_back(right[right_length - i - 1][j]);
                vector<vector<int> > tmp = left;
                left.clear();
                for (int i = 0;i < right_length - left_length;i++)
                    left.push_back(right[i]);
                for (int i = 0;i < tmp.size();i++)
                    left.push_back(tmp[i]);
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
    vector<vector<int> > data = result.levelOrderBottom(T);
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
