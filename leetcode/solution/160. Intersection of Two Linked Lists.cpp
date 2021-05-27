struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
    {
        ListNode *currA = headA, *currB = headB;
        int lengthA = 0, lengthB = 0;
        while (currA != nullptr)
        {
            ++lengthA;
            currA = currA->next;
        }
        while (currB != nullptr)
        {
            ++lengthB;
            currB = currB->next;
        }

        currA = headA;
        currB = headB;

        if (lengthA <= lengthB)
        {
            int n = lengthB - lengthA;
            while (n--)
                currB = currB->next;
        }
        else
        {
            int n = lengthA - lengthB;
            while (n--)
                currA = currA->next;
        }

        while (currA != currB)
        {
            currA = currA->next;
            currB = currB->next;
        }
        return currA;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pA = headA, *pB = headB;
        bool resetA = false, resetB = false;
        while (pA && pB)
        {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
            if (!pA && !resetA)
            {
                pA = headB;
                resetA = true;
            }
            if (!pB && !resetB)
            {
                pB = headA;
                resetB = true;
            }
        }
        return nullptr;
    }
};