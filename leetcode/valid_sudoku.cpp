#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) 
        {
            int pivot[] = {0,3,6};
            for (int i = 0;i < 9;i++)
                if (!isLineValid(board[i]))
                    return false;
            for (int i = 0;i < 9;i++)
            {
                vector<char> tmp;
                for (int j = 0;j < 9;j++)
                    tmp.push_back(board[j][i]);
                if (!isLineValid(tmp))
                    return false;
            }
            for (int i = 0;i < 3;i++)
                for (int j = 0;j < 3;j++)
                    if (!isSubSu(board,pivot[i],pivot[j]))
                        return false;
            return true;
        }
        bool isLineValid(vector<char> line)
        {
            char mark[] = {"0000000000"};
            for (int i = 0;i < 9;i++)
            {
                if ('.' == line[i])
                    continue;
                mark[(line[i] - '0')] = (mark[(line[i] - '0')] - '0') + 1 + '0';
            }
            for (int i = 1;i <= 9;i++)
                if ((mark[i] - '0') > 1)
                    return false;
            return true;
        }
        bool isSubSu(vector<vector<char> > &board,int m,int n)
        {
            char mark[] = {"0000000000"};
            for (int i = m;i < m + 3;i++)
                for (int j = n;j < n + 3;j++)
                {
                    if ('.' == board[i][j])
                        continue;
                    mark[(board[i][j] - '0')] = (mark[(board[i][j] - '0')] - '0') + 1 + '0';
                }
            for (int i = 1;i <= 9;i++)
                if ((mark[i] - '0') > 1)
                    return false;
            return true;
        }
};

int main()
{
    Solution result;
    char data_ch[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char> > data;
    for (int i = 0;i < 9;i++)
    {
        vector<char>  tmp(data_ch[i],data_ch[i] + 9);
        data.push_back(tmp);
    }
    cout<<result.isValidSudoku(data)<<endl;
    return 0;
}

