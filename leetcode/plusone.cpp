#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits)
        { 
            int flag = 1,length = digits.size();
            int i;
            for (i = length - 1;i >= 0;i--)
            {
                if (9 == digits[i])
                {
                    digits[i] = 0;
                    continue;
                }
                else
                {
                    digits[i] += flag;
                    break;
                }
            }
            if (i < 0)
            {
                digits.insert(digits.begin(),1);
            }

            return digits;
        }
};

void input_num(vector<int> &data)
{
    cout<<"input the number:"<<endl;
    int n;
    cin>>n;
    while (-1 != n)
    {
        data.push_back(n);
        cin>>n;
    }
}

void print_num(vector<int> &data)
{
    cout<<"The number are:"<<endl;
    for (int i = 0;i < data.size();i++)
        cout<<data[i];
    cout<<endl;
}

int main()
{
    vector<int> data;
    input_num(data);
    print_num(data);
    Solution result;
    result.plusOne(data);
    print_num(data);

    return 0;
}
