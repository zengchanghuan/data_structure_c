//
//  linkedList.h
//  dataStructTest
//
//  Created by 曾长欢 on 2022/11/4.
//

#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdbool.h>

typedef int Element;

struct ListNode{
    Element element;
    struct ListNode *next;
};

//别名
typedef struct ListNode *Node;
typedef struct ListNode *LinkList;

void initList(LinkList head);

bool insertList(LinkList head,Element element,int index);

bool deleteList(LinkList head,int index);

Element *getList(LinkList head,int index);

int findList(LinkList head,Element element);

int length(LinkList list);

void printList(LinkList head);

#endif /* linkedList_h */
