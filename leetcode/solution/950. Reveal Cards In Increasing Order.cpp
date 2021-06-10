#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        vector<int> result(deck.size());

        sort(deck.begin(), deck.end());

        int start = JOSP(deck.size(), 3);
        result[start] = deck.back();

        return result;
    }

    int JOSP(int n, int m)
    {
        // 返回该数在原数组中的下标，从 0 开始
        int x = 0;
        for (int i = 1; i < n; ++i)
            x = (x + m % (i + 1)) % (i + 1);
        return x;
    }

    int getOriginalIndex(int turn, int n, int m)
    {
        // 该元素是在 JOSP(n, m) 问题中第 turn 轮（从 1 开始）中被剔除出去的
        
    }
};