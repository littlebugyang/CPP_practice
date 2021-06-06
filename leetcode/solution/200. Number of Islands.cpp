#include <vector>
#include <stack>
using std::stack;
using std::vector;

class Solution
{
private:
    int count;
    vector<vector<char>> grids;
    vector<vector<int>> islands; // 记录每个位置所属的岛屿。0 表示不是岛。
    vector<vector<int>> st;      // 辅助遍历
    int stIndex;

public:
    int numIslands(vector<vector<char>> &grid)
    {
        grids = grid;
        islands = vector<vector<int>>(grid.size());
        for (int i = 0; i < islands.size(); ++i)
            islands[i] = vector<int>(grid[0].size());
        st = vector<vector<int>>(grid.size() * grid[0].size());
        stIndex = -1;

        count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1' && islands[i][j] == 0)
                {
                    ++count;
                    visit(i, j);
                }
            }
        }
        return count;
    }

    void visit(int i, int j) // BFS
    {
        st[++stIndex] = vector<int>{i, j};
        islands[i][j] = count;
        while (stIndex != -1)
        {
            vector<int> front = st[stIndex--];
            checkPos(front[0] - 1, front[1]); // 检查上方是否可以放入栈中
            checkPos(front[0], front[1] + 1); // 检查右方是否可以放入栈中
            checkPos(front[0] + 1, front[1]); // 检查下方是否可以放入栈中
            checkPos(front[0], front[1] - 1); // 检查左方是否可以放入栈中
        }
    }

    void checkPos(int i, int j)
    {
        if (i < 0 || i >= islands.size() || j < 0 || j >= islands[0].size() || grids[i][j] == '0' || islands[i][j] != 0)
            return;
        islands[i][j] = count;
        st[++stIndex] = vector<int>{i, j};
    }
};