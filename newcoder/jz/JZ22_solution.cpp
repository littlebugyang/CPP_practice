#include <vector>
using std::vector;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};
class Solution
{
public:
    struct Queue
    {
        struct TreeNode *treeNode;
        struct Queue *next;
        Queue() : treeNode(nullptr), next(nullptr) {}
    };
    vector<int> PrintFromTopToBottom2(TreeNode *root)
    {
        vector<int> result;
        Queue queue;
        queue.next = new Queue();
        queue.next->treeNode = root;
        Queue *current = queue.next;

        while (queue.next != nullptr)
        {
            // 1. 加入队首元素的左右孩子
            if (queue.next->treeNode->left != nullptr)
            {
                current->next = new Queue();
                current = current->next;
                current->treeNode = queue.next->treeNode->left;
            }
            if (queue.next->treeNode->right != nullptr)
            {
                current->next = new Queue();
                current = current->next;
                current->treeNode = queue.next->treeNode->right;
            }

            // 2. 访问队首元素的值
            result.push_back(queue.next->treeNode->val);

            // 3. 出队
            Queue *temp = queue.next;
            queue.next = queue.next->next;
            delete temp;
        }
        delete queue.next;
        return result;
    }

    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<TreeNode *> queue;
        vector<int> result;
        if (!root)
            return result;
        int headOfQueue = -1;
        queue.push_back(root);
        while (headOfQueue != queue.size() - 1)
        {
            TreeNode *nextNode = queue[headOfQueue + 1];
            // 1. 加入首元素的左右孩子
            if (nextNode->left)
                queue.push_back(nextNode->left);
            if (nextNode->right)
                queue.push_back(nextNode->right);

            // 2. 访问队首元素
            result.push_back(nextNode->val);

            // 3. 出队
            ++headOfQueue;
        }
        return result;
    }
};