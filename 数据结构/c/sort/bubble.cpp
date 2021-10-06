#include "stdio.h"
#include "stdlib.h"

#define N 10

void sort(int *nums);
void show(int *nums);

int main()
{
    int nums[N];
    printf("输入10 个需要排序的数\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }
    show(nums);
    sort(nums);
    show(nums);
    return 0;
}

void sort(int *nums)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if(nums[i] > nums[j]){
                nums[i] = nums[i] ^ nums[j];
                nums[j] ^= nums[i];
                nums[i] ^= nums[j];
            }
        }
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