#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> st(temperatures.size());

        int top = 0;
        st[top] = 0;

        for (int i = 1; i < temperatures.size(); ++i)
        {
            while (top != -1)
            {
                if (temperatures[i] > temperatures[st[top]])
                {
                    temperatures[st[top]] = i - st[top];
                    --top;
                    continue;
                }
                break;
            }
            st[++top] = i;
        }

        while (top != -1)
            temperatures[st[top--]] = 0;
        return temperatures;
    }
};