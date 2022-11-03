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
struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *newNode = NULL;
    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        temp->next = newNode;
        newNode = temp;
    }
    return newNode;
}

struct ListNode *rotateRight(struct ListNode *head, int k) {
    if(head == NULL || k == 0){
        return head;
    }
    struct ListNode *node = head;
    int len = 1;
    while (node->next){
        node = node->next;
        len++;
    }
    if(k == len){
        return head;
    }
    node->next = head;
    int index = len - k % len;
    node = head;
    while (--index){
        node = node->next;
    }

    head = node->next;
    node->next = NULL;
    return head;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
