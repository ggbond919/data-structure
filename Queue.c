#include <stdio.h>
#include <stdlib.h>

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

// int main() {
//     Queue *q = CreateQueue();
//     Push(&q,1);
//     Push(&q,2);
//     Push(&q,3);
//     Push(&q,4);

//     printf("%d\n",Pop(&q));
//     printf("%d\n",Pop(&q));
//     printf("%d\n",Pop(&q));
//     printf("%d\n",Pop(&q));
//     printf("%d\n",Pop(&q));

//     return 0;
// }