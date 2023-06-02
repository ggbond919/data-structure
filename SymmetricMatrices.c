#include <stdio.h>
#include <stdlib.h>

// 对称矩阵压缩存储方式：行优先
// 1.所需空间大小：1+2+...+n = Sn = n/2 * (A1 + An);
// 2.如何计算获取矩阵当中对应的a[i][j],两种情况讨论
// 如果i >= j：统计前i-1行元素个数，再加上j个元素，即为所得下标(i - 1.0)/2 * i + j - 1；i <= j 交换字母即可
// 因为一维数组下标从0开始，所以需要减去1

// 对称矩阵压缩存储方式：列优先
// 1.所需空间大小：1+2+...+n = Sn = n/2 * (A1 + An);
// 2.如何计算获取矩阵当中对应的a[i][j],两种情况讨论
// (a):如果i >= j：第一列元素个数:n,第二列:n-1,第n-j列：n-j+2,计算出前n-j列元素总个数
// (b)此时并未结束，还需要计算本列要取的a[i][j]前面还有多少个元素，只需要用i-j即可得到 (a) + (b) - 1
// (a) + (b) - 1 即为一维数组中索引
// 因为一维数组下标从0开始，所以需要减去1

// 下三角矩阵压缩存储方式：行优先
// 1.所需空间大小：1+2+...+n = Sn = n/2 * (A1 + An) + 1；（因为上三角矩阵的所有常数 C 需要占一个空间，所以+1）
// 2.如何计算获取矩阵当中对应的a[i][j],两种情况讨论
// (a)如果i >= j：统计前i-i行元素个数，再加上j个元素，即为所得下标(i - 1.0)/2 * i + j - 1；
// (b)如果i < j: 直接读取一维数组最后一个元素即为常数C

// 上三角矩阵压缩存储方式：行优先
// 1.所需空间大小：1+2+...+n = Sn = n/2 * (A1 + An) + 1；（因为上三角矩阵的所有常数 C 需要占一个空间，所以+1）
// 2.如何计算获取矩阵当中对应的a[i][j],两种情况讨论
// 如果i <= j：
// (a) 统计前n-i行元素个数，第一行元素个数:n,第二行:n-1,第a-1行：n-a+2,计算出前a-1行元素总个数
// (b)此时并未结束，还需要计算本行要取的a[i][j]前面还有多少个元素，只需要用j-i即可得到 (a) + (b) - 1
// 如果i > j: 直接读取一维数组最后一个元素即为常数C

// 三对角矩阵：行优先
// 所需空间：3*n-2
// 访问a[i][j]在一维数组的映射关系，3(i-1)-1 + (j - i + 2) - 1,其中(j - i + 2)表示a[i][j]是第i行的第几个元素，这是区别于上述几个特殊矩阵的地方
// 假如给的B[k],让求解对应a[i][j]在第几行，第几列，
// 明确k+1是一维数组中第k个元素（数组下标从0开始的所以加1）3*(i-1)-1 < k+1 <= 3*i - 1(一定大于上一行之前的，小于等于本行之前的元素个数) 
// 求出行号i后，根据2*i+j-3 = k,再求出j。

// 稀疏矩阵：三元组存储方式
// 存储 i，j, value
typedef struct BareMatrix{
    int i; // 行
    int j; // 列
    int value; // 值
}Matrix;

// 获取一维数组空间大小
int GetLenth(int row){
    if (row < 0)
    {
        return -1;
    }
    
    // 采用行优先存储方式，存储矩阵下三角即可，即row >= col
    // 第一行1个，第二行2个，第三行3个...第n行n个
    // 等差数列前n项和 Sn = n/2 * (A1 + An);
    int len = row / 2 * (1 + row);
    return len;
}

// 将对称矩阵元素下三角元素放入一维数组当中，int (*matrix)[4]二维数组需要这样传参，4对应列数
void Compress(int (*matrix)[4],int *arr,int len,int row){
    if(matrix == NULL || arr == NULL || len < 0){
        return ;
    }
    int i = 1;
    int j = 0;
    int count;
    while(i <= row){
        for(j,count = 1;count <= i;j++,count++){
            (arr)[j] = matrix[i-1][count-1];
        }
        i++;
    }
}

// 此处需要用float类型计算下标，
int GetElement(int *arr,float i,float j){
    if(arr == NULL)
        return -1;

    // 将对称矩阵对应的二维数组下标转换为一维数组下标
    if(i >= j){
        // 下三角元素
        int index = (i - 1.0)/2 * i + j - 1;
        int value = arr[index];
        return value;
    } else {
        int index = (j - 1.0)/2 * j + i - 1;
        int value = arr[index];
        return value;
    }

}

// int main()
// {
//     // int **matrix = (int **)malloc(sizeof(int *)*4);
//     // matrix[]还要继续神情才可以
//     int matrix[4][4] = 
//     {
//         {2,8,0,3},
//         {8,0,4,6},
//         {0,4,1,2},
//         {3,6,2,1},
//     };
//     int *arr = (int *)malloc(sizeof(int) * GetLenth(4));
    
//     Compress(matrix,arr,GetLenth(4),4);
//     printf("%d\n",GetElement(arr,3,2));
//     printf("%d\n",GetElement(arr,2,3));

//     printf("%d\n",GetElement(arr,1,4));
//     printf("%d\n",GetElement(arr,4,1));


//     Matrix * bare_arr= (Matrix *)malloc(sizeof(Matrix)*20);
//     bare_arr[1].i = 1;
//     bare_arr[1].j = 1;
//     bare_arr[1].value = 1;

//     return 0;
// }