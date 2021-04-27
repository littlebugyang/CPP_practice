#include <climits>
#include <algorithm>
using std::min;
class MinStack
{
private:
    int capacity;
    int size;
    int *data;
    int minVal;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        capacity = 1;
        size = 0;
        data = new int[capacity];
        minVal = INT_MAX;
    }

    ~MinStack()
    {
        delete[] data;
    }

    void push(int val)
    {
        if (size == capacity)
        {
            int *temp = new int[2 * capacity];
            for (int i = 0; i < capacity; ++i)
                temp[i] = data[i];
            capacity *= 2;
            delete[] data;
            data = temp;
        }
        data[size++] = val;
        minVal = min(minVal, val);
    }

    void pop()
    {
        if (data[size - 1] == minVal)
        {
            minVal = INT_MAX;
            for (int i = 0; i < size - 1; ++i)
                minVal = min(minVal, data[i]);
        }
        --size;
    }

    int top()
    {
        return data[size - 1];
    }

    int getMin()
    {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
