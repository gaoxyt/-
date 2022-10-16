class MyCircularDeque {
public:
    MyCircularDeque(int k) : node_cnt_(0), max_cnt_(k),
        head_(new DoubleLinkList()), tail_(new DoubleLinkList()) {
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~MyCircularDeque() {
        auto *node = head_;
        while (node != nullptr) {
            auto *next = node->next;
            delete node;
            node = next;
        }
    }
    
    bool insertFront(int value) {
        if (node_cnt_ >= max_cnt_) {
            return false;
        }
        node_cnt_++;
        DoubleLinkList *new_node = new DoubleLinkList(value);
        new_node->next = head_->next;
        head_->next = new_node;
        new_node->next->prev = new_node;
        new_node->prev = head_;
        return true;
    }
    
    bool insertLast(int value) {
        if (node_cnt_ >= max_cnt_) {
            return false;
        }
        node_cnt_++;
        DoubleLinkList *new_node = new DoubleLinkList(value);
        new_node->prev = tail_->prev;
        new_node->next = tail_;
        new_node->prev->next = new_node;
        tail_->prev = new_node;
        return true;
    }
    
    bool deleteFront() {
        if (node_cnt_ < 1) {
            return false;
        }
        node_cnt_--;
        auto *delete_node = head_->next;
        head_->next = delete_node->next;
        delete_node->next->prev = head_;
        delete delete_node;
        return true;
    }
    
    bool deleteLast() {
        if (node_cnt_ < 1) {
            return false;
        }
        node_cnt_--;
        auto *delete_node = tail_->prev;
        tail_->prev = delete_node->prev;
        delete_node->prev->next = tail_;
        delete delete_node;
        return true;
    }
    
    int getFront() {
        if (node_cnt_ < 1) {
            return -1;
        }
        return head_->next->val;
    }
    
    int getRear() {
        if (node_cnt_ < 1) {
            return -1;
        }
        return tail_->prev->val;
    }
    
    bool isEmpty() {
        return node_cnt_ < 1;
    }
    
    bool isFull() {
        return node_cnt_ >= max_cnt_;
    }

private:
    struct DoubleLinkList {
        int val;
        DoubleLinkList *prev;
        DoubleLinkList *next;
        DoubleLinkList() : val(0), prev(nullptr), next(nullptr) {}
        DoubleLinkList(int value) : val(value), prev(nullptr), next(nullptr) {}
    };
    DoubleLinkList *head_;
    DoubleLinkList *tail_;
    int node_cnt_;
    int max_cnt_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
