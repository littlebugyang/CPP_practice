#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result(matrix.size() * matrix[0].size());
        int direction = 0;
        int x = -1, y = 0; // 左上角是 (0, 0)，右下角是 (matrix[0].size(), matrix.size())
        int rows = matrix.size(), columns = matrix[0].size();

        for (int i = 0; i < result.size();)
        {
            switch (direction)
            {
            case 0: // 向右
                --rows;
                for (int j = 0; j < columns; ++j)
                    result[i++] = matrix[y][++x];
                break;
            case 1: // 向下
                --columns;
                for (int j = 0; j < rows; ++j)
                    result[i++] = matrix[++y][x];
                break;
            case 2: // 向左
                --rows;
                for (int j = 0; j < columns; ++j)
                    result[i++] = matrix[y][--x];
                break;
            case 3: // 向上
                --columns;
                for (int j = 0; j < rows; ++j)
                    result[i++] = matrix[--y][x];
                break;
            }
            direction = (direction + 1) % 4;
        }
        return result;
    }
};