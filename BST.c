#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int value;
    struct Tree *pLeft;
    struct Tree *pRight;
} BinaryTree;

// 中序遍历
void InorderPrint(BinaryTree *pTree) {
    if (pTree == NULL)
        return;
    InorderPrint(pTree->pLeft);
    printf("%d ", pTree->value);
    InorderPrint(pTree->pRight);
}

// AddNode
void AddNode(BinaryTree **pRoot, int value) {
    BinaryTree *pNode = (BinaryTree *)malloc(sizeof(BinaryTree));
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    pNode->value = value;

    if (*pRoot == NULL) {
        *pRoot = (BinaryTree *)malloc(sizeof(BinaryTree));
        (*pRoot)->pLeft = NULL;
        (*pRoot)->pRight = NULL;
        (*pRoot)->value = value;
        return;
    } else {
        BinaryTree *pMark = (*pRoot);
        while (pMark) {
            if (pMark->value > value) {
                if (pMark->pLeft == NULL) {
                    pMark->pLeft = pNode;
                    return;
                }
                pMark = pMark->pLeft;
            } else if (pMark->value < value) {
                if (pMark->pRight == NULL) {
                    pMark->pRight = pNode;
                    return;
                }
                pMark = pMark->pRight;
            } else {
                return;
            }
        }
    }
}

// Search
void Search(BinaryTree *pTree, BinaryTree **pDel, BinaryTree **pFather,
            int num) {
    while (pTree) {
        if (pTree->value == num) {
            *pDel = pTree;
            return;
        }
        if (pTree->value > num) {
            *pFather = pTree;
            pTree = pTree->pLeft;
        } else if (pTree->value < num) {
            *pFather = pTree;
            pTree = pTree->pRight;
        }
    }

    // 没找到目标节点,标记的父节点需要赋空
    *pFather = NULL;
}

// Delete Node
void DeleteNode(BinaryTree **pTree, int num) {
    if (pTree == NULL)
        return;
    BinaryTree *pDel = NULL;
    BinaryTree *pFather = NULL;
    Search(*pTree, &pDel, &pFather, num);

    // 节点异常情况
    if (pDel == NULL)
        return;

    // 两个节点的情况
    if (pDel->pLeft != NULL && pDel->pRight != NULL) {
        // 标记一下要删除的位置，只需将左的最右重新赋值给pMark，删除左的最右叶节点即可
        BinaryTree *pMark = pDel;

        pFather = pDel;
        pDel = pDel->pLeft;

        // 更新要删除的节点与其父节点
        while (pDel->pRight) {
            pFather = pDel;
            pDel = pDel->pRight;
        }

        // 将标记位置赋值即可
        pMark->value = pDel->value;
    }

    // 0或者1个节点
    // 如果pFather为空，说明删除的是根节点
    if (pFather == NULL) {
        *pTree = pDel->pLeft ? pDel->pLeft : pDel->pRight;
        free(pDel);
        pDel = NULL;
        return;
    }

    if (pDel->pLeft != NULL && pDel->pRight == NULL) {
        if (pFather->pLeft == pDel) {
            pFather->pLeft = pDel->pLeft;
        } else {
            pFather->pRight = pDel->pLeft;
        }
    } else if (pDel->pLeft == NULL && pDel->pRight != NULL) {
        if (pFather->pLeft == pDel) {
            pFather->pLeft = pDel->pRight;
        } else {
            pFather->pRight = pDel->pRight;
        }
    } else if (pDel->pLeft == NULL && pDel->pRight == NULL) {
        if (pFather->pLeft == pDel) {
            pFather->pLeft = NULL;
        } else {
            pFather->pRight = NULL;
        }
    }
    free(pDel);
    pDel = NULL;
}

// Create BST Tree
BinaryTree *CreateTree(int *arr, int len) {
    BinaryTree *pRoot = NULL;
    for (int i = 0; i < len; i++) {
        AddNode(&pRoot, arr[i]);
    }

    return pRoot;
}

// int main() {
//     int arr[] = {1, 8, 3, 6, 88, 9, 44};
//     BinaryTree *pTree = CreateTree(arr, 7);
//     InorderPrint(pTree);
//     printf("\n");

//     DeleteNode(&pTree, 88);
//     InorderPrint(pTree);
//     return 0;
// }