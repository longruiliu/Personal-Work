#include<iostream>
#include<stack>

using namespace std;

/*class MinStack {
    public:
        vector<int> _my_stack;
        int _min_value[2];
        MinStack()
        {
            _min_value[0] = 0;
            _min_value[1] = 0;
        }
        void push(int x) 
        {
            _my_stack.push_back(x);
            if (x == _min_value[0])
                _min_value[1]++;
            else if (0 == _min_value[1] || x < _min_value[0])
            {
                _min_value[0] = x;
                _min_value[1] = 1;
            }
        }
        void pop() 
        {
            int top_value = top();
            _my_stack.pop_back();
            if (top_value == _min_value[0])
            {
                if (_min_value[1] > 1)
                    _min_value[1]--;
                else
                {
                    int min = _my_stack[0];
                    int count = 1;
                    int length = _my_stack.size();
                    for (int i = 1;i < length;i++)
                    {
                        if (_my_stack[i] < min)
                        {
                            min = _my_stack[i];
                            count = 1;
                        }
                        else if (min == _my_stack[i])
                            count++;
                    }
                    _min_value[0] = min;
                    _min_value[1] = count;
                }
            }
        }
        int top()
        {
            return _my_stack.back();
        }
        int getMin() 
        {
            return _min_value[0];
        }
};*/

class MinStack {
    public:
        void push(int x) 
        {
            _data.push(x);
            if (_min_data.empty() || _min_data.top() >= x)
                _min_data.push(x);
        }
        void pop()
        {
            if (!_data.empty())
            {
                if (_data.top() == _min_data.top())
                    _min_data.pop();
                _data.pop();
            }
        }
        int top() 
        {
            if (_data.empty())
                return false;
            return _data.top();
        }
        int getMin() 
        {
            if (_min_data.empty())
                return false;
           return  _min_data.top();
        }
    private:
        stack<int> _data;
        stack<int> _min_data;
};

int main()
{
    MinStack result;
    for (int i = 0;i < 10;i++)
        result.push(i);
    result.push(-1);
    result.push(-2);
    
    cout<<"before"<<endl;
    cout<<result.top()<<endl;
    cout<<result.getMin()<<endl;

    cout<<"after"<<endl;
    result.pop();
    cout<<result.getMin()<<endl;

    cout<<"after"<<endl;
    result.pop();
    cout<<result.getMin()<<endl;

    return 0;
}
