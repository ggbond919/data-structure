#include <stdio.h>
#include <stdlib.h>

// 基本操作 初始化链表，插入（头插入、尾插入，按照节点插入） 删除，遍历打印，
// 单向链表
// 双向链表

typedef struct list {
    char node_value;
    struct list *pNext;

} List;

List *AddNode(char value) {
    List *node = (List *)malloc(sizeof(List));
    node->node_value = value;
    node->pNext = NULL;
    return node;
}

// 单链表创建过程
void CreateList(List **pHead, List **pEnd, List *pNode) {
    if ((*pHead) == NULL) {
        *pHead = pNode;
        *pEnd = pNode;
    } else {
        (*pEnd)->pNext = pNode;
        *pEnd = pNode;
    }
}

// 单链表头删除过程
void PopFront(List **pHead, List **pEnd) {
    // 没有节点
    if (pHead == NULL) {
        printf("there is no node in this list\n");
        return;
    }

    // 一个节点或者多个节点情况
    if ((*pHead) == (*pEnd)) {
        free((*pHead));
        (*pHead) = NULL;
        (*pEnd) = NULL;
    } else {
        List *pDel = (*pHead);
        *pHead = (*pHead)->pNext;
        free(pDel);
        pDel = NULL;
    }
}

// 删除某一个节点
void DeleteNode(List **pHead, List **pEnd, int id) {
    if ((*pHead) == NULL)
        return;
    if ((*pHead)->node_value == id) {
        List *pDel = *pHead;
        (*pHead) = (*pHead)->pNext;
        free(pDel);
        (pDel) = NULL;
        return;
    }

    List *pMark = *pHead;

    // pMark和pHead都指向了同一块空间
    while (pMark->pNext) {
        if (pMark->pNext->node_value == id) {
            List *pDel = pMark->pNext;
            pMark->pNext = pMark->pNext->pNext;
            free(pDel);
            pDel = NULL;
            if (pMark->pNext == NULL) {
                // 说明删除的是尾结点，需要重新更新尾结点的位置
                (*pEnd) = pMark;
            }
            return;
        }

        pMark = pMark->pNext;
    }
}
// 单链表打印过程
void Print(List *pHead) {
    if (pHead == NULL) {
        printf("链表已空\n");
        return;
    }

    while (pHead) {
        printf("%d ", pHead->node_value);
        pHead = pHead->pNext;
    }
    printf("\n");
}

// int main() {
//     List *pHead = NULL;
//     List *pEnd = NULL;
//     CreateList(&pHead, &pEnd, AddNode(1));
//     CreateList(&pHead, &pEnd, AddNode(2));
//     CreateList(&pHead, &pEnd, AddNode(3));
//     // Print(pHead);
//     // PopFront(&pHead,&pEnd);
//     // PopFront(&pHead,&pEnd);
//     // Print(pHead);
//     // PopFront(&pHead,&pEnd);
//     // Print(pHead);
//     // PopFront(&pHead,&pEnd);
//     // CreateList(&pHead,&pEnd,AddNode(4));
//     // Print(pHead);

//     DeleteNode(&pHead, &pEnd, 3);
//     Print(pHead);
//     CreateList(&pHead, &pEnd, AddNode(4));
//     Print(pHead);
//     DeleteNode(&pHead, &pEnd, 1);
//     Print(pHead);
//     return 0;
// }