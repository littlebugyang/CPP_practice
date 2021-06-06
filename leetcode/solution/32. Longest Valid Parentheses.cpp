#include <string>
#include <algorithm>
using std::max;
using std::string;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() == 0)
            return 0;

        int lastCount = 0; // 记录上次栈大小为 0 之前的已匹配的括号数
        int count = 0;
        int maxCount = 0;
        int stackSize = int(s[0] == '('); // 如果遇到了 '(' 就加 1，表示栈中有 '('
        int left = stackSize - 1;
        int nPair = 0; // 记录距离上次栈大小为 0 的时候已匹配的括号对数
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == ')') // 此时栈中最好有个 '('
            {
                if (stackSize == 0) // 失配
                {
                    lastCount = count = 0; // count 不能延续
                }
                else
                {
                    count += 2;
                    if (stackSize == 1) // 恰好栈为 0
                    {
                        lastCount = (count += lastCount);
                        maxCount = max(maxCount, lastCount);
                        count = 0;
                    }
                    --stackSize;
                }
            }
            else // 是一个 '('
            {
                ++stackSize;
            }
        }

        // 栈中如果还剩余左括号
        if (stackSize > 0)
        {
            // 则要统计该阶段的 count
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};