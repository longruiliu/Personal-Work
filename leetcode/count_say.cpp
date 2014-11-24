#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    public:
        string countAndSay(int n)
        {
            vector<string> data;
            data.push_back("1");
            for (int i = 1;i < n;i++)
                data.push_back(count(data[i - 1]));

            return data[n - 1];
        }
        string count(string prev)
        {
            string result;
            int length = prev.length();
            int i = 0,count = 0;
            char pivot = prev[0];
            for (i = 0;i < length;i++)
            {
                if (pivot == prev[i])
                {
                    count++;
                    continue;
                }
                else
                {
                    result += (count + '0');
                    result += pivot;
                    pivot = prev[i];
                    count = 1;
                }
            }
            result += (count + '0');
            result += pivot;
            return result;
        }
};

int main()
{
    int test;
    cin>>test;
    Solution result;
    cout<<result.countAndSay(test)<<endl;

    return 0;
}
