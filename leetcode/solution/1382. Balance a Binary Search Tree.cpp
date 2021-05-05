#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using std::abs;
using std::max;
using std::unordered_map;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    unordered_map<TreeNode *, TreeNode *> parentOf;
    unordered_map<TreeNode *, int> heightOf; // 0 为默认值，即空节点高度为 0
    TreeNode *hot;                           // 搜索时目标节点的父节点
    TreeNode *root;

public:
    Solution()
    {
        root = nullptr;
        hot = root;
        parentOf[root] = nullptr;
        // heightOf[root] = 1; 这样会使得所有空节点高度都为 1
    }
    ~Solution()
    {
        // delete root;
        // 虽然这里不足以释放所有内存，但是又不是在我机子上跑，又有什么关系呢~
    }

    TreeNode *balanceBST(TreeNode *r)
    {
        vector<int> inSeq = inorderSequence(r);
        for (int i = 0; i < inSeq.size(); ++i)
            AVLInsert(inSeq[i]);
        return root;
    }

    void updateHeight(TreeNode *node)
    {
        heightOf[node] = max(heightOf[node->left], heightOf[node->right]) + 1;
    }

    void updateHeightAbove(TreeNode *node)
    {
        while (node)
        {
            heightOf[node] = max(heightOf[node->left], heightOf[node->right]) + 1;
            node = parentOf[node];
        }
    }

    bool balanced(TreeNode *root)
    {
        return abs(heightOf[root->left] - heightOf[root->right]) <= 1;
    }

    TreeNode *reconstruct34(TreeNode *newLeft, TreeNode *newRoot, TreeNode *newRight, TreeNode *child1, TreeNode *child2, TreeNode *child3, TreeNode *child4)
    {
        // newLeft、newRoot、newRight 必不为空
        newRoot->left = newLeft, parentOf[newLeft] = newRoot;
        newRoot->right = newRight, parentOf[newRight] = newRoot;

        newLeft->left = child1;
        if (child1)
            parentOf[child1] = newLeft;
        newLeft->right = child2;
        if (child2)
            parentOf[child2] = newLeft;
        newRight->left = child3;
        if (child3)
            parentOf[child3] = newRight;
        newRight->right = child4;
        if (child4)
            parentOf[child4] = newRight;

        // children 的高度不可能发生变化，但是 newLeft、newRoot、newRight 的可能
        updateHeight(newLeft);
        updateHeight(newRight);
        updateHeight(newRoot);
        return newRoot;
    }

    void reconnectChild(TreeNode *oldChild, TreeNode *newChild)
    {
        TreeNode *parent = parentOf[oldChild];
        if (parent)
        {
            parent->left = parent->left == oldChild ? newChild : parent->left;
            parent->right = parent->right == oldChild ? newChild : parent->right;
        }
        else
            root = newChild;
    }

    TreeNode *rotateAt(TreeNode *v)
    {
        TreeNode *p = parentOf[v];
        TreeNode *g = parentOf[p];
        if (p->right == v) // zag
        {
            if (g->right == p) // zagzag
            {
                // 向下联接
                reconnectChild(g, p);
                // 向上联接
                parentOf[p] = parentOf[g];
                return reconstruct34(g, p, v, g->left, p->left, v->left, v->right);
            }
            else // zagzig
            {
                // 向下联接
                reconnectChild(g, v);
                // 向上联接
                parentOf[v] = parentOf[g];
                return reconstruct34(p, v, g, p->left, v->left, v->right, g->right);
            }
        }
        else // zig
        {
            if (g->right == p) // zigzag
            {
                // 向下联接
                reconnectChild(g, v);
                // 向上联接
                parentOf[v] = parentOf[g];
                return reconstruct34(g, v, p, g->left, v->left, v->right, p->right);
            }
            else // zigzig
            {
                // 向下联接
                reconnectChild(g, p);
                // 向上联接
                parentOf[p] = parentOf[g];
                return reconstruct34(v, p, g, v->left, v->right, p->right, g->right);
            }
        }
    }

    TreeNode *AVLInsert(int val)
    {
        TreeNode *x = AVLSearch(val);
        if (x)
            return x;

        if (!hot) // 插入第一个节点
            return root = new TreeNode(val);

        if (hot->val > val)
        {
            x = hot->left = new TreeNode(val);
            parentOf[hot->left] = hot;
            heightOf[hot->left] = 1;
        }
        else
        {
            x = hot->right = new TreeNode(val);
            parentOf[hot->right] = hot;
            heightOf[hot->right] = 1;
        }

        for (TreeNode *g = hot; g; g = parentOf[g])
        {
            if (!balanced(g))
            {
                // 找到恢复平衡所需的节点 g、p、v 中的 v
                TreeNode *v = heightOf[g->left] > heightOf[g->right] ? g->left : g->right;
                v = heightOf[v->left] > heightOf[v->right] ? v->left : v->right;
                rotateAt(v);
                break;
            }
            else
                updateHeight(g);
        }
        return x;
    }

    void AVLDelete(int val)
    {
    }

    TreeNode *AVLSearch(int val)
    {
        // 其实这里不用 curr，只用 root 就可以了。
        hot = parentOf[root];
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->val == val)
                return curr;
            hot = curr;
            if (curr->val > val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return nullptr;
    }

    vector<int> inorderSequence(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        vector<TreeNode *> stack;
        stack.push_back(root);
        gotoLeftmost(stack);

        while (!stack.empty())
        {
            TreeNode *leftmost = stack[stack.size() - 1];
            stack.pop_back();
            result.push_back(leftmost->val);
            if (leftmost->right)
            {
                stack.push_back(leftmost->right);
                gotoLeftmost(stack);
            }
        }
        return result;
    }

    void gotoLeftmost(vector<TreeNode *> &stack)
    {
        TreeNode *curr = stack[stack.size() - 1];
        while (curr = curr->left)
            stack.push_back(curr);
    }
};

TreeNode *constructTree(const vector<int> &nums)
{
    TreeNode *root = new TreeNode(nums[0]);
    TreeNode *curr = root;
    int i = 0;
    while (i != nums.size() - 1)
    {
        curr->left = (nums[++i] == -1) ? nullptr : new TreeNode(nums[i]);
        curr->right = (nums[++i] == -1) ? nullptr : new TreeNode(nums[i]);
        curr = curr->left ? curr->left : curr->right;
    }
    return root;
}

int main()
{
    vector<int> nums = {1, -1, 2, -1, 3, -1, 4, -1, -1};
    TreeNode *root = constructTree(nums);

    Solution solution;
    TreeNode *result = solution.balanceBST(root);
    return 0;
}
