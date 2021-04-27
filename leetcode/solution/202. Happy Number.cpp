class Solution
{
public:
    bool isHappy(int n)
    {
        int slowResult = n;
        int fastResult = n;
        bool moveSlowResult = false;
        while (true)
        {
            if (n == 1)
                return true;
            n = calc(n);
            if (moveSlowResult)
                slowResult = calc(slowResult);
            fastResult = n;
            moveSlowResult = !moveSlowResult;
            if (slowResult == fastResult)
                return false;
        }
        return false; // 为了避免报错
    }

    unsigned long long calc(unsigned long long n)
    {
        unsigned long long sum = 0;
        while (n != 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    unsigned long long result = solution.isHappy(2);
    return 0;
}