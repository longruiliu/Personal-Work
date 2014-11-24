#include<iostream>

using namespace std;

class Solution {
    public:
        int removeElement(int A[], int n, int elem) 
        {
            int index = 0;
            for (int i = 0;i < n;i++)
            {
                if (elem != A[i])
                {
                    swap(A[i],A[index]);
                    index++;
                }
            }
            return index;
        }
};

int main()
{
    int A[100];
    int n,element;
    cin>>n;
    cout<<"numbers:"<<endl;
    for (int i = 0;i < n;i++)
        cin>>A[i];
    cout<<"element:"<<endl;
    cin>>element;
    Solution result;
    cout<<result.removeElement(A,n,element)<<endl;

    return 0;
}
