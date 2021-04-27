class Solution
{
public:
    int trailingZeroes(int n)
    {
        unsigned int powerFive = 5;
        int zerosCount = 0;
        while (powerFive <= n)
        {
            zerosCount += (n / powerFive);
            powerFive *= 5;
        }
        return zerosCount;
    }
};