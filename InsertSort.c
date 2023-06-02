#include <stdio.h>
//#include <algorithm>
// 插入排序:平均和最差时间复杂度为o(n^2),最好的情况是数据有序O(N)，最坏的情况是数据逆序
// 折半插入排序,对直接插入排序的优化，时间复杂度为O(NlogN)

void InsertSort(int *arr, int len) {
    if (arr == NULL || len <= 0)
        return;

    // 将数组分为有序和无序两个部分
    int i;     // 无序
    int j;     // 有序
    int temp;  // 标记要交换的元素

    // for循环一次结束，有序部分增加，无序部分减少
    for (i = 1; i < len; i++) {
        j = i - 1;      // 有序最后一个元素位置
        temp = arr[i];  // 无序第一个元素

        // 先将无序前面较大的元素后移,直至找到合适位置
        while (temp < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        //
        arr[j + 1] = temp;
    }
}

// 插入排序的改进，折半插入排序|二分插入排序,
void BinaryInsertSort(int *arr, int len) {
    if (arr == NULL || len <= 0)
        return;

    int left, right, mid, i, j, tmp;
    for (i = 1; i < len; i++) {
        tmp = arr[i];
        j = i - 1;

        left = 0;
        right = i - 1;

        // 利用无序的元素，在有序部分中进行二分查找，直至找到合适位置，减少比较的次数
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] > tmp) {
                right = mid - 1;
            } else if (arr[mid] < tmp) {
                left = mid + 1;
            }
        }

        // 从left位置开始，将元素后移
        while (j >= left) {
            arr[j + 1] = arr[j];
            j--;
        }

        // 最后放置在left位置上
        arr[left] = tmp;
    }
}

void Print(int *arr, int len) {
    if (arr == NULL || len <= 0) {
        return;
    }

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 6, 4, 9, 2};
    // InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
    BinaryInsertSort(arr, sizeof(arr) / sizeof(arr[0]));
    Print(arr, sizeof(arr) / sizeof(arr[0]));
    
    return 0;
}