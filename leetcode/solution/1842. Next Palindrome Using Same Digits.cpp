#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string nextPalindrome(string num) {
        int mid = int(num.size()) / 2 - 1;
        int i;
        for(i = mid - 1; 0 <= i; --i)
        {
            if(num[i] < num[i+1])
            {
                for(int j = mid; i < j; --j)
                {
                    if(num[j] > num[i])
                    {
                        swap(num[j], num[i]);
                        int left = i + 1, right = mid;
                        while(left < right)
                        {
                            swap(num[left], num[right]);
                            ++left, --right;
                        }
                        break;
                    }
                }
                break;
            }
        }

        if(i < 0)
            return "";
        else
        {
            mid = int(num.size() - 1) / 2;
            for(i = mid + 1; i < num.size(); ++i)
                if(num.size() % 2 != 0)
                    num[i] = num[2 * mid - i];
                else
                    num[i] = num[2 * mid - i + 1];
        }
        return num;
    }
};