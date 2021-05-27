#include <vector>
#include <algorithm>
#include <iostream>
using std::next_permutation;
using std::vector;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
    }
};

int main()
{
    vector<int> test{1, 2, 3, 4, 5};
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            std::cout << test[j] << ", ";
        }
        std::cout << std::endl;
        next_permutation(test.begin(), test.end());
    }
    return 0;
}