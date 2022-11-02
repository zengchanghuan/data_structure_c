#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Element;

struct ArrayStack {
    Element *array;
    int capacity;
    int top;
};

typedef struct ArrayStack *Stack;

bool initStack(Stack stack) {
    stack->array = malloc(sizeof(Element) * 10);
    if (stack->array == NULL) {
        return false;
    }

    stack->capacity = 10;
    stack->top = -1;
    return true;
}

bool isEmpty(Stack stack) {
    return stack->top == -1;
}

void printStack(Stack stack) {
    printf("| ");

    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");

}

bool push(Stack stack, Element element) {
    if (stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        Element *newArray = realloc(stack->array, newCapacity * sizeof(Element));
        if (newCapacity == NULL) {
            return false;
        }
        stack->array = newArray;
        stack->capacity = newCapacity;

    }
    stack->array[stack->top + 1] = element;
    stack->top++;
    return true;

}

Element pop(Stack stack) {
    return stack->array[stack->top--];
}

int main() {
    struct ArrayStack stack;
    initStack(&stack);
    for (int i = 0; i < 3; ++i) {
        push(&stack, i * 100);
    }
    printStack(&stack);
    printf("\n");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));   //将栈中所有元素依次出栈
    }
    return 0;
}
