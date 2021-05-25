#include <map>
using std::map;

struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity;
    int size;

    Node head;
    Node tail;
    map<int, Node *> keyNodes;

public:
    LRUCache(int capacity)
    {
        head.next = &tail;
        tail.prev = &head;
        this->capacity = capacity;
        this->size = 0;
    }

    ~LRUCache()
    {
        Node *curr = head.next;
        Node *temp = nullptr;
        while (curr != &tail)
        {
            temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    int get(int key)
    {
        if (keyNodes[key])
        {
            // 把该节点从当前位置脱离
            keyNodes[key]->prev->next = keyNodes[key]->next;
            keyNodes[key]->next->prev = keyNodes[key]->prev;

            // 把该节点放到最前面
            keyNodes[key]->next = head.next;
            head.next->prev = keyNodes[key];
            keyNodes[key]->prev = &head;
            head.next = keyNodes[key];

            return keyNodes[key]->value;
        }
        return -1;
    }

    void insertAfter(Node *pos, Node *target)
    {
        // 不要将该方法应用于 tail 节点上
        if (!pos->next)
            return;

        target->next = pos->next;
        pos->next->prev = target;
        target->prev = pos;
        pos->next = target;
    }

    void removeBefore(Node *pos)
    {
        // 不要将该方法应用于 head 节点上
        if (!pos->prev)
            return;

        Node *deletedNode = pos->prev;
        deletedNode->prev->next = pos;
        pos->prev = deletedNode->prev;
        delete deletedNode;
    }

    void moveToHead(Node *pos)
    {
        // 不要将该方法应用于 head 或 tail 节点上
        if (!pos->prev || !pos->next)
            return;

        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;

        head.next->prev = pos;
        pos->next = head.next;
        head.next = pos;
        pos->prev = &head;
    }

    void put(int key, int value)
    {
        if (keyNodes[key]) // 该关键字已在，则仅需要更新
        {
            keyNodes[key]->value = value;
            // 并将该节点提到队伍前
            moveToHead(keyNodes[key]);
        }
        else // 关键字不存在
        {
            if (size == capacity) // 如果容量已达上限
            {
                // 则需要移除最后一个节点
                keyNodes[tail.prev->key] = nullptr;
                removeBefore(&tail);
            }
            else
            {
                ++size;
            }
            // 终究是要插入一个新节点的
            Node *newNode = new Node(key, value);
            insertAfter(&head, newNode);
            keyNodes[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */