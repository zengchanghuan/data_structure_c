//###不带头结点的单链表
//
//###带头结点的单链表
//
//###带头结点的单循环链表

typedef int ElementType;

typedef struct ListNode{
    ElementType data;
    struct ListNode *next;
    struct ListNode *prev;
}ListNode,*DuLinkNode;

typedef struct {
    DuLinkNode head;
    DuLinkNode  tial;
    int size;
};


