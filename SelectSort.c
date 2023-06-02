#include <stdio.h>

// 选择排序：简单选择和堆排序
// 简单选择是对冒泡排序的一种优化排序，但是时间复杂度依旧是0(n^2),只不过交换次数减少了，性能优于冒泡排序
// 堆排序是对简单选择排序的一种优化

void SelectSort(int *arr,int len){
    if(arr == NULL || len <= 0)return;

    // 存放每一趟比较之后，值最小的数组下标，最后放在数组的最前面
    int min_index;
    
    // 总共进行n-1趟的操作就可以完成数组的排序
    for(int i = 0;i < len - 1;i++){
        min_index = i;

        for(int j = i + 1;j < len;j++){
            if(arr[min_index] > arr[j]){
                // 及时更新最小值的数组下标
                min_index = j;
            }
        }

        // 一趟比较结束之后，根据获取到的最小值下标和前面的元素进行交换,此举会造成排序的不稳定
        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
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

// int main(){

//     int arr[] = {8, 6, 4, 9, 2};
//     SelectSort(arr,sizeof(arr)/sizeof(arr[0]));
//     Print(arr,sizeof(arr)/sizeof(arr[0]));

//     return 0;
// }