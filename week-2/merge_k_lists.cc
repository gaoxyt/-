class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return mergeRecur(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeRecur(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        ListNode* left_list = mergeRecur(lists, start, (start + end) / 2);
        ListNode* right_list = mergeRecur(lists, (start + end) / 2 + 1, end);
        return mergeList(left_list, right_list);
    }

    ListNode* mergeList(ListNode *left, ListNode* right) {
        ListNode head(-1);
        ListNode *node = &head;;
        while (left && right) {
            if (left->val < right->val) {
                node->next = left;
                left = left->next;
            } else {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }
        if (left) {
            node->next = left;
        } else {
            node->next = right;
        }
        return head.next;

    }
};
