#include <stdio.h>
#include <stdlib.h>

// 普通二叉树
// 满二叉树：每一层都是满的
// 完全二叉树：最后一层连续空缺，且从右向左连续空缺
// 二叉排序树：树中每个节点左子树值永远比该节点值小，右子树值比该节点值大，树中每个值都是唯一不可重复的。BST
// 平衡二叉树：前提是一颗BST，且每个节点左右子树高度差不超过1
// 性质1 二叉树，k层总结点数：2^k - 1;性质2，第k层叶子结点最多2^(k-1);
// 性质3 任意一颗二叉树都满足 N0 = N2 + 1
// 性质4 有n个节点的完全二叉树，它有多少层？ K = log2(N) 向下取整 + 1
// 性质5 有n个节点的完全二叉树，从上到下，从左到右，从1开始依次编号，
// 如果某个节点i，2*i <= n 说明该节点有左孩子，且编号2*i，如果 2*i + 1 <= n
// 说明该节点有右孩子,且编号为2*i+1 父亲节点的编号范围是1 ~ n/2

// 深度优先遍历，广度优先遍历
// 深度优先遍历 前序(根左右)  中序(左根右) 后序(左右根)

typedef struct Tree {
    int value;
    struct Tree *pLeft;
    struct Tree *pRight;
} BinaryTree;

typedef struct node {
    int value;
    struct node *pNext;
} Node;

typedef struct queue {
    int size;
    Node *pHead;
    Node *pEnd;
} Queue;

Queue *CreateQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->pHead = NULL;
    q->pEnd = NULL;
    q->size = 0;
    return q;
}

void Push(Queue **q, int id) {
    if (q == NULL)
        return;
    Node *element = (Node *)malloc(sizeof(Node));
    element->pNext = NULL;
    element->value = id;

    if ((*q)->size == 0) {
        (*q)->pHead = element;
        (*q)->pEnd = element;
    } else {
        (*q)->pEnd->pNext = element;
        (*q)->pEnd = element;
    }
    (*q)->size++;
}

int Pop(Queue **q) {
    if (q == NULL || (*q)->pHead == NULL)
        return -1;
    int value = (*q)->pHead->value;
    Node *pMark = (*q)->pHead;
    (*q)->pHead = (*q)->pHead->pNext;
    free(pMark);
    pMark = NULL;
    (*q)->size--;
    if((*q)->size == 0){
        (*q)->pEnd = NULL;
    }
    return value;
}

BinaryTree *CreateTree() {
    BinaryTree *pRoot = NULL;
    pRoot = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->value = 5;
    pRoot->pLeft = NULL;
    pRoot->pRight = NULL;

    // 左
    pRoot->pLeft = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pLeft->value = 3;
    pRoot->pLeft->pLeft = NULL;
    pRoot->pLeft->pRight = NULL;

    // 左的左
    pRoot->pLeft->pLeft = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pLeft->pLeft->value = 1;
    pRoot->pLeft->pLeft->pLeft = NULL;
    pRoot->pLeft->pLeft->pRight = NULL;

    // 左的右
    pRoot->pLeft->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pLeft->pRight->value = 2;
    pRoot->pLeft->pRight->pLeft = NULL;
    pRoot->pLeft->pRight->pRight = NULL;

    // 右
    pRoot->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pRight->value = 7;
    pRoot->pRight->pLeft = NULL;
    pRoot->pRight->pRight = NULL;

    // 右的左
    pRoot->pRight->pLeft = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pRight->pLeft->value = 6;
    pRoot->pRight->pLeft->pLeft = NULL;
    pRoot->pRight->pLeft->pRight = NULL;

    // 右的右
    pRoot->pRight->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pRight->pRight->value = 8;
    pRoot->pRight->pRight->pLeft = NULL;
    pRoot->pRight->pRight->pRight = NULL;

    return pRoot;
}

// 前序遍历
void PreorderPrint(BinaryTree *pTree) {
    if (pTree == NULL)
        return;

    printf("%d ", pTree->value);
    PreorderPrint(pTree->pLeft);
    PreorderPrint(pTree->pRight);
}

// 中序遍历
void InorderPrint(BinaryTree *pTree) {
    if (pTree == NULL)
        return;
    InorderPrint(pTree->pLeft);
    printf("%d ", pTree->value);
    InorderPrint(pTree->pRight);
}

// 后序遍历
void LastorderPrint(BinaryTree *pTree) {
    if (pTree == NULL)
        return;
    LastorderPrint(pTree->pLeft);
    LastorderPrint(pTree->pRight);
    printf("%d ", pTree->value);
}

// 层序遍历

// 输入数字创建树
void CreateBinaryTree(BinaryTree **pTree) {
    int value;
    scanf("%d", &value);
    if (value == 0) {
        return;
    }
    *pTree = (BinaryTree *)malloc(sizeof(BinaryTree));
    (*pTree)->value = value;
    (*pTree)->pLeft = NULL;
    (*pTree)->pRight = NULL;

    CreateBinaryTree((&(*pTree)->pLeft));
    CreateBinaryTree(&((*pTree)->pRight));
}

// 输入数组创建树
BinaryTree **CreateBinaryTree1(int arr[], int len) {
    BinaryTree **arr_tree = (BinaryTree **)malloc(sizeof(BinaryTree *) * len);
    for (int i = 0; i < len; i++) {
        arr_tree[i] = (BinaryTree *)malloc(sizeof(BinaryTree));
        arr_tree[i]->pLeft = NULL;
        arr_tree[i]->pRight = NULL;
        arr_tree[i]->value = arr[i];
    }

    for (int i = 0; i < len; i++) {
        if (2 * i + 1 <= len - 1) {
            arr_tree[i]->pLeft = (arr_tree[2 * i + 1]);
        }
        if(2 * i + 2 <= len - 1){
            arr_tree[i]->pRight = (arr_tree[2 * i + 2]);
        }
    }

    return arr_tree;
}

// int main() {
//     // BinaryTree *pTree = CreateTree();
//     // PreorderPrint(pTree);
//     // printf("\n");

//     // InorderPrint(pTree);
//     // printf("\n");

//     // LastorderPrint(pTree);
//     // printf("\n");

//     BinaryTree *pTree = NULL;
//     // CreateBinaryTree(&pTree);
//     // PreorderPrint(pTree);
//     int arr[] = {5,3,7,1,2,6,8};
//     BinaryTree **pTree1 = CreateBinaryTree1(arr,7);
//     PreorderPrint(pTree1[0]);



//     return 0;
// }