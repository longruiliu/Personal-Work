#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) 
        {
            if (0 == strs.size())
                return "";
            if (isCommon(strs[0],strs))
                return strs[0];
            int begin = 0,end = strs[0].length() - 1;
            string prefix;
            while (begin < end)
            {
                int mid = (begin + end) / 2;
                prefix = strs[0].substr(0,mid + 1);
                if (isCommon(prefix,strs))
                {
                    if (isCommon(strs[0].substr(0,mid + 2),strs))
                        begin = mid + 1;
                    else
                        return prefix;
                }
                else
                    end = mid;
            }
            return "";
        }
        bool isCommon(string prefix,vector<string> &strs)
        {
            int length = strs.size();
            for (int i = 0;i < length;i++)
            {
                for (int j = 0;j < prefix.length();j++)
                    if (prefix[j] != strs[i][j])
                        return false;
            }
            return true;
        }
};

int main()
{
    vector<string> test;
    string s1 = "abc";
    //string s2 = "acc";
    //string s3 = "ccc";
    //string s2 = "";
    string s2;
    cin>>s2;
    test.push_back(s1);
    test.push_back(s2);
    Solution result;
    cout<<result.longestCommonPrefix(test)<<endl;

    return 0;
}
