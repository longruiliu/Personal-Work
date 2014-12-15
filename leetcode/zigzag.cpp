#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Solution {
    public:
        string convert(string s, int nRows)
        {
            if (1 == nRows)
                return s;
            int length = s.length(),index = 0;
            string result = "";
            char **data;
            data = (char **)malloc(nRows * sizeof(char*));
            for (int i = 0;i < nRows;i++)
            {
                data[i] = (char *)malloc(500 * sizeof(char));
                memset(data[i],' ',500);
            }
            for (int j = 0;j < 500;j++)
            {
                for (int i = 0;i < nRows;i++)
                {
                    if (index >= length)
                        break;
                    if ((0 == j % (nRows - 1))||(0 == (i + j) % (nRows - 1)))
                    {
                        data[i][j]  = s[index];
                        index++;
                    }
                }
                if (index >= length)
                    break;
            }
            for (int i = 0;i < nRows;i++)
                for (int j = 0;j < 500;j++)
                    if (' ' != data[i][j])
                        result += data[i][j];

            for (int i = 0;i < nRows;i++)
                free(data[i]);
            free(data);

            return result;
        }
};

int main()
{
    Solution result;
    string test;
    cin>>test;
    int num;
    cin>>num;
    cout<<result.convert(test,num)<<endl;
    return 0;
}
