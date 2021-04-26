#include <string>
using std::string;

class Solution
{
public:
    int romanToInt(string s)
    {
        char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int values[7] = {1, 5, 10, 50, 100, 500, 1000};
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if ((s[i] == 'I' || s[i] == 'X' || s[i] == 'C') && i + 1 < s.size()) // 只有在 I、X、C 出现的时候才有可能需要考虑特殊情况
            {

                char nextChar = s[i + 1];
                int nextIdx = locateSymbol(symbols, nextChar);
                int currIdx = locateSymbol(symbols, s[i]);
                if (nextIdx - currIdx > 0 && nextIdx - currIdx <= 2) // 特殊情况
                {
                    result += (values[nextIdx] - values[currIdx]);
                    ++i;
                }
                else
                    result += values[currIdx];
            }
            else
                result += values[locateSymbol(symbols, s[i])];
        }
        return result;
    }

    int locateSymbol(char symbols[], char c)
    {
        for (int i = 0; i < 7; ++i)
            if (symbols[i] == c)
                return i;
        return -1;
    }
};