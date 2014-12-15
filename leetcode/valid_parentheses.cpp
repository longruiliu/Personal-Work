#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
        bool isValid(string s)
        {
            if (s.empty())
                return true;
            int length = s.length();
            vector<char> my_stack;
            for (int i = 0;i < length;i++)
            {
                if (0 == my_stack.size())
                {
                    my_stack.push_back(s[i]);
                    continue;
                }
                int tmp = s[i] - my_stack.back();
                if (1 == tmp||2 == tmp)
                    my_stack.pop_back();
                else
                    my_stack.push_back(s[i]);
            }
            if (0 == my_stack.size())
                return true;
            else 
                return false;
        }
};

int main()
{
    string test;
    cin>>test;
    Solution result;
    cout<<result.isValid(test)<<endl;
    return 0;
}
