#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//删除链表中重复元素
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *node = head;
    while (node->next != NULL) {
        if (node->next->val == node->val) {
            node->next = node->next->next;
        } else {
            node = node->next;
        }
    }
    return head;
}

//链表反转
struct ListNode* reverseList(struct ListNode* head){

}
int main() {
    printf("Hello, World!\n");
    return 0;
}
