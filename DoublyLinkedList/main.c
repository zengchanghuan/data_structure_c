#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;
struct ListNode {
    Element element;
    //后续
    struct ListNode *next;
    //前驱
    struct ListNode *prev;
};

typedef struct ListNode *Node;

void initNode(Node node) {
    node->next = node->prev = NULL;
}

bool insertList(Node head, Element element, int index) {
    if (index < 1) {
        return false;
    }  //跟单链表一样，还是先找到对应的位置
    while (--index) {
        head = head->next;
        if (head == NULL) {
            return false;
        }
    }
    Node node = malloc(sizeof(struct ListNode));  //创建新的结点
    if (node == NULL) {
        return false;
    }
    node->element = element;

    if (head->next) {   //首先处理后继结点，现在有两种情况，一种是后继结点不存在的情况，还有一种是后继结点存在的情况
        head->next->prev = node;   //如果存在则修改对应的两个指针
        node->next = head->next;
    } else {
        node->next = NULL;   //不存在直接将新结点的后继指针置为NULL
    }

    head->next = node;   //接着是前驱结点，直接操作就行
    node->prev = head;
    return true;
}

bool deleteList(Node head,int  index){
    if (index < 1){
        return false;
    }

    while (--index){
        head = head->next;
        if(head == NULL){
            return false;
        }
    }
    if(head->next == NULL){
        return false;
    }

    Node temp = head->next;
    if (head->next->next){
        head->next->next->prev = head;
        head->next = head->next->next;
    } else{
        head->next = NULL;
    }
    free(temp);
    return true;
}

int sizeList (Node head){
    int size = 0;
    while (head != NULL){
        head = head->next;
        size++;
    }
    return size;

}
int main() {
    struct ListNode head;
    initNode(&head);
    for (int i = 0; i < 5; i++) {
        insertList(&head, i * 100, i);
    }
    Node node = &head;
    do {
        node = node->next;
        printf("%d -> ", node->element);
    } while (node->next != NULL);
    printf("\n");
//再来反向遍历一次
    do {
        printf("%d -> ", node->element);
        node = node->prev;
    } while (node->prev != NULL);
    printf("\n");
    printf("sizeList = %d \n", sizeList(&head));

    return 0;
}
