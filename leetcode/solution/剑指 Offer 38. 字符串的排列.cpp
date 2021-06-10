#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> result;

        int lesser = s.size() - 2;
        int more = s.size() - 1;

        sort(s.begin(), s.end());
        result.push_back(s);

        while (true)
        {
            while (lesser >= 0 && s[lesser] >= s[lesser + 1])
                --lesser;
            if (lesser == -1)
                break;
            while (more >= 0 && s[more] <= s[lesser])
                --more;
            swap(s[more], s[lesser]);

            ++lesser;
            more = s.size() - 1;
            while (lesser < more)
            {
                swap(s[more], s[lesser]);
                ++lesser, --more;
            }

            lesser = s.size() - 2;
            more = s.size() - 1;

            result.push_back(s);
        }

        return result;
    }
};