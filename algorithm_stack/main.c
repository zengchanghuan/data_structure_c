#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

bool isEmpty(Node head) {
    return head->next == NULL;
}

Element popStack(Node head){
    Node top = head->next;
    head->next = head->next->next;
    Element element = top->element;
    free(element);
    return element;
}
bool pushStack(Node head, Element element) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) {
        return false;
    }
    node->next = head->next;
    node->element = element;
    head->next = node;
    return true;
}

bool isValid(char *s) {
    unsigned long len = strlen(s);
    if (len % 2 == 1) {
        return false;
    }
    struct LNode head;
    initStack(&head);
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            pushStack(&head, c);
        } else {
            if (isEmpty(&head)) {
                return false;
            }
            if (c == ')') {
                if (popStack(&head) != '(') {
                    return false;
                }
            } else if (c == ']') {
                if (popStack(&head) != '[') {
                    return false;
                }
            } else {
                if (popStack(&head) != '{') {
                    return false;
                }
            }
        }
    }
    return isEmpty(&head);
}
int main() {
    printf("Hello, World!\n");
    return 0;
}
