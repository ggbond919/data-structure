#include <stdio.h>
#include <stdlib.h>

// 双向链表
typedef struct List {
    int value;
    struct List *prior;
    struct List *next;
} LinkList;

// 初始化节点
LinkList *AddNode(int value) {
    LinkList *Node = (LinkList *)malloc(sizeof(LinkList));
    Node->next = NULL;
    Node->prior = NULL;
    Node->value = value;
    return Node;
}
// 创建双向链表
void CreateLinkList(LinkList **pHead, LinkList **pEnd, LinkList *Node) {
    if (*pHead == NULL) {
        *pHead = Node;
        *pEnd = Node;
    } else {
        (*pEnd)->next = Node;
        Node->prior = (*pEnd);
        (*pEnd) = Node;
    }
}

// 删除节点
void DeleteNode(LinkList **pHead, LinkList **pEnd, int id) {
    if (*pHead == NULL)
        return;

    // 如果是头结点
    if ((*pHead)->value == id) {
        LinkList *pDel = *pHead;
        (*pHead) = (*pHead)->next;
        (*pHead)->prior = NULL;
        free(pDel);
        pDel = NULL;
        return;
    }

    // 标记头结点
    LinkList *pMark = *pHead;
    while (pMark->next) {
        if (pMark->next->value == id) {
            LinkList *pDel = pMark->next;

            // 如果是尾结点
            if (pMark->next->next == NULL) {
                free(pDel);
                pDel = NULL;
                (*pEnd) = pMark;

                // 标记节点的下一个虽然删除，但是标记节点仍然指向那片被释放的空间，所以需要重置
                pMark->next = NULL;
                return;
            }
            pMark->next->next->prior = pMark;
            pMark->next = pMark->next->next;

            free(pDel);
            pDel = NULL;

            return;
        }

        pMark = pMark->next;
    }
}

// 打印，从前向后，从后向前
void PrintLinkList(LinkList *pHead, LinkList *pEnd) {
    if (pHead == NULL)
        return;
    if (pEnd == NULL)
        return;

    // 从前向后打印
    while (pHead) {
        printf("%d ", pHead->value);
        pHead = pHead->next;
    }
    printf("\n");
    // 从后向前打印
    while (pEnd) {
        printf("%d ", pEnd->value);
        pEnd = pEnd->prior;
    }
    printf("\n");
}

// int main() {
//     LinkList *pHead = NULL;
//     LinkList *pEnd = NULL;

//     CreateLinkList(&pHead, &pEnd, AddNode(1));
//     CreateLinkList(&pHead, &pEnd, AddNode(2));
//     CreateLinkList(&pHead, &pEnd, AddNode(3));
//     CreateLinkList(&pHead, &pEnd, AddNode(4));
//     PrintLinkList(pHead, pEnd);
//     DeleteNode(&pHead, &pEnd, 1);   // 删除头
//     PrintLinkList(pHead, pEnd);
//     DeleteNode(&pHead, &pEnd, 3);   // 删除中间节点
//     PrintLinkList(pHead, pEnd);
//     CreateLinkList(&pHead, &pEnd, AddNode(5));  // 新增节点
//     PrintLinkList(pHead, pEnd);
//     DeleteNode(&pHead, &pEnd, 5);               // 删除尾结点
//     PrintLinkList(pHead, pEnd);

//     return 0;
// }