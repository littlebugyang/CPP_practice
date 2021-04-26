#include <string>
using std::string;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        unsigned long long result = 0;
        for (int i = 0; i < columnTitle.size(); ++i)
            result = result * 26 + columnTitle[i] - 'A' + 1;
        return result;
    }
};