#include <stdio.h>
#include <stdlib.h>



// int main()
// {

//     // 一定要注意地址是十六进制，逢16进1
//     int array[6] = {0,1,2,3,4,5};
//     printf("%p\n",array);           // 0x7fffffffe020
//     printf("%p\n",&array);          // 0x7fffffffe020
//     printf("%p\n",&(array[0]));     // 0x7fffffffe020
//     printf("%p\n",&(array[1]));     // 0x7fffffffe024
//     printf("%p\n",&(array[2]));     // 0x7fffffffe028
//     printf("%p\n",&(array[3]));     // 0x7fffffffe02c
//     printf("%p\n",&(array[4]));     // 0x7fffffffe030
//     printf("%p\n",&(array[5]));     // 0x7fffffffe034

//     printf("%p\n",array + 1);       // 0x7fffffffe024
//     printf("%p\n",(&array) + 1);    // 0x7fffffffe038
//     printf("%p\n",array + 4);       // 0x7fffffffe030
//     printf("%p\n",&(array[1]));     // 0x7fffffffe024

//     return 0;
// }