#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;

class Solution {
    public:
        int reverse(int x) 
        {
            double sum;
            if (x >= 0)
                sum = my_reverse(x);
            else
                sum = 0 - my_reverse(-x);
            if (sum > INT_MAX || sum < INT_MIN)
                return 0;
            else
                return (int)sum;
        }
        double my_reverse(int x)
        {
            vector<char> digits;
            double sum = 0.0;
            while (x)
            {
                digits.push_back((x % 10) + '0');
                x /= 10;
            }
            while(!digits.empty())
            {
                sum = sum * 10.0 + (digits.front() - '0');
                digits.erase(digits.begin());
            }
            return sum;
        }
};

int main()
{
    Solution result;
    int n;
    cin>>n;
    cout<<result.reverse(n)<<endl;

    return 0;
}
