#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// Hash表结构
typedef struct hash{
    int value;          // 数组值
    int index;          // 数组下标
    struct hash *pNext;
}Hash;

Hash **CreateHashTable(int *arr,int len){
    if(arr == NULL || len <= 0)return NULL;

    // 指针数组
    Hash **table = (Hash **)malloc(sizeof(Hash*) * len);
    // 头添加时保证最后一个元素的pNext为空
    memset(table,0,sizeof(Hash*)*len);

    for(int i = 0;i < len;i++){
        int index = arr[i] % len;   // 要放入的位置
        Hash *temp = (Hash *)malloc(sizeof(Hash));
        temp->value = arr[i];
        temp->index = i;

        // 头添加
        temp->pNext = table[index];
        table[index] = temp;
    }

    return table;
}

int HashSearch(Hash **table,int arr_len,int des_num){
    if(table == NULL)return -2;
    int index = des_num % arr_len;

    Hash *temp = table[index];

    // 遍历链表查找
    while(temp){
        if(temp->value == des_num){
            return temp->index;
        }
        temp = temp->pNext;
    }

    // 循环结束表示未查找到
    return -1;
}

// int main(){

//     int arr[] = {1,5,6,7,9,42,55,66,99,112,335,888};
//     Hash **t = CreateHashTable(arr,sizeof(arr)/sizeof(arr[0]));
//     printf("Index : %d\n",HashSearch(t,sizeof(arr)/sizeof(arr[0]),99));
//     printf("Index : %d\n",HashSearch(t,sizeof(arr)/sizeof(arr[0]),999));

//     return 0;
// }