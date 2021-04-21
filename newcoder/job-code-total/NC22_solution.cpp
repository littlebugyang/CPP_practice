class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int *temp = new int[m + n];
        int indexM, indexN, indexTemp;
        indexM = indexN = indexTemp = 0;
        while (indexM != m && indexN != n)
        {
            if (A[indexM] <= B[indexN])
            {
                temp[indexTemp++] = A[indexM++];
            }
            else
            {
                temp[indexTemp++] = B[indexN++];
            }
        }

        if (indexM == m) // A 数组满了
        {
            while (indexN != n)
                temp[indexTemp++] = B[indexN++];
        }
        else
        {
            while (indexM != m)
                temp[indexTemp++] = A[indexM++];
        }

        for (int i = 0; i < m + n; ++i)
            A[i] = temp[i];
        delete temp;
    }
};

int main()
{
    int A[5] = {1, 2, 4, 5, 9};
    int B[4] = {1, 9, 10, 11};
    Solution solution;
    solution.merge(A, 4, B, 4);
    return 0;
}