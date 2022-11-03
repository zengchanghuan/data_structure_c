#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Element;

struct LinkedListNode {
    Element element;
    struct LinkedListNode *next;
};

typedef struct LinkedListNode *Node;

struct LinkedListQueue {
    Node front;
    Node rear;
};

typedef struct LinkedListQueue *Queue;

bool initQueue(Queue queue) {
    Node node = malloc(sizeof(struct LinkedListNode));
    if (node == NULL) {
        return false;
    }
    queue->front = queue->rear = node;
    return true;
}

void printQueue2(Queue queue) {
    printf("<<< ");
    Node node = queue->front->next;
    while (1) {    //注意不能直接判空，因为前面我们没考虑，也就没将新结点next设定为NULL
        printf("%d ", node->element);
        if (node == queue->rear) break;    //当已经打印最后一个元素后，再结束
        else node = node->next;
    }
    printf("<<<\n");
}

void printQueue(Queue queue) {
    printf("<<< ");
    if (queue->front == NULL) {
        return;
    }
    Node p = queue->front->next;
    while (p != NULL) {
        printf("%d ->", p->element);
        p = p->next;
    }
    printf("\n");


}

bool isEmpty(Queue queue) {
    return queue->rear == queue->front;
}
//入队
bool enqueue(Queue queue, Element element) {
    Node node = malloc(sizeof(struct LinkedListNode));
    if (node == NULL) {
        return false;
    }
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return true;
}

//出队
Element dequeue2(Queue queue) {
    Element e = queue->front->next->element;
    Node node = queue->front->next;
    queue->front->next = queue->front->next->next;  //直接让头结点指向下下个结点
    if (queue->rear == node) {
        queue->rear = queue->front;
    }//如果队尾就是待出队的结点，那么队尾回到队首位置上
    free(node);   //释放内存
    return e;
}

Element dequeue(Queue queue) {
    Element element = queue->front->next->element;
    Node node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if (queue->rear == node) {
        queue->rear = queue->front;
    }
    free(node);
    return element;
}

int main() {
    struct LinkedListQueue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        enqueue(&queue, i * 100);
    }
    printQueue(&queue);
    printf("\n");
    while (!isEmpty(&queue)) {
        printf("%d ", dequeue2(&queue));
    }
    return 0;
}
