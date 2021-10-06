#include "stdio.h"
#include "stdlib.h"

#define N 10

void sort(int *nums);
void show(int *nums);
void merge(int *arr1, int len1, int *arr2, int len2);

int main()
{
    // int nums[N];
    // printf("输入10个需要排序的数\n");
    // for (int i = 0; i < N; i++)
    // {
    //     scanf("%d", &nums[i]);
    // }

    // sort(nums);
    // show(nums);
    int arr1[5] = {1, 3, 4, 5, 10};
    int arr2[5] = {2, 4, 6, 8, 12};
    merge(arr1, 5, arr2, 5);

    system("pause");
    return 0;
}

void merge(int *arr1, int len1, int *arr2, int len2)
{
    int total[N];
    int i = 0;
    int j = 0; //指向 arr2
    while (i < len1 && j < len2)
    {
        if (arr2[j] < arr1[i])
        {
            total[i + j] = arr2[j];
            printf("%d < %d\t total[%d] = %d\n", arr2[j], arr1[i], i + j, total[i + j]);
            j++;
        }
        else
        {
            total[i + j] = arr1[i];
            printf("%d <= %d\t total[%d] = %d\n", arr1[i], arr2[j], i + j, total[i + j]);
            i++;
        }
    }
    printf("i=%d, j=%d\n", i, j);
    while (i < len1)
    {
        total[i + j] = arr1[i];
        i++;
    }
    while (j < len2)
    {
        total[i + j] = arr2[j];
        j++;
    }
    show(total);
}

void show(int *nums)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}