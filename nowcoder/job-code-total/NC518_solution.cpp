#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param chessboard string字符串vector 
     * @return string字符串
     */
    string playchess(vector<string> &chessboard)
    {
        // 大写字母是牛妹的，小写字母是牛牛的。
        bool win = false;
        for (int i = 0; i < chessboard.size(); ++i)
        {
            for (int j = 0; j < chessboard[i].size(); ++j)
            {
                if (chessboard[i].at(j) == '.')
                    continue;

                bool end = false;
                switch (chessboard[i].at(j))
                {
                case 'J':
                case 'B':
                    // 下面 || 上面 || 左面 || 右面 有路且为 'j'
                    if ((i + 1 != chessboard.size() && chessboard[i + 1].at(j) == 'j') ||
                        (i - 1 != -1 && chessboard[i - 1].at(j) == 'j') ||
                        j - 1 != -1 && chessboard[i].at(j - 1) == 'j' ||
                        j + 1 != chessboard[i].size() && chessboard[i].at(j + 1) == 'j')
                        end = true;
                    break;
                case 'P':
                    if (JiangWithinPaosRange(chessboard, i, j))
                        end = true;
                    break;
                case 'C':
                    if (JiangOnChesWay(chessboard, i, j))
                        end = true;
                    break;
                }
                if (end)
                {
                    win = true;
                    i = chessboard.size() - 1;
                    break;
                }
            }
        }
        return win ? "Happy" : "Sad";
    }

    bool JiangOnChesWay(vector<string> &chessboard, int posRow, int posColumn)
    {
        int i = -1;
        // 向上
        i = posRow;
        while (--i != -1 && chessboard[i].at(posColumn) == '.')
            ;
        ++i;
        while (--i != -1)
        {
            if (chessboard[i].at(posColumn) == 'j')
                return true;
            else
                break;
        };

        // 向下
        i = posRow;
        while (++i != chessboard.size() && chessboard[i].at(posColumn) == '.')
            ;
        --i;
        while (++i != chessboard.size())
        {
            if (chessboard[i].at(posColumn) == 'j')
                return true;
            else
                break;
        };

        // 向左
        i = posColumn;
        while (--i != -1 && chessboard[posRow].at(i) == '.')
            ;
        ++i;
        while (--i != -1)
        {
            if (chessboard[posRow].at(i) == 'j')
                return true;
            else
                break;
        }

        // 向右
        i = posColumn;
        while (++i != chessboard[posRow].size() && chessboard[posRow].at(i) == '.')
            ;
        --i;
        while (++i != chessboard[posRow].size())
        {
            if (chessboard[posRow].at(i) == 'j')
                return true;
            else
                break;
        }
        return false;
    }

    bool JiangWithinPaosRange(vector<string> &chessboard, int posRow, int posColumn)
    {
        int i = -1;
        bool jump = false;

        // 向上
        i = posRow;
        while (--i != -1 && chessboard[i].at(posColumn) == '.')
            ;
        i += 1;
        while (--i != -1)
        {
            if (chessboard[i].at(posColumn) == 'j')
                if (jump)
                    return true;
                else
                    break;
            else if (!jump)
                jump = true;
            else if (chessboard[posRow].at(i) != '.')
                break;
        };

        // 向下
        i = posRow;
        jump = false;
        while (++i != chessboard.size() && chessboard[i].at(posColumn) == '.')
            ;
        i -= 1;
        while (++i != chessboard.size())
        {
            if (chessboard[i].at(posColumn) == 'j')
                if (jump)
                    return true;
                else
                    break;
            else if (!jump)
                jump = true;
            else if (chessboard[posRow].at(i) != '.')
                break;
        };

        // 向左
        i = posColumn;
        jump = false;
        while (--i != -1 && chessboard[posRow].at(i) == '.')
            ;
        i += 1;
        while (--i != -1)
        {
            if (chessboard[posRow].at(i) == 'j')
                if (jump)
                    return true;
                else
                    break;
            else if (!jump)
                jump = true;
            else if (chessboard[posRow].at(i) != '.')
                break;
        }

        // 向右
        i = posColumn;
        jump = false;
        while (++i != chessboard[posRow].size() && chessboard[posRow].at(i) == '.')
            ;
        i -= 1;
        while (++i != chessboard[posRow].size())
        {
            if (chessboard[posRow].at(i) == 'j')
                if (jump)
                    return true;
                else
                    break;
            else if (!jump)
                jump = true;
            else if (chessboard[posRow].at(i) != '.')
                break;
        }
        return false;
    }
};

int main()
{
    vector<string> arr = {"......", "..B...", "P.C.j.", "......", "..b...", "...J.."};
    Solution solution;
    string result = solution.playchess(arr);
    return 0;
}