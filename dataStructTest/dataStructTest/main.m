//
//  main.m
//  dataStructTest
//
//  Created by 曾长欢 on 2022/11/3.
//

#import <Foundation/Foundation.h>
#import "linkedList.h"


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        
        struct ListNode head;
        initList(&head);
        
        
        for (int i = 1; i <= 5; i++) {
            insertList(&head, i * 100, i);
        }
        printList(&head);
        printf("\n");
        deleteList(&head, 3);   //这里我们尝试删除一下第一个元素
        printList(&head);
        
    }
    return 0;
}
