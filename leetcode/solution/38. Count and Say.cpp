#include <string>
using std::string;
using std::to_string;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return to_string(1);

        string current = "1";
        for (int i = 0; i < n - 1; ++i)
        {
            char lastChar = current[0];
            int count = 1;
            string temp = "";
            for (int j = 1; j < current.size(); ++j)
            {
                if (current[j] == lastChar)
                    ++count;
                else // 清算
                {
                    temp += (to_string(count) + string(1, lastChar));
                    lastChar = current[j];
                    count = 1;
                }
            }
            current = (temp += (to_string(count) + string(1, lastChar)));
        }
        return current;
    }
};