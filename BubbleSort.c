#include <stdio.h>
#include <stdlib.h>


// 思想：每一次排序，相邻两个元素进行比较，较大者置后，n个元素，每一次筛选出一个最大放在后面，n-1次后任务结束
// 优化：1，每一次冒泡之后，后面已经排好序，只需要比较前面几个数即可，故第二个for循环里面可以j < len - 1 - i即可减少排序次数
// 优化：2，若经过几次之后数组便已经有序了，或者传入的数组本身就是有序的，那么就不需要进入第二个循环，直接跳出程序即可。
// 时间复杂度 ：最好情况，数据有序，0(n);最坏情况，数据逆序，0(n^2)
void BubbleSort(int *arr, int len) {
    if (arr == NULL || len <= 0) {
        return;
    }

    int flag;
    int i;
    int j;

    // len-1次排序即可完成任务
    for (i = 0; i < len - 1; i++) {
        flag = 0;
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)break;
    }
}

// 鸡尾酒/双向冒泡排序算法
void CockTail(int *arr, int len){
    if(arr == NULL || len <= 0)return;

    int left = 0;
    int right = len-1;
    int flag;
    
    while(left < right){
        // 从左向右起泡
        for(int i = left;i < right;i++){
            if(arr[i] > arr[i+1]){
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                flag = i;       // 从左向右起泡时，最后一次交换完成的前一个位置，即最大值之前的那个位置
            }
        }
        right = flag;

        // 从右向左起泡，如果前一个位置比当前位置小则交换
        for(int i = right;i > left;i--){
            if(arr[i] < arr[i-1]){
                int tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                flag = i;  // 从右向左起泡时，最后一次交换完成的后一个位置，即最小值之后的那个位置
            }
        }
        left = flag;

    }

}

void Print(int *arr, int len) {
    if (arr == NULL || len <= 0) {
        return;
    }

    for(int i = 0;i < len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 6, 4, 9, 2};

    // BubbleSort(arr,sizeof(arr)/sizeof(arr[0]));
    CockTail(arr,sizeof(arr)/sizeof(arr[0]));
    Print(arr,sizeof(arr)/sizeof(arr[0]));

    return 0;
}