#include "stdio.h"
#include "stdlib.h"

#define N 10
#define MIN -9999
#define MAX 9999

void sort(int *nums);
void show(int *nums);
//  j 插到 j之前的某个位置
void insert(int *nums,int j);

int main()
{
    int nums[N];
    printf("输入10 个需要排序的数\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }

    sort(nums);
    show(nums);
    system("pause");
    return 0;
}
void insert(int *nums, int no_j)
{
    int temp = nums[no_j];

    //  i 及 i之后的后移
    for (int i = 0; i < no_j; i++)
    {
        if (nums[no_j] > nums[i])
        {
            printf("%d插到%d之前\n", nums[no_j], nums[i]);
            for (int k = no_j; k > i; k--)
            {
                nums[k] = nums[k - 1];
            }
            nums[i] = temp;
        }
    }
}

void sort(int *nums)
{

    for (int j = 1; j < N; j++)
    {
        insert(nums,j);
    }
}

void show(int *nums)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}