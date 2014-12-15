#include<iostream>
#include<cmath>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) 
        {
            int exp;
            if (0 == x)
                return true;
            else if (x < 0)
                return false;
            for (int i = 9;i >= 0;i--)
                if (0 != (x / (int)pow(10,i)))
                {
                    exp = i;
                    break;
                }
            while (exp > 0)
            {
                if ((x % 10) != (x / ((int)pow(10,exp))))
                    return false;
                x %= ((int)pow(10,exp));
                x /= 10;
                exp -= 2;
            }
            return true;
        }
};

int main()
{
    Solution result;
    int num;
    cin>>num;
    cout<<result.isPalindrome(num)<<endl;
    return 0;
}
