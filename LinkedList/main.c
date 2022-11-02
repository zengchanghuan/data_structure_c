#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Element;
/*
 * 链表分为带头结点的链表和不带头结点的链表.
 * 戴头结点的链表就是会有一个头结点指向后续的整个链表，但是头结点不存放数据
 * 一般设计链表都会采用带头结点的结构，因为操作更加方便。
 *
 * */
struct ListNode {
    Element element;
    struct ListNode *next;
};

typedef struct ListNode *Node;

void initList(Node head) {
    head->next = NULL;
}

void printList(Node head) {
    while (head->next) {
        head = head->next;
        //因为头结点不存放数据，所以从第二个开始打印
        printf("%d ", head->element);
    }
    printf("\n");
}

bool insertList(Node head, Element element, int index) {
    if (index < 1) {
        return false;
    }
    //先找到待插入位置的前驱结点
    while (--index) {
        head = head->next;
        if (head == NULL) {
            return false;
        }
    }

    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) {
        return false;
    }
    node->element = element;
    node->next = head->next;
    head->next = node;
    return true;
}

bool deleteList(Node head, int index) {
    if (index < 1) {
        return false;
    }

    while (--index) {
        head = head->next;
        if (head == NULL) {
            return false;
        }

        if (head->next == NULL) {
            return false;
        }

        Node tmp = head->next;
        head->next = head->next->next;
        free(tmp);
        return true;
    }
}

Element *getList(Node head, int index) {
    if (index < 1) {
        return NULL;
    }

    do {
        head = head->next;
        if (head == NULL) {
            return NULL;
        }
    } while (--index);
    return &head->element;
}

int findList(Node head,Element element){
    head= head->next;
    int i = 1;
    while (head){
        if(head->element == element){
            return i;
        }
        head = head->next;
        i++;
    }
    return -1;
}

int sizeList (Node head){
    int i = 0;
    while (head->next){
        head = head->next;
        i++;
    }
    return i;
}
int main() {
    //这里创建一个新的头结点，头结点不存放任何元素，只做连接，连接整个链表
    struct ListNode head;
    initList(&head);
    printList(&head);

    for (int i = 0; i <= 5; ++i) {
        insertList(&head, i * 100, i);
    }
//    deleteList(&head, 2);
    printList(&head);
    printf("getList = %d",*getList(&head,2));
    printf("\n");

    printf("findList = %d ", findList(&head,300));
    printf("\n");

    printf("sizeList = %d", sizeList(&head));



    printf("\n");


    return 0;
}
