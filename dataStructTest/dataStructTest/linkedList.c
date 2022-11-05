//
//  linkedList.c
//  dataStructTest
//
//  Created by 曾长欢 on 2022/11/4.
//

#include "linkedList.h"
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include <string.h>     // 提供 strstr 原型

void initList(LinkList head){

    head->next = NULL;
}

bool insertList(LinkList head,Element element,int index){
    
    if (head == NULL || index < 1) {
        return false;
    }
    
    //先找到插入位置的前驱结点
    while (--index) {
        head = head->next;
        //右边界限制
        if (head == NULL) {
            return false;
        }
    }
    
    Node newNode = malloc(sizeof (struct ListNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->element = element;
    
    //核心代码
    newNode->next = head->next;
    head->next = newNode;
    
    return true;
    
}

bool deleteList(LinkList head,int index){
    if(index < 1) {
        return false;
    }
    
    while (--index) {
        head = head->next;
        if (head == NULL) {
            return false;
        }
    }
    
    //判断右边界
    if (head->next == NULL) {
        return false;
    }
    
    //拿到被删除结点
    Node temp = head->next;
    head->next = head->next->next;
    //释放内存
    free(temp);
    return true;
    
}



Element *getList(LinkList head,int index);

int findList(LinkList head,Element element);

int length(LinkList list);

void printList(LinkList head){
    while (head->next) {
        head = head->next;
        printf("%d ",head->element);
    }
}
