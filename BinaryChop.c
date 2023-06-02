#include <stdio.h>

int BinaryChop(int *arr, int len, int des_num) {
    if (arr == NULL || len <= 0)
        return -1;

    int mid;
    int low = 0;
    int high = len - 1;

    while (low <= high) {
        // 唯一优化，防止溢出
        mid = low + (high - low) / 2;

        if (arr[mid] == des_num) {
            return mid;
        } else if (arr[mid] > des_num) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// int main() {
//     int arr[] = {1, 6, 9, 44, 66, 99, 821, 1000};
//     printf("Index : %d\n",BinaryChop(arr,sizeof(arr)/sizeof(arr[0]),99));
//     printf("Index : %d\n",BinaryChop(arr,sizeof(arr)/sizeof(arr[0]),3));
//     return 0;
// }