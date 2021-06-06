#include <iostream>
#include <vector>
using std::cout;
using std::vector;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // todo: 判空
        if (matrix.size() == 0)
        {
            vector<int> temp;
            return temp;
        }

        const int SPIRAL_RIGHT = 0;
        const int SPIRAL_DOWN = 1;
        const int SPIRAL_LEFT = 2;
        const int SPIRAL_UP = 3;

        int direction = SPIRAL_RIGHT;
        vector<int> result;
        int pos_x, pos_y; // 左上角为 (0, 0)
        pos_x = -1;
        pos_y = 0;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int horizontal_steps = columns;
        int vertical_steps = rows;

        for (int i = 0; i < rows * columns;)
        {
            switch (direction)
            {
            case SPIRAL_UP:
                --horizontal_steps;
                i += vertical_steps;
                for (int j = 0; j < vertical_steps; ++j)
                    result.push_back(matrix[--pos_y][pos_x]);
                direction = (direction + 1) % 4;
                break;
            case SPIRAL_DOWN:
                --horizontal_steps;
                i += vertical_steps;
                for (int j = 0; j < vertical_steps; ++j)
                    result.push_back(matrix[++pos_y][pos_x]);
                direction = (direction + 1) % 4;
                break;
            case SPIRAL_LEFT:
                --vertical_steps;
                i += horizontal_steps;
                for (int j = 0; j < horizontal_steps; ++j)
                    result.push_back(matrix[pos_y][--pos_x]);
                direction = (direction + 1) % 4;
                break;
            case SPIRAL_RIGHT:
                --vertical_steps;
                i += horizontal_steps;
                for (int j = 0; j < horizontal_steps; ++j)
                    result.push_back(matrix[pos_y][++pos_x]);
                direction = (direction + 1) % 4;
                break;
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> matrix;
    vector<int> row1 = {1, 2, 3};
    vector<int> row2 = {4, 5, 6};
    vector<int> row3 = {7, 8, 9};
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    Solution solution;
    solution.spiralOrder(matrix);
    return 0;
}