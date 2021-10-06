#include "stdio.h"
#include "stdlib.h"

#define N 10
#define MIN -9999
#define MAX 9999

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

    sort(nums);
    show(nums);
    system("pause");
    return 0;
}
void sort(int *nums)
{
    int max = MIN;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i; j < N; j++)
        {
            if(nums[j] > max){
                max ^= nums[j];
                nums[j] ^= max;
                max ^= nums[j];
            }
        }
        max ^= nums[i];
        nums[i] ^= max;
        max ^= nums[i];
        show(nums);
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