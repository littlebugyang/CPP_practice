class Solution
{
public:
    int Fibonacci(int n)
    {
        if (n == 0 || n == 1)
            return n;

        int j = 0;
        int k = 1;
        int result = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            result = j + k;
            j = k;
            k = result;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    solution.Fibonacci(4);
    return 0;
}