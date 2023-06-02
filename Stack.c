#include <stdio.h>
#include <stdlib.h>

// 元素
typedef struct stacknode {
    int value;
    struct stacknode *pNext;
} StackNode;

// 栈具体结构
typedef struct stack {
    StackNode *pTop;  // 栈顶元素
    int size;         // 栈大小
} Stack;

// 初始化
Stack *CreateStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->pTop = NULL;
    s->size = 0;
    return s;
}

void Push(Stack **pStack,int id) {
    if(pStack == NULL)
        return;
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->value = id;
    node->pNext = NULL;


    node->pNext = (*pStack)->pTop;
    (*pStack)->pTop = node;
    (*pStack)->size++;
}

int Pop(Stack **pStack){
    if(pStack == NULL || (*pStack)->size == 0)
        return -1;

    int value;
    StackNode *pMark = (*pStack)->pTop;
    value = pMark->value;

    (*pStack)->pTop = (*pStack)->pTop->pNext;
    (*pStack)->size--;

    free(pMark);
    pMark = NULL;

    return value;
}

// int main() {
//     Stack *pTop = NULL;
//     pTop = CreateStack();
//     Push(&pTop,1);
//     Push(&pTop,2);
//     Push(&pTop,3);
//     Push(&pTop,4);

//     printf("%d\n",Pop(&pTop));
//     printf("%d\n",Pop(&pTop));
//     printf("%d\n",Pop(&pTop));
//     printf("%d\n",Pop(&pTop));
//     printf("%d\n",Pop(&pTop));

//     return 0;
// }