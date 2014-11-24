#include<iostream>

using namespace std;

class Solution {
    public:
        int removeDuplicates(int A[], int n)
        {
            int index = 0;
            if (n < 2)
                return n;
            for (int i = 1;i < n;i++)
                if (A[i] != A[index])
                {
                    swap(A[index + 1],A[i]);
                    index++;
                }
            return index + 1;
        }
};

int main()
{
    int A[100];
    int n;
    cin>>n;
    cout<<"numbers:"<<endl;
    for (int i = 0;i < n;i++)
        cin>>A[i];
    Solution result;
    cout<<result.removeDuplicates(A,n)<<endl;

    return 0;
}
