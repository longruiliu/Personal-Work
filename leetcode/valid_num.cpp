#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Solution {
    public:
        bool isNumber(const char *s)
        {
            char t[100];
            for (int i = 0;i <= strlen(s);i++)
                t[i] = s[i];
            delete_blank(t);

            int t_length = strlen(t);
            bool num = false;
            bool exp = false;
            bool dot = false;
            for (int i = 0;i < t_length;i++)
            {
                char c = t[i];
                if ('e' == c)
                {
                    if (!num || exp)
                        return false;
                    exp = true;
                    num = false;
                }
                else if (c >= '0'&& c <= '9')
                {
                    num = true;
                }
                else if ('.' == c)
                {
                    if (dot || exp)
                        return false;
                    dot = true;
                }
                else if ('+' == c||'-' == c)
                {
                    if (0 != i&&'e' != t[i - 1])
                        return false;
                }
                else
                    return false;
            }
            return num;
        }
        void delete_blank(char *s)
        {
            int i = 0,j = 0,index = 0;
            for (;i < strlen(s);i++)
            {
                if ( ' ' == s[i])
                    continue;
                break;
            }
            for (j = strlen(s) - 1;j>=0;j--)
            {
                if (' ' == s[j])
                    continue;
                break;
            }
            for (int k = i;k <= j;k++)
            {
                s[index] = s[k];
                index++;
            }
            s[index] = '\0';
        }
};

int main()
{
    char s1[100] = "0";
    char s2[100] = " 0.1 ";
    char s3[100] = "abc";
    char s4[100] = "1 a  bd";
    char s5[100] = "2e10";
    char s6[100] = " . 1   ";

    Solution result;
    cout<<result.isNumber(s6)<<endl;

    return 0;
}
