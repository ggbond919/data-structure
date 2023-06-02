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

// stack to queue
typedef struct queue {
    Stack *s1;
    Stack *s2;
    int size;
} Queue;

// 初始化
Stack *CreateStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->pTop = NULL;
    s->size = 0;
    return s;
}

void Push(Stack **pStack, int id) {
    if (pStack == NULL)
        return;
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->value = id;
    node->pNext = NULL;

    node->pNext = (*pStack)->pTop;
    (*pStack)->pTop = node;
    (*pStack)->size++;
}

int Pop(Stack **pStack) {
    if (pStack == NULL || (*pStack)->size == 0)
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

// 队列初始化
Queue *Init() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->s1 = CreateStack();
    q->s2 = CreateStack();
    q->size = 0;
    return q;
}

void q_Push(Queue **q, int id) {
    // s1作为放入 s2作为弹出
    if (q == NULL)
        return;
    if ((*q)->s2->size > 0) {
        while ((*q)->s2->size > 0) {
            Push(&((*q)->s1), Pop(&((*q)->s2)));
        }
    }
    Push(&((*q)->s1), id);
    (*q)->size++;
}

int q_Pop(Queue **q) {
    if (q == NULL || (*q)->size == 0)
        return -1;
    if ((*q)->s1->size > 0) {
        while ((*q)->s1->size > 0) {
            Push(&((*q)->s2), Pop(&((*q)->s1)));
        }
    }
    int value = Pop(&((*q)->s2));
    (*q)->size--;
    return value;
}

// int main() { 
    
//     Queue *q = Init();
//     q_Push(&q,1);
//     q_Push(&q,2);
//     q_Push(&q,3);
//     q_Push(&q,4);

//     printf("%d\n",q_Pop(&q));
//     printf("%d\n",q_Pop(&q));
//     printf("%d\n",q_Pop(&q));
//     printf("%d\n",q_Pop(&q));
//     printf("%d\n",q_Pop(&q));

//     return 0; 
// }