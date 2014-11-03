#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
/*    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int> > result;
        if (numRows == 0)
            return result;
        vector<int> one;
        one.push_back(1);
        result.push_back(one);
        if (numRows == 1)
            return result;
        else
        {
            for (int i = 1;i < numRows;i++)
                result.push_back(get_n_row(result[i - 1],i + 1));

            return result;
        }
    }
    vector<int> get_n_row(vector<int> row,int n)
    {
        vector<int> tmp;
        tmp.push_back(1);
        for (int i = 1;i < n - 1;i++)
            tmp.push_back(row[i - 1] + row[i]);
        tmp.push_back(1);
        
        return tmp;
    }*/
    public:
    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int> > result;
        for (int i = 0;i < numRows;i++)
            result.push_back(getRow(i));

        return result;
    }
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        result.push_back(1);
        for (int i = 1;i <= rowIndex;i++)
            result.push_back(result[i - 1] * 1.0 * (rowIndex - i + 1) / i);
                                                       
        return result;
    }
};

int main()
{

    Solution result;
    int num;
    cin>>num;
    vector<vector<int> > data = result.generate(num);
    for (int i = 0;i < data.size();i++)
    {
        for (int j = 0;j < data[i].size();j++)
            cout<<data[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
