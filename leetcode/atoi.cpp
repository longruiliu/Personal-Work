#include<iostream>
#include<limits.h>
#include<string.h>

using namespace std;

class Solution {
    public:
        int atoi(const char *str) 
        {
            int index = 0,length = strlen(str);
            char data[100];
            if (0 == length)
                return 0;
            for (int i = 0;i < length;i++)
            {
                if (' ' == str[i]&&0 == index)
                    continue;
                else if ('0' <= str[i]&&str[i] <= '9')
                {
                    data[index] = str[i];
                    index++;
                }
                else if ('-' == str[i]||'+' == str[i])
                {
                    if (0 == index)
                    {
                        data[index] = str[i];
                        index++;
                    }
                    else
                        return 0;
                }
                else
                    break;
            }
            if (0 == index)
                return 0;
            return (int)compute(data,index);
        }
        double compute(char data[],int length)
        {
            double sum = 0.0;
            if ('+' == data[0])
                data[0] = '0';
            if ('-' == data[0])
            {
                for (int i = 1;i < length;i++)
                {
                    sum = sum * 10 - (data[i] - '0');
                    if (sum < INT_MIN)
                        return INT_MIN;
                }
            }
            else
            {
                for (int i = 0;i < length;i++)
                {
                    sum = sum * 10 + (data[i] - '0');
                    if (sum > INT_MAX)
                        return INT_MAX;
                }
            }
            return sum;
        }
};

int main()
{
    Solution result;
    char test[] = " 214748364a";
    cout<<result.atoi(test)<<endl;
    return 0;
}
