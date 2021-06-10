#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int sum = 0;
        map<int, int> counts;

        for (int i = 0; i < answers.size(); ++i)
        {
            if (answers[i] == 0)
            {
                ++sum;
                continue;
            }
            if (counts[answers[i]] == 0)
            {
                counts[answers[i]] = 1;
                sum += (answers[i] + 1);
            }
            else if (counts[answers[i]] > answers[i]) // 说还有同样个数的兔子太多了，比如出现了 7 只兔子说还有 5 个自己这种色的
            {
                counts[answers[i]] = 1;
                sum += (answers[i] + 1);
            }
            else
            {
                ++counts[answers[i]];
            }
        }
        return sum;
    }
};