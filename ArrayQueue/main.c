#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Element;

struct ArrayQueue {
    Element *array;
    int capacity;
    //队尾
    int rear;
    //队首
    int front;
};

typedef struct ArrayQueue *Queue;

bool initQueue(Queue queue) {
    queue->array = malloc(sizeof(Element) * 10);
    if (queue->array == NULL) {
        return false;
    }
    queue->capacity = 10;
    //默认情况下队首和队尾都指向0的位置
    queue->front = queue->rear = 0;
    return true;
}
//入队
bool enqueue(Queue queue,Element element) {
    //先判断队列是否已满，如果队尾下一个就是队首，那么说明已满
    if ((queue->rear + 1) % queue->capacity == queue->front) {
        return false;
    }
    //队尾先向前移动一位，注意取余计算才能实现循环
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;   //在新的位置插入元素
    return true;

}
bool isEmpty(Queue queue){
    return queue->rear == queue->front;
}
//出队
Element dequeue(Queue queue) {
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

void printQueue(Queue queue) {
    printf("<<< ");
    int i = queue->front;   //遍历队列需要从队首开始
    do {
        i = (i + 1) % queue->capacity;   //先向后循环移动
        printf("%d ", queue->array[i]);  //然后打印当前位置上的元素
    } while (i != queue->rear);   //当到达队尾时，结束
    printf("<<<\n");
}


int main() {
    struct ArrayQueue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        enqueue(&queue, i * 100);
    }
    printQueue(&queue);
    printf("\n");
    while (!isEmpty(&queue)){
        printf("%d ", dequeue(&queue));
    }
    return 0;
}
