#include<iostream>

using namespace std;

class Solution {
    public:
        int climbStairs(int n) 
        {
            int  data[100];
            data[0] = 0;data[1] = 1;data[2] = 2;
            if (n < 3)
                return data[n];
            for (int i = 3;i <= n;i++)
                data[i] = data[i - 1] + data[i - 2];

            return data[n];
        }
};

int main()
{
    int n;
    cin>>n;
    Solution result;
    cout<<result.climbStairs(n)<<endl;
    return 0;
}
