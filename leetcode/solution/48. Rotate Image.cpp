#include <vector>
#include <algorithm>
using std::swap;
using std::vector;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // matrix 共有 matrix.size() / 2 个环，分别把这几个环都旋转就可以了。
        for (int i = 0; i < matrix.size() / 2; ++i)
            rotateLoop(matrix, i);
    }

    void rotateLoop(vector<vector<int>> &matrix, int i)
    {
        // 旋转第 i 个环，最外边的环为第 0 环
        int n = matrix.size() - i * 2; // 该环的边长
        for (int j = 0; j < n - 1; ++j)
        {
            int last = matrix[i][i];

            int x = i, y = i;
            for (int i = 0; i < n - 1; ++i, ++y) // 向下
                matrix[y][x] = matrix[y + 1][x];
            for (int i = 0; i < n - 1; ++i, ++x) // 向右
                matrix[y][x] = matrix[y][x + 1];
            for (int i = 0; i < n - 1; ++i, --y) // 向上
                matrix[y][x] = matrix[y - 1][x];
            for (int i = 0; i < n - 1; ++i, --x) // 向左
                matrix[y][x] = matrix[y][x - 1];
            matrix[y][x + 1] = last;
        }
    }
};