/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int val):val(val), next(nullptr) { }
    };
    
    MyLinkedList() {
        dummyHead = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index > size - 1)
        {
            return -1;
        }

        ListNode* currNode = dummyHead->next;
        while(index)
        {
            index--;
            currNode = currNode->next;
        }
        return currNode->val;
    }
    
    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = dummyHead->next;
        dummyHead->next = newHead;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newTail = new ListNode(val);
        ListNode* curr = dummyHead;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newTail;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
        {
            return ;
        }
        else if(index == size)
        {
            addAtTail(val);
            return ;
        }
        else if(index < 0)
        {
            addAtHead(val);
            return ;
        }

        ListNode* newNode = new ListNode(val);
        ListNode* currNode = dummyHead;
        while(index)
        {
            index--;
            currNode = currNode->next;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
        {
            return ;
        }

        // we should keep in track of the prev node of the node to be deleted
        ListNode* curr = dummyHead;
        while(index)
        {
            index--;
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete(temp);
        temp = nullptr;
        size--;
    }
    
private:
    int size;
    ListNode* dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

