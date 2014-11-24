#include<iostream>

using namespace std;

class Solution {
    public:
        void merge(int A[], int m, int B[], int n) 
        {
            int i = m - 1,j = n - 1,k = m + n - 1;
            while (i >= 0&&j >= 0)
            {
                if (A[i] >= B[j])
                {
                    A[k] = A[i];
                    i--;
                    k--;
                }
                else
                {
                    A[k] = B[j];
                    j--;
                    k--;
                }
            }
            if (i < 0)
            {
                while (j >= 0)
                {
                    A[k] = B[j];
                    j--;
                    k--;
                }
            }
            if (j < 0)
            {
                while (i >= 0)
                {
                    A[k] = A[i];
                    i--;
                    k--;
                }
            }
        }
};

int main()
{

    int A[50] = {20,21,22,24,25,35};
    int B[] = {12,13,14,15,16};
    int m = 6,n = 5;
    Solution result;
    result.merge(A,m,B,n);
    for (int i = 0;i < m + n;i++)
        cout<<A[i]<<"\t";
    cout<<endl;
    
    return 0;
}
