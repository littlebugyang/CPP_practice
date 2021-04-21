#include <iostream>
#include <map>
#include <vector>
using std::cout;
using std::map;
using std::vector;

class Solution
{
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> mappings;
        for (int i = 0; i < numbers.size(); ++i)
            mappings[numbers[i]] = i + 1;

        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i)
        {
            int temp = mappings[target - numbers[i]];
            if (temp != 0 && temp != i + 1)
            {
                result.push_back(i + 1);
                result.push_back(temp);
                break;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(4);
    Solution solution;
    vector<int> result = solution.twoSum(numbers, 6);
    return 0;
}