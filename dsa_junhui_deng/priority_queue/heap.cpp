#include <algorithm>
#include <vector>
using std::swap;
using std::vector;

class Heap
{
private:
    vector<int> elems;

public:
    Heap()
    {
    }

    Heap(vector<int> nums) { elems = nums; }

    void percolateUp(int idx)
    {
        while ((idx - 1) / 2 >= 0 && compare(elems[(idx - 1) / 2], elems[idx]))
        {
            swap(elems[(idx - 1) / 2], elems[idx]);
            idx = (idx - 1) / 2;
        }
    }

    void percolateDown()
    {
        int index = 0;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int swapIndex = leftIndex;

        while (leftIndex < elems.size())
        {
            if (rightIndex < elems.size() && compare(elems[leftIndex], elems[rightIndex]))
                swapIndex = rightIndex;
            if (compare(elems[index], elems[swapIndex]))
            {
                swap(elems[index], elems[swapIndex]);
                index = swapIndex;

                leftIndex = 2 * index + 1;
                rightIndex = 2 * index + 2;
                swapIndex = leftIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapify()
    {
    }

    void insert(int x)
    {
        elems.push_back(x);
        percolateUp(elems[elems.size() - 1]);
    }

    void deleteRoot()
    {
        elems[0] = elems[elems.size() - 1];
        elems.pop_back();
        percolateDown();
    }

    bool compare(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    vector<int> nums{5, 4, 3, 2, 0, 1};

    Heap heap(nums);

    // heap.insert(5);
    heap.deleteRoot();
    return 0;
}