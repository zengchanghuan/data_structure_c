#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

struct List {
    Element *array;
    int capacity;
    int size;
};

typedef struct List *ArrayList;

bool initList(ArrayList list) {
    list->capacity = 10;
    list->array = malloc(sizeof(Element) * 10);
    if (list->array == NULL) {
        return false;
    }
    list->size = 0;
    return true;
}

bool insertList(ArrayList list, Element element, int index) {
    if (index < 1 || index > list->size + 1) {
        return false;
    }

    if (list->size == list->capacity) {
        int newCapacity = list->capacity + (list->capacity >> 1);
        Element *newArray = realloc(list->array, sizeof(Element) * newCapacity);
        if (newCapacity == NULL) {
            return false;
        }
        list->array = newArray;
        list->capacity = newCapacity;
    }


    for (int i = list->size; i > index - 1; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;
    list->size++;
    return true;
}

bool deleteList(ArrayList list, int index) {
    if (index < 1 || index > list->size) {
        return false;
    }
    for (int i = index - 1; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return true;
}

void printList(ArrayList list) {

    for (int i = 0; i < list->size; ++i) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

int sizeList(ArrayList list) {
    return list->size;
}

Element * getList(ArrayList list, int index) {
    if (index < 1 || index > list->size) {
        return NULL;
    }
    return &list->array[index - 1];
}

int findList(ArrayList list,Element element){
    for (int i = 0; i < list->size; i++){
        if(list->array[i] == element){
            return i + 1;
        }
    }
    return -1;
}

int main() {

    struct List list;
    if (initList(&list)) {
        for (int i = 0; i < 10; ++i) {
            insertList(&list, i, i);
        }
//        deleteList(&list, 5);   //这里删除5号元素
//
        printList(&list);

        findList(&list,8);
        printf("findList %d",findList(&list,80));
        printf("findList %d",findList(&list,8));

        printf("\n");
        printf("getList %d", *getList(&list,4));
        printf("\n");
        printf("sizeList %d", sizeList(&list));

    } else {
        printf("顺序表初始化失败，无法启动程序！");
    }
    return 0;
}
