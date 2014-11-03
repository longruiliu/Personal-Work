#include<string>
#include<iostream>

using namespace std;

class Solution
{
    public:bool isPalindrome(string s)
           {
               if (s.length() == 0||s.length() == 1)
                   return true;
               int i= 0,j = s.length() - 1;
               while (i != s.length())
               {
                   if (!isAlphaNumberic(s[i]))
                   {
                       i++;
                       continue;
                   }
                   else if (!isAlphaNumberic(s[j]))
                   {
                       j--;
                       continue;
                   }
                   else
                   {
                       if (i == j)
                           return true;
                       //whether s[i] and s[j] are same,ignore cases
                       if (!(s[i] == s[j] || (s[i] - s[j]) == 32||(s[j] - s[i]) == 32))
                           return false;
                       i++;
                       j--;
                   }
               }
               if (i == s.length())
                   return true;
           }
    public:bool isAlphaNumberic(char c)
           {
               if ((c >= 'a'&&c <= 'z')||(c >= 'A')&&c <= 'Z')
                   return true;
               else if(c >= '0' && c <= '9')
                   return true;
               else 
                   return false;
           }
};

int main()
{
    //string test = "A man, a plan, a canal: Panama";
    string test = "...a";

    Solution result;
    cout<<result.isPalindrome(test)<<endl;

    return 0;
}
