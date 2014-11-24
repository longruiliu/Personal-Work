#include<iostream>
#include<string.h>

using namespace std;

class Solution {
    public:
        int strStr(char *haystack, char *needle) 
        {
            int ha_length = strlen(haystack);
            int ne_length = strlen(needle);
            if (0 == ne_length)
                return 0;
            for (int i = 0;i < ha_length;i++)
                if (haystack[i] == needle[0] && is_sub(i,haystack,needle))
                        return i;

            return -1;
        }
        bool is_sub(int index,char *s1,char *s2)
        {
            int s1_length = strlen(s1);
            int s2_length = strlen(s2);
            if (s2_length > s1_length - index)
                return false;
            for (int i = 0;i < s2_length;i++)
                if (s1[i + index] != s2[i])
                    return false;
            return true;
        }
};

int main()
{
    char s1[] = "a";
    char s2[] = "";
    Solution result;
    cout<<result.strStr(s1,s2)<<endl;


    return 0;
}
