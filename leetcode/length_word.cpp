#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(const char *s)
        {
            int length = strlen(s);
            int i = length - 1,result = 0;
            while (' ' == s[i] && i >= 0)
            {
                i--;
            }
            if (i < 0)
                return 0;
            else
            {
                while (' ' != s[i] && i >= 0)
                {
                    result++;
                    i--;
                }
            }
            return result;
        }
};

int main()
{
    char s[100]= "aa   bbb    ";
    Solution result;
    cout<<result.lengthOfLastWord(s)<<endl;

    return 0;
}
