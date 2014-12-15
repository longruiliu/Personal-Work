#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
    public:
        int romanToInt(string s) 
        {
            map<char,int> data;
            data['I'] = 1;
            data['V'] = 5;
            data['X'] = 10;
            data['L'] = 50;
            data['C'] = 100;
            data['D'] = 500;
            data['M'] = 1000;

            int sum = 0;
            int length = s.length();
            for (int i = 0;i < length - 1;i++)
            {
                if (data[s[i + 1]] > data[s[i]])
                    sum -= data[s[i]];
                else 
                    sum += data[s[i]];
            }
            sum += data[s[length - 1]];

            return sum;
        }
};

int main()
{
    Solution test;
    string num;
    cin>>num;
    cout<<test.romanToInt(num)<<endl;

    return 0;
}
