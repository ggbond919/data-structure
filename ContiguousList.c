#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct table {
    int *base;
    int lenth;
    int size;
} Table;

Table *Init() {
    Table *t = (Table *)malloc(sizeof(Table));
    t->base = (int *)malloc(sizeof(int) * SIZE);
    t->lenth = 0;
    t->size = SIZE;
    return t;
}

void Add(Table **t, int value, int pos) {
    if (pos < 0 || pos > ((*t)->size))
        return;

    // 如果此时表已满，需要申请空间
    if ((*t)->lenth == (*t)->size) {
        (*t)->base = (int *)realloc((*t)->base, sizeof(int) * ((*t)->size + 1));
        if (!(*t)->base) {
            return;
        }
        (*t)->size += 1;
    }

    // pos位置之后的元素整体移动
    int i = (*t)->lenth;
    for (i; i > pos; i--) {
        (*t)->base[i] = (*t)->base[i - 1];
    }
    (*t)->base[i] = value;
    (*t)->lenth++;
}

void Delete(Table **t, int pos) {
    if (pos < 0 || pos > ((*t)->size) - 1)
        return;
    int i = pos;
    for (i; i < (*t)->lenth - 1; i++) {
        (*t)->base[i] = (*t)->base[i + 1];
    }
    (*t)->lenth--;
}

void Modify(Table **t, int value, int pos) {
    if (pos < 0 || pos > ((*t)->size) - 1)
        return;
    (*t)->base[pos] = value;
}

// int main() {
//     Table *t = Init();
//     Add(&t, 1, 0);
//     Add(&t, 2, 1);
//     Add(&t, 3, 2);
//     Add(&t, 4, 3);
//     Add(&t, 5, 4);
//     Add(&t, 6, 5);
//     for (int i = 0; i < t->lenth; i++) {
//         printf("%d\n", t->base[i]);
//     }
//     printf("lenth : %d ,size : %d\n", t->lenth, t->size);

//     Delete(&t, 0);
//     for (int i = 0; i < t->lenth; i++) {
//         printf("%d\n", t->base[i]);
//     }
//     printf("lenth : %d ,size : %d\n", t->lenth, t->size);

//     Delete(&t, 4);
//     for (int i = 0; i < t->lenth; i++) {
//         printf("%d\n", t->base[i]);
//     }
//     printf("lenth : %d ,size : %d\n", t->lenth, t->size);

//     return 0;
// }