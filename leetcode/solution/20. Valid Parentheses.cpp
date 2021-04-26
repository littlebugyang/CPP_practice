#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() < 2)
            return false;
        vector<char> parenStack;
        parenStack.push_back('#');
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s.at(i))
            {
            case ')':
                if (parenStack[parenStack.size() - 1] == '(')
                    parenStack.pop_back();
                else
                    return false;
                break;
            case ']':
                if (parenStack[parenStack.size() - 1] == '[')
                    parenStack.pop_back();
                else
                    return false;
                break;
            case '}':
                if (parenStack[parenStack.size() - 1] == '{')
                    parenStack.pop_back();
                else
                    return false;
                break;
            default:
                parenStack.push_back(s.at(i));
            }
        }
        return parenStack.size() == 1;
    }
};
