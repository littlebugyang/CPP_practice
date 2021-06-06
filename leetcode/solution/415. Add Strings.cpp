#include <string>
using std::string;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result = "";
        int i1 = num1.size() - 1, i2 = num2.size() - 1;
        bool carry = false;
        while (i1 >= 0 && i2 >= 0)
        {
            int sum = int(num1[i1--] - '0') + int(num2[i2--] - '0') + int(carry);
            carry = sum > 9;
            result = char('0' + (sum % 10)) + result;
        }

        if (i1 >= 0) // num1 还有长度
            solveRest(result, num1, i1, carry);
        if (i2 >= 0)
            solveRest(result, num2, i2, carry);

        return carry ? '1' + result : result;
    }

    void solveRest(string &result, const string &num, int &index, bool &carry)
    {
        while (0 <= index)
        {
            int sum = int(num[index--] - '0') + int(carry);
            carry = sum > 9;
            result = char('0' + (sum % 10)) + result;
        }
    }
};