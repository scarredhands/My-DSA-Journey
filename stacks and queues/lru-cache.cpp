//https://leetcode.com/problems/lru-cache/submissions/1674094934/
//tc= O(1)
//sc= O(capacity)

class LRUCache {
public:
    class node {
    public:
        int key, val;
        node* prev;
        node* next;
        node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    unordered_map<int, node*> mpp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(node* temp) {
        node* prevv = temp->prev;
        node* nextt = temp->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }

    void addNode(node* newnode) {
        node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        node* temp = mpp[key];
        deleteNode(temp);
        addNode(temp);
        mpp[key] = head->next;
        return temp->val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            node* existing = mpp[key];
            existing->val = value;
            deleteNode(existing);
            addNode(existing);
            mpp[key] = head->next;
        } else {
            if (mpp.size() >= cap) {
                int lruKey = tail->prev->key;
                deleteNode(tail->prev);
                mpp.erase(lruKey);
            }
            node* newnode = new node(key, value);
            addNode(newnode);
            mpp[key] = newnode;
        }
    }
};
