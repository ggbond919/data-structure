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

typedef struct stack {
    int size;
    Queue *q1;
    Queue *q2;
} Stack;

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
    if ((*q)->size == 0) {
        (*q)->pEnd = NULL;
    }
    return value;
}

Stack *Init() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->q1 = CreateQueue();
    s->q2 = CreateQueue();
    s->size = 0;
    return s;
}

void s_Push(Stack **s, int id) {
    if (s == NULL)
        return;
    Push(&((*s)->q1), id);
    (*s)->size++;
}

int s_Pop(Stack **s) {
    if (s == NULL || (*s)->size == 0)
        return -1;
    int value;
    if ((*s)->q1->size == 1) {
        value = Pop(&(*s)->q1);
        (*s)->size--;
        return value;
    }

    if ((*s)->q1->size > 1) {
        while ((*s)->q1->size > 1) {
            Push(&(*s)->q2, Pop(&(*s)->q1));
        }
        value = Pop(&(*s)->q1);
        while ((*s)->q2->size > 0) {
            Push(&(*s)->q1, Pop(&(*s)->q2));
        }
        (*s)->size--;
        return value;
    }
}

// int main() { 

//     Stack *s = Init();
//     s_Push(&s,1);
//     s_Push(&s,2);
//     s_Push(&s,3);
//     s_Push(&s,4);

//     printf("%d\n",s_Pop(&s));
//     printf("%d\n",s_Pop(&s));
//     printf("%d\n",s_Pop(&s));
//     printf("%d\n",s_Pop(&s));
//     printf("%d\n",s_Pop(&s));

//     return 0; 
// }