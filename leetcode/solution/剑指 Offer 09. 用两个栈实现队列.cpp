#include <stack>
using namespace std;

class CQueue
{
private:
    stack<int> st1;
    stack<int> st2;
    int size;

public:
    CQueue()
    {
        size = 0;
    }

    void appendTail(int value)
    {
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }

        st1.push(value);
        ++size;
    }

    int deleteHead()
    {
        if (size == 0)
            return -1;
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st2.top();
        --size;
        st2.pop();
        return temp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */