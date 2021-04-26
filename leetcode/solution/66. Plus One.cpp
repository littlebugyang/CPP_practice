#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int sum = digits[digits.size() - 1] + 1;
        digits[digits.size() - 1] = sum % 10;
        bool carry = bool(sum / 10);

        for (int i = digits.size() - 2; i >= 0; --i)
        {
            if (carry)
            {
                sum = digits[i] + 1;
                digits[i] = sum % 10;
                carry = bool(sum / 10);
            }
            else
                break;
        }

        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};