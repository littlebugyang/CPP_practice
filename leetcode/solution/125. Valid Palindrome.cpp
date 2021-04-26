#include <string>
using std::string;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = -1, j = s.size() - 1;
        for (int k = 0; k < s.size(); ++k)
        {
            if (isAlphaNumeric(s.at(k)))
                s.at(++i) = s.at(k);
        }

        if (i <= 0) // i == -1 时，一个字母数字都没有；i == 0 时，只有一个有效字符
            return true;
        j = i;
        i = 0;
        while (i < j)
        {
            char left = s.at(i++);
            char right = s.at(j--);
            left = toLower(left);
            right = toLower(right);

            if (left != right)
                return false;
        }
        return true;
    }

    bool isAlphaNumeric(char c)
    {
        return ('A' <= c && c <= 'Z') ||
               ('a' <= c && c <= 'z') ||
               ('0' <= c && c <= '9');
    }

    char toLower(char c)
    {
        if ('A' <= c && c <= 'Z')
            return c + 'a' - 'A';
        return c;
    }
};