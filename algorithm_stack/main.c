#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char Element;

struct LNode {
    Element element;
    struct LNode *next;
};

typedef struct LNode *Node;

void initStack(Node head) {
    head->next = NULL;
}

bool pushStack(Node head, Element element) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) {
        return 0;
    }
    node->next = head->next;
    node->element = element;
    head->next = node;
    return true;
}

bool isEmpty(Node head) {
    return head->next == NULL;
}

Element popStack(Node head) {
    Node top = head->next;
    head->next = head->next->next;
    Element e = top->element;
    free(top);
    return e;
}

bool isValid(char *s) {
    unsigned long len = strlen(s);
    if (len % 2 == 1) return false;  //如果长度不是偶数，那么一定不能成功匹配
    struct LNode head;
    initStack(&head);
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            pushStack(&head, c);
        } else {
            if (isEmpty(&head)) return false;
            if (c == ')') {
                if (popStack(&head) != '(') return false;
            } else if (c == ']') {
                if (popStack(&head) != '[') return false;
            } else {
                if (popStack(&head) != '{') return false;
            }
        }
    }
    return isEmpty(&head);
}





