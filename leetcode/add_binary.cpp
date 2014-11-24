#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) 
        {
            int a_length = a.length();
            int b_length = b.length();
            string result(max(a_length,b_length) + 1,'0');
            int i,j,k,flag = 0;
            i = a_length - 1;
            j = b_length - 1;
            k = result.length() - 1;
            while (i >= 0&&j >= 0)
            {
                int sum = (a[i] - '0') + (b[j] - '0') + flag;
                if (sum > 1)
                {
                    result[k] = sum % 2 + '0';
                    flag = 1;
                }
                else
                {
                    result[k] = sum + '0';
                    flag = 0;
                }
                i--;
                j--;
                k--;
            }
            if (i < 0)
            {
                while (j >= 0)
                {
                    int sum = (b[j] - '0') + flag;
                    if (sum > 1)
                    {
                        result[k] = sum % 2 + '0';
                        flag = 1;
                    }
                    else
                    {
                        result[k] = sum + '0';
                        flag = 0;
                    }
                    j--;
                    k--;
                }
            }
            if (j < 0)
            {
                while (i >= 0)
                {
                    int sum = (a[i] - '0') + flag;
                    if (sum > 1)
                    {
                        result[k] = sum % 2 + '0';
                        flag = 1;
                    }
                    else
                    {
                        result[k] = sum + '0';
                        flag = 0;
                    }
                    i--;
                    k--;
                }
            }
            if (1 == flag)
            {
                result[k] = '1';
                return result;
            }
            else
            {
                result.erase(0,1);
                return result;
            }
        }
};

int main()
{
    string s,t;
    cin>>s;cin>>t;
    Solution result;
    cout<<result.addBinary(s,t)<<endl;;

    return 0;
}
