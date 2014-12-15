#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int findPeakElement(const vector<int> &num) 
        {
            if (num.empty()||1 == num.size())
                return 0;
            int length = num.size();
            if (num[0] > num[1])
                return 0;
            if (num[length - 1] > num[length - 2])
                return length - 1;
            for (int i = 1; i < length - 1;i++)
                if (num[i] > num[i - 1]&&num[i] > num[i + 1])
                    return i;
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
    cout<<result.findPeakElement(data)<<endl;

    return 0;
}
