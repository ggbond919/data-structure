#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

// 顺序存储结构
typedef struct queue {
    int *base;
    int front;
    int rear;
} CircularQueue;

CircularQueue *Init() {
    CircularQueue *q = (CircularQueue *)malloc(sizeof(CircularQueue));
    q->base = (int *)malloc(sizeof(int) * MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

// 循环队列最后一个空间不放东西，作为标志位，来判断队列已满 这一点和队列已空 作为区分
void cq_Push(CircularQueue **q, int num) {
    if (q == NULL)
        return;

    // the situation in which the queue has been filled with elements
    if (((*q)->rear + 1) % MAXSIZE == (*q)->front) {
        return;
    }

    // the other situation
    (*q)->base[(*q)->rear] = num;
    (*q)->rear = ((*q)->rear + 1) % MAXSIZE;
}

int cq_Pop(CircularQueue **q) {
    if (q == NULL)
        return -1;

    // 队列本身是空的
    if ((*q)->front == (*q)->rear) {
        return -1;
    }

    int num = (*q)->base[(*q)->front];
    (*q)->front = ((*q)->front + 1) % MAXSIZE;
    return num;
}

// int main() {
//     CircularQueue *q = Init();
//     cq_Push(&q, 1);
//     cq_Push(&q, 2);
//     cq_Push(&q, 3);
//     cq_Push(&q, 4);
//     cq_Push(&q, 5);
//     printf("%d\n", ((q->rear) - (q->front) + MAXSIZE) % MAXSIZE);

//     printf("%d\n", cq_Pop(&q));
//     printf("%d\n", cq_Pop(&q));
//     printf("%d\n", cq_Pop(&q));
//     printf("%d\n", cq_Pop(&q));
//     printf("%d\n", cq_Pop(&q));
//     printf("%d\n", (q->rear - q->front + MAXSIZE) % MAXSIZE);

//     cq_Push(&q, 1);
//     cq_Push(&q, 2);
//     cq_Push(&q, 3);
//     printf("%d\n", (q->rear - q->front + MAXSIZE) % MAXSIZE);

//     printf("%d\n", cq_Pop(&q));
//     printf("%d\n", cq_Pop(&q));
//     printf("%d\n", cq_Pop(&q));
//     printf("%d\n", (q->rear - q->front + MAXSIZE) % MAXSIZE);

//     return 0;
// }