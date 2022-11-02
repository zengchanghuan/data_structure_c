#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Element;

struct LinkedListNode {
    Element element;
    struct LinkedListNode *next;
};
typedef struct LinkedListNode *Node;

typedef struct LinkedListNode *Stack;

void initStack(Stack stack) {
    stack->next = NULL;
}

bool printStack(Stack stack) {
    printf("| ");
    stack = stack->next;
    while (stack) {
        printf("%d ", stack->element);
        stack = stack->next;
    }
    printf("\n");

}

bool push(Stack stack, Element element) {
    Node node = malloc(sizeof(struct LinkedListNode));
    if (node == NULL) {
        return false;
    }
    node->next = stack->next;
    node->element = element;
    stack->next = node;
    return true;
}


Element pop(Stack stack){
    Node temp = stack->next;
    Element element = temp->element;
    stack->next = stack->next->next;
    free(temp);
    return element;
}

//判断栈是否为空只需要看头结点下一个是否为NULL即可
bool isEmpty(Stack stack){
    return stack->next == NULL;
}
int main() {
    struct LinkedListNode stack;
    initStack(&stack);
    for (int i = 0; i < 3; ++i) {
        push(&stack, i * 100);
    }
    printStack(&stack);
    printf("\n");
    while (!isEmpty(&stack)){
        printf("%d ", pop(&stack));
    }
    return 0;
}
