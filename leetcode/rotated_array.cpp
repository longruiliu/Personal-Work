#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int findMin(vector<int> &num) 
        {
            if (num.empty())
                return 0;
            int length = num.size();
            for (int i = 0;i < length - 1;i++)
                if (num[i + 1] < num[i])
                    return num[i + 1];
            return num[0];
        }
};

int main()
{
    Solution result;
    int n;
    vector<int> data;
    cin>>n;
    while (-1 != n)
    {
        data.push_back(n);
        cin>>n;
    }
    cout<<result.findMin(data)<<endl;

    return 0;
}
